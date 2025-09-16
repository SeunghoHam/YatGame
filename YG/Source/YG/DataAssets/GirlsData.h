// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GirlsData.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Melee,
	Range,
	Buffer,
};

// 런타임 상태(저장 대상)
USTRUCT(BlueprintType)
struct FHeroineStatic
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category=Heroine)
	FName HeroineId; // 명칭 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Heroine)
	FText DisplayName; // 화면상 보여질 이름
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Heroine)
	EWeaponType AttackType = EWeaponType::Melee;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Heroine)
	uint8 Friendly =0; // 친밀도. 용사 - 플레이어의 관계
	// 용사가 플레이어의 선택에 거부하지 않게 됨
	 
	 // 상승 : 이벤트, 의뢰 성공
	 // 하락 : 먼가 잘못된 선택을 했을 때, 의뢰 실패
	 
	 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Heroine)
	uint8 Relationship =0; // 우정도. 용사 - 플레이어의 신뢰
	// 우정도가 낮아지면 탈주 가능성이 생김
		
	// 상승 : 임무성공
	// 하락 : 임무실패
	
	
	// 초기화에 사용할 기본 스탯(예: Affection, Trust 등)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Heroine")
	TMap<FName, int32> DefaultStats; // 이름 변경하게되면 HeroineSystem에서도 적용 변경해주기

	// 필요 시 기본 플래그도 지원
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Heroine")
	TSet<FName> DefaultFlags;
	
	// 값 초기화에 사용할 스탯들
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Heroine)
	//TMap<FName, int32> Stats; // 수치값들

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TSet<FName>Flags; // 일회성 플래그(첫만남 등)
};

UCLASS(BlueprintType)
class YG_API UGirlsData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	/*
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName HeroineId;

	// 추적할 스탯 목록과 기본값 (예: Affection, Trust 등)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<FName, int32> DefaultStats;
*/
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category= Heroine)
	TMap<FName, FHeroineStatic> HeroineDatas;
	// 필요하면 설명/아이콘/이벤트 조건 등도 추가…
};
