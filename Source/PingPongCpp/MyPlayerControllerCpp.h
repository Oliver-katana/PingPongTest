// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerControllerCpp.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONGCPP_API AMyPlayerControllerCpp : public APlayerController
{
	GENERATED_BODY()

	void MoveRight(float AxisValue);

	void Turn(float AxisValue);

	class AMyPawnCpp* MyPawn;

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float deltatime) override;

public:

	AMyPlayerControllerCpp();

	virtual void SetupInputComponent() override;

};
