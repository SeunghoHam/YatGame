// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ChaPawn.h"
#include "Kismet/GameplayStatics.h" // GameInstnace
#include "YG/SubSystems/HeroineSystem.h"
#include "UObject/ConstructorHelpers.h"
// Sets default values
AChaPawn::AChaPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//static ConstructorHelpers::FClassFinder<UGirlsData> GirlsData1 (TEXT("/Game/"))
}

// Called when the game starts or when spawned
void AChaPawn::BeginPlay()
{
	Super::BeginPlay();
	if(UGameInstance* GI = GetGameInstance())
	{
		if (UHeroineSystem* HIS = GI->GetSubsystem<UHeroineSystem>())
		{
			//HIS->InitFromData();
		}
	}
}

// Called every frame
void AChaPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AChaPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

