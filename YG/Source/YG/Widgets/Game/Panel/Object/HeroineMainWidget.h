// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HeroineMainWidget.generated.h"

UCLASS()
class YG_API UHeroineMainWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void NativeConstruct() override;
};
