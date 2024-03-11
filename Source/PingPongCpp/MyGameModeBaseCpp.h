// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBaseCpp.generated.h"

/**
 *
 */
UCLASS()
class PINGPONGCPP_API AMyGameModeBaseCpp : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyGameModeBaseCpp();

	UFUNCTION(BlueprintCallable)
	void SpawnBall();
	
private:
	UPROPERTY(EditAnywhere, Category = "Ball")
	TSubclassOf<class AMyActorCpp> MyBall;

	UPROPERTY(EditAnywhere, Category = "BallSpeed", meta = (ClampMin = "50", ClampMax = "120"))
	int32 BallSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
