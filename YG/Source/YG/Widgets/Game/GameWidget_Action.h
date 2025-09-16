// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameWidget_Action.generated.h"

/**
 * 
 */
 class UWidgetSwitcher;
class UCanvasPanel;
UCLASS()
class YG_API UGameWidget_Action : public UUserWidget
{
	GENERATED_BODY()
public:
	
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta=(BindWidget)) UWidgetSwitcher* PanelSwitcher;
	
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta=(BindWidget)) UCanvasPanel* ActionMainPanel; // 메인 패널
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta=(BindWidget)) UCanvasPanel* SocialPanel; // 사교
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta=(BindWidget)) UCanvasPanel* BusinessPanel; // 도매(물건조달)
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta=(BindWidget)) UCanvasPanel* RequestPanel; // 의뢰
	
};
