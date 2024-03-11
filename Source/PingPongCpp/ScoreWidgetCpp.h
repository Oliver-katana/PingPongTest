// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidgetCpp.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONGCPP_API UScoreWidgetCpp : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* player1_score;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* player2_score;
};
