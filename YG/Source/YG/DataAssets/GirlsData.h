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
	TObjectPtr<UTexture2D> HeroineTexture; // 사용할 텍스쳐 소스
	
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

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Heroine)
	TMap<FName, int32> DefaultStats;// 이름 변경하게되면 HeroineSystem에서도 적용 변경해주기
 

	// 필요 시 기본 플래그도 지원
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Heroine")
	TSet<FName> DefaultFlags;
};

UCLASS(BlueprintType)
class YG_API UGirlsData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	//TMap<FName, FHeroineStatic> GetHeroineData() { return HeroineDatas;}
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category= Heroine)
	TMap<FName, FHeroineStatic> HeroineDatas;

};
