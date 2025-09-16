// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameWidget_Action.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EPanelType : uint8
{
	Main,
	Social,
	Business,
	Request,
};
 class UWidgetSwitcher;
class UCanvasPanel;
class UButton;
//class UUserWidget;

class UPanel_Main;
class UPanel_Social;
class UPanel_Business;
class UPanel_Request;
UCLASS()
class YG_API UGameWidget_Action : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
public:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget)) UWidgetSwitcher* PanelSwitcher;

	
	UPROPERTY(BlueprintReadWrite) UPanel_Main* MainPanel = nullptr; // 메인 패널
	UPROPERTY(BlueprintReadWrite) UPanel_Social* SocialPanel = nullptr; // 사교
	UPROPERTY(BlueprintReadWrite) UPanel_Business* BusinessPanel = nullptr; // 도매(물건조달)
	UPROPERTY(BlueprintReadWrite) UPanel_Request* RequestPanel = nullptr; // 의뢰

	UPROPERTY(EditAnywhere, Category=Setting) TSubclassOf<UPanel_Main> MainPanelTemplate;
	UPROPERTY(EditAnywhere, Category=Setting) TSubclassOf<UPanel_Social> SocialPanelTemplate;
	UPROPERTY(EditAnywhere, Category=Setting) TSubclassOf<UPanel_Business> BusinessPanelTemplate;
	UPROPERTY(EditAnywhere, Category=Setting) TSubclassOf<UPanel_Request> RequestPanelTemplate;


	UPROPERTY(BlueprintReadWrite,meta=(BindWidget)) UButton* Btn_Exit;
	UPROPERTY(BlueprintReadWrite,meta=(BindWidget)) UButton* Btn_Social;
	UPROPERTY(BlueprintReadWrite,meta=(BindWidget)) UButton* Btn_Business;
	UPROPERTY(BlueprintReadWrite,meta=(BindWidget)) UButton* Btn_Request;
	
	EPanelType CurrentPanelType = EPanelType::Main;
	
	void ChangePanel(EPanelType _type);

	UFUNCTION() void HandleExit();
	UFUNCTION()void HandleSoicalPanel();
	UFUNCTION()void HandleBusinessPanel();
	UFUNCTION()void HandleRequestPanel();

private:
	bool bPanelBuilt= false;
};
