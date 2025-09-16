// Fill out your copyright notice in the Description page of Project Settings.


#include "GameWidget_Action.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "YG/Widgets/Game/Panel/Panel_Social.h"
#include "YG/Widgets/Game/Panel/Panel_Business.h"
#include "YG/Widgets/Game/Panel/Panel_Request.h"
#include "YG/Widgets/Game/Panel/Panel_Main.h"
void UGameWidget_Action::NativeConstruct()
{
	Super::NativeConstruct();

	MainPanel =  CreateWidget<UPanel_Main>(GetOwningPlayer(), MainPanelTemplate);
	if (MainPanel) { PanelSwitcher->AddChild(MainPanel);}
	SocialPanel=  CreateWidget<UPanel_Social>(GetOwningPlayer(), SocialPanelTemplate);
	if (SocialPanel) { PanelSwitcher->AddChild(SocialPanel);}
	BusinessPanel=  CreateWidget<UPanel_Business>(GetOwningPlayer(), BusinessPanelTemplate);
	if (BusinessPanel) { PanelSwitcher->AddChild(BusinessPanel);}
	RequestPanel=  CreateWidget<UPanel_Request>(GetOwningPlayer(), RequestPanelTemplate);
	if (RequestPanel) { PanelSwitcher->AddChild(RequestPanel);}

	if (bPanelBuilt)
	{
		ChangePanel(CurrentPanelType);
		return;
	}
	
	ChangePanel(EPanelType::Main);
	bPanelBuilt =true;


	if (Btn_Exit) Btn_Exit->OnClicked.AddDynamic(this,&UGameWidget_Action::HandleExit);
	if (Btn_Social) Btn_Social->OnClicked.AddDynamic(this,&UGameWidget_Action::HandleSoicalPanel);
	if (Btn_Business) Btn_Business->OnClicked.AddDynamic(this,&UGameWidget_Action::HandleBusinessPanel);
	if (Btn_Request) Btn_Request->OnClicked.AddDynamic(this,&UGameWidget_Action::HandleRequestPanel);
	
}

void UGameWidget_Action::ChangePanel(EPanelType _type)
{
	if (PanelSwitcher == nullptr) return;
	CurrentPanelType = _type;
	
	switch (CurrentPanelType)
	{
	case EPanelType::Main:
		PanelSwitcher->SetActiveWidget(MainPanel);break;
	case EPanelType::Social:
		PanelSwitcher->SetActiveWidget(SocialPanel);
		break;
	case EPanelType::Business:
		PanelSwitcher->SetActiveWidget(BusinessPanel);
		break;
	case EPanelType::Request:
		PanelSwitcher->SetActiveWidget(RequestPanel);
		break;
	default:
		break;
	}
}

void UGameWidget_Action::HandleExit()
{
	ChangePanel(EPanelType::Main);
}

void UGameWidget_Action::HandleSoicalPanel()
{
	ChangePanel(EPanelType::Social);
}

void UGameWidget_Action::HandleBusinessPanel()
{
	ChangePanel(EPanelType::Business);
}

void UGameWidget_Action::HandleRequestPanel()
{
	ChangePanel(EPanelType::Request);
}
