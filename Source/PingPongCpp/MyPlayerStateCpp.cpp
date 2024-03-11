// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerStateCpp.h"
#include "ScoreWidgetCpp.h"
#include "MyHUDCpp.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void AMyPlayerStateCpp::UpdateScore_Server_Implementation(const int& Score1, const int& Score2)
{
	UpdateScore_Client(Score1, Score2);
	if (PlayerId % 2)
	{
		SetScore(Score2, Score1);
	}
	else
	{
		SetScore(Score1, Score2);
	}
}

void AMyPlayerStateCpp::UpdateScore_Client_Implementation(const int& Score1, const int& Score2)
{
	if (PlayerId % 2)
	{
		SetScore(Score1, Score2);
	}
	else
	{
		SetScore(Score2, Score1);
	}
}

void AMyPlayerStateCpp::SetScore(const int& Score1, const int& Score2)
{
	AMyHUDCpp* MyHUD = Cast<AMyHUDCpp>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if (MyHUD)
	{
		MyHUD->ScoreWidgetRef->player1_score->SetText(FText::AsNumber(Score1));
		MyHUD->ScoreWidgetRef->player2_score->SetText(FText::AsNumber(Score2));
	}
}