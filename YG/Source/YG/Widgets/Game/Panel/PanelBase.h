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
class UWidgetSwitcher;
UCLASS()
class YG_API UPanelBase : public UUserWidget
{
	GENERATED_BODY()
public:
	
	//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPanelExitRequest, EPanelType, PanelType);
	//UPROPERTY(EditAnywhere, meta=(BindWidget))
	//UButton* Btn_BackToMain;

	//UPROPERTY(BlueprintAssignable, Category=Event)
	//FOnPanelExitRequest OnPanelExitRequest;

	// 가상함수로 설정해놔서 . Main에서 이 버튼 누르면 메인화면으로 가지도록 설정할거임~
	//UFUNCTION() virtual void HandleMainPanel();
	
	//void SetWidgetSwitcher();
	virtual void OnClickExitButton(){};

private:
	
};
