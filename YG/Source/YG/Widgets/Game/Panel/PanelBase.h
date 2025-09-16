// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PanelBase.generated.h"

/**
 * 
 */
class UButton;
class UImage;

UCLASS()
class YG_API UPanelBase : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UButton* BackToMainButton;
};
