// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBaseCpp.generated.h"

/**
 *
 */
UCLASS()
class PINGPONGCPP_API AMyGameStateBaseCpp : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(ReplicatedUsing = PlayerScoreChanged, BlueprintReadWrite)
	int32 Player1Score;

	UPROPERTY(ReplicatedUsing = PlayerScoreChanged, BlueprintReadWrite)
	int32 Player2Score;

	UFUNCTION()
	void PlayerScoreChanged();
};
