// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Panel_Main.generated.h"

/**
 * 
 */
class UHeroineMainWidget;

UCLASS()
class YG_API UPanel_Main : public UUserWidget
{
	GENERATED_BODY()
public:
	TSubclassOf<UHeroineMainWidget> HeroineWidgetClass;
	// MainScreen Action
	// 1. 내 히로인들 정보 띄우기
	// 2. 나으 그녀들
};
