// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "HeroineSaveGame.generated.h"


// 저장 전용: 런타임 구조를 그대로 써도 되지만, 향후 버전 업을 위해 DTO로 분리 권장
USTRUCT(BlueprintType)
struct FHeroineSaveEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName HeroineId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, int32> Stats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> Flags; // TSet은 직렬화 되지만, 세이브엔 Array가 무난
};
UCLASS()
class YG_API UHeroineSaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	UPROPERTY()
	int32 SaveVersion = 1;             // 버전 관리용

	UPROPERTY()
	TArray<FHeroineSaveEntry> Entries; // 히로인별 세이브 슬롯
};
