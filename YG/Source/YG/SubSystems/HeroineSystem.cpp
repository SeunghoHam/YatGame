// Fill out your copyright notice in the Description page of Project Settings.


#include "SubSystems/HeroineSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "YG/SubSystems/Save/HeroineSaveGame.h"

static constexpr int32 kCurrentSaveVersion = 1; // SaveVersion 에서 사용
void UHeroineSystem::InitFromData(const TArray<UGirlsData*>& Datas)
{
	for (auto* D : Datas)
	{
		if (!D) continue;

		for (const TPair<FName, FHeroineStatic>& Pair : D->HeroineDatas)
		{
			const FName Id = Pair.Key;
			const FHeroineStatic& heroine_static = Pair.Value;

			FHeroineRuntime& R = Runtime.FindOrAdd(Id);
			R.HeroineId = heroine_static.HeroineId;
			R.HeroineDisplayName = heroine_static.DisplayName;
			R.HeroineTexture = heroine_static.HeroineTexture;

			
			// 이미 로드 과정에서 채워졌으면 덮어쓰기 X
			if (R.Stats.Num() ==0)
			{
				R.Stats = heroine_static.DefaultStats;
			}
			// 기본 플래그도 없을때만 채움
			if (R.Flags.Num() == 0 && heroine_static.DefaultFlags.Num()> 0)
			{
				R.Flags = heroine_static.DefaultFlags;
			}
		}
	}
}

int32 UHeroineSystem::AddStat(FName HeroineId, FName Stat, int32 Delta)
{
	// 스탯 변경시키기
	FHeroineRuntime& R = Runtime.FindOrAdd(HeroineId);
	int32& Val = R.Stats.FindOrAdd(Stat);
	Val += Delta;
	OnStatChanged.Broadcast(HeroineId, Stat);
	return Val;
}

bool UHeroineSystem::Save(const FString& Slot, int32 UserIdx)
{
	UHeroineSaveGame* SaveObj = NewObject<UHeroineSaveGame>();
	SaveObj->SaveVersion = kCurrentSaveVersion;

	SaveObj->Entries.Reserve(Runtime.Num());

	for (const TPair<FName, FHeroineRuntime>& Pair : Runtime)
	{
		const FHeroineRuntime& R = Pair.Value;

		FHeroineSaveEntry E;
		E.HeroineId = R.HeroineId;
		E.Stats     = R.Stats;
		
		// TSet -> Array
		E.Flags.Reserve(R.Flags.Num());
		for (const FName& Flag : R.Flags)
			E.Flags.Add(Flag);

		SaveObj->Entries.Add(MoveTemp(E));
	}

	const bool bOK = UGameplayStatics::SaveGameToSlot(SaveObj, Slot, UserIdx);

#if !UE_BUILD_SHIPPING
	UE_LOG(LogTemp, Log, TEXT("[Save] Slot:%s User:%d Result:%s, Entries:%d"),
		*Slot, UserIdx, bOK ? TEXT("OK") : TEXT("FAIL"), SaveObj->Entries.Num());
#endif

	return bOK;
}

bool UHeroineSystem::Load(const FString& Slot, int32 UserIdx)
{
	USaveGame* Raw = UGameplayStatics::LoadGameFromSlot(Slot, UserIdx);
	if (!Raw)
	{
		UE_LOG(LogTemp, Warning, TEXT("[Load] Slot:%s User:%d -> No save found"), *Slot, UserIdx);
		return false;
	}

	UHeroineSaveGame* SaveObj = Cast<UHeroineSaveGame>(Raw);
	if (!SaveObj)
	{
		UE_LOG(LogTemp, Error, TEXT("[Load] Slot:%s -> Invalid SaveGame class"), *Slot);
		return false;
	}

	// 버전 호환 처리 (필요시 마이그레이션)
	if (SaveObj->SaveVersion != kCurrentSaveVersion)
	{
		// TODO: 여기서 마이그레이션 로직 적용 (필드 추가/이름 변경 등)
		UE_LOG(LogTemp, Log, TEXT("[Load] Version migrate: %d -> %d"),
			SaveObj->SaveVersion, kCurrentSaveVersion);
	}

	// 세이브 -> 런타임 맵 복원
	Runtime.Empty(SaveObj->Entries.Num());

	for (const FHeroineSaveEntry& E : SaveObj->Entries)
	{
		FHeroineRuntime& R = Runtime.FindOrAdd(E.HeroineId);
		R.HeroineId = E.HeroineId;
		R.Stats     = E.Stats;
		
		R.Flags.Empty(E.Flags.Num());
		for (const FName& Flag : E.Flags) R.Flags.Add(Flag);
	}

	// (선택) DataAsset의 기본값으로 빈 항목 채우기
	// -> InitFromData(Datas)를 로드 직후 한번 더 호출하면
	//    새로 추가된 스탯 키가 세이브에 없어도 Default로 채워짐.

	// UI와 동기화: 현재 값 브로드캐스트
	for (const auto& Pair : Runtime)
	{
		for (const auto& StatPair : Pair.Value.Stats)
		{
			OnStatChanged.Broadcast(Pair.Key, StatPair.Key);
		}
	}

#if !UE_BUILD_SHIPPING
	UE_LOG(LogTemp, Log, TEXT("[Load] Slot:%s OK, Entries:%d"), *Slot, SaveObj->Entries.Num());
#endif

	return true;
}
