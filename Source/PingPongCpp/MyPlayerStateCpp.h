// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MyPlayerStateCpp.generated.h"

/**
 *
 */
UCLASS()
class PINGPONGCPP_API AMyPlayerStateCpp : public APlayerState
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void UpdateScore_Server(const int& Score1, const int& Score2);

	UFUNCTION(Client, Reliable, BlueprintCallable)
	void UpdateScore_Client(const int& Score1,const int& Score2);

	UFUNCTION(BlueprintCallable)
	void SetScore(const int& Score1,const int& Score2);
};
