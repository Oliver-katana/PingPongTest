// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBaseCpp.h"
#include "MyActorCpp.h"
#include "MyPawnCpp.h"
#include "Components/StaticMeshComponent.h"
#include "MyPlayerControllerCpp.h"

AMyGameModeBaseCpp::AMyGameModeBaseCpp()
{
	ConstructorHelpers::FObjectFinder<UClass>MyPlayerPawn(TEXT("/Game/MainBPs/MyPawnBP.MyPawnBP_C"));
	if (MyPlayerPawn.Object)
	{
		DefaultPawnClass = MyPlayerPawn.Object;
	}

	PlayerControllerClass = AMyPlayerControllerCpp::StaticClass();

	ConstructorHelpers::FObjectFinder<UClass>MyPlayerState(TEXT("/Game/MainBPs/MyPlayerStateBP.MyPlayerStateBP_C"));
	if (MyPlayerState.Object)
	{
		PlayerStateClass = MyPlayerState.Object;
	}
	ConstructorHelpers::FObjectFinder<UClass>MyGameState(TEXT("/Game/MainBPs/MyGameStateBP.MyGameStateBP_C"));
	if (MyGameState.Object)
	{
		GameStateClass = MyGameState.Object;
	}
	ConstructorHelpers::FObjectFinder<UClass>MyHUD(TEXT("/Game/MainBPs/MyHudBP.MyHudBP_C"));
	if (MyHUD.Object)
	{
		HUDClass = MyHUD.Object;
	}

	BallSpeed = 100;
}

void AMyGameModeBaseCpp::BeginPlay()
{
	Super::BeginPlay();
}

void AMyGameModeBaseCpp::SpawnBall()
{
	FActorSpawnParameters SpawnParams;
	AMyActorCpp* Ball = GetWorld()->SpawnActor<AMyActorCpp>(MyBall, FVector(700.0f, 300.0f, 50.0f), FRotator(0.0f, rand() % 360, 0.0f), SpawnParams);
	UStaticMeshComponent* StaticMesh = Cast<UStaticMeshComponent>(Ball->GetRootComponent());
	if (StaticMesh)
	{
		FVector ImpulseVector = StaticMesh->GetForwardVector();
		ImpulseVector.Z = 0;
		StaticMesh->AddImpulse(ImpulseVector * BallSpeed);
	}
}
