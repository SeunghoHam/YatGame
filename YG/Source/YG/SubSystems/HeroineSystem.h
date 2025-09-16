// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"


#include "YG/DataAssets/GirlsData.h" // HeroineData
#include "HeroineSystem.generated.h"

/**
 * 
 */



USTRUCT(BlueprintType)
struct FHeroineRuntime
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName HeroineId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, int32> Stats;  // 진행 중 변하는 수치

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSet<FName> Flags;         // 일회성/분기 플래그
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStatChanged, FName, HeroineId, FName, StatName);

UCLASS()
class YG_API UHeroineSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:

	// 초기화: 등록된 DataAsset을 받아 기본값 세팅
	UFUNCTION(BlueprintCallable)
	void InitFromData(const TArray<UGirlsData*>& Datas);
	UFUNCTION(BlueprintCallable)
	int32 AddStat(FName HeroineId, FName Stat, int32 Delta);
	
	UFUNCTION(BlueprintCallable) bool Save(const FString& Slot = TEXT("DatingSlot"), int32 UserIdx = 0);
	UFUNCTION(BlueprintCallable) bool Load(const FString& Slot = TEXT("DatingSlot"), int32 UserIdx = 0);
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStatChanged, FName, HeroineId, FName, StatName);
	UPROPERTY(BlueprintAssignable)
	FOnStatChanged OnStatChanged;

private:
	UPROPERTY()
	TMap<FName, FHeroineRuntime> Runtime;
};
