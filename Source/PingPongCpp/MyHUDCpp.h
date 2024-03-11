// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUDCpp.generated.h"

/**
 *
 */
UCLASS()
class PINGPONGCPP_API AMyHUDCpp : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay()override;

	UPROPERTY(EditDefaultsOnly, Category = "Widget")
	TSubclassOf<UUserWidget> ScoreWidget;

	UPROPERTY(BlueprintReadOnly)
	class UScoreWidgetCpp* ScoreWidgetRef = nullptr;
};
