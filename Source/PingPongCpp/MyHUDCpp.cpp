// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUDCpp.h"
#include "ScoreWidgetCpp.h"
#include "Blueprint/UserWidget.h"

void AMyHUDCpp::BeginPlay()
{
	Super::BeginPlay();
	if (ScoreWidget)
	{
		ScoreWidgetRef = Cast<UScoreWidgetCpp>(CreateWidget(GetWorld(), ScoreWidget));
		if (ScoreWidgetRef)
		{
			ScoreWidgetRef->AddToViewport();
		}
	}
}
