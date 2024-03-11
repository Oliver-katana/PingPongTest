// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerControllerCpp.h"
#include "MyPawnCpp.h"

AMyPlayerControllerCpp::AMyPlayerControllerCpp()
{
}

void AMyPlayerControllerCpp::BeginPlay()
{
	Super::BeginPlay();
	MyPawn = Cast<AMyPawnCpp>(GetPawn());
}

void AMyPlayerControllerCpp::Tick(float deltatime)
{
	if (WasInputKeyJustPressed(EKeys::Q))
	{
		ConsoleCommand("quit");
	}
}

void AMyPlayerControllerCpp::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveRight", this, &AMyPlayerControllerCpp::MoveRight);
	InputComponent->BindAxis("Turn", this, &AMyPlayerControllerCpp::Turn);
}

void AMyPlayerControllerCpp::MoveRight(float AxisValue)
{
	if (MyPawn)
	{
		MyPawn->MoveRight_Server(AxisValue);
	}
}

void AMyPlayerControllerCpp::Turn(float AxisValue)
{
	if (MyPawn)
	{
		MyPawn->Turn(AxisValue);
	}
}
