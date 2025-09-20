// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "YG/DataAssets/GirlsData.h"


#include "ChaPawn.generated.h"



UCLASS()
class YG_API AChaPawn : public APawn
{
	GENERATED_BODY()
	
public:
	AChaPawn();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:
	 TSubclassOf<UGirlsData> GirlsData;

	
};
