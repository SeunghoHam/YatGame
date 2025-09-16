// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Game/Panel/PanelBase.h"

#include "Components/Button.h"
#include "Widgets/Game/GameWidget_Action.h"

void UPanelBase::NativeConstruct()
{
	Super::NativeConstruct();
	//if (Btn_BackToMain) Btn_BackToMain->OnClicked.AddDynamic(this, &UPanelBase::HandleMainPanel);
}

/*
void UPanelBase::HandleMainPanel()
{
	OnPanelExitRequest.Broadcast(EPanelType::Main);
}
*/