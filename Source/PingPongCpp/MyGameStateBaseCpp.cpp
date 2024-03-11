// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameStateBaseCpp.h"
#include "MyPlayerStateCpp.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"

void AMyGameStateBaseCpp::GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMyGameStateBaseCpp, Player1Score);
	DOREPLIFETIME(AMyGameStateBaseCpp, Player2Score);
}

void AMyGameStateBaseCpp::PlayerScoreChanged()
{
	AMyPlayerStateCpp* MyPlayerState = Cast<AMyPlayerStateCpp>(UGameplayStatics::GetPlayerController(this,0)->PlayerState);
	if (MyPlayerState)
	{
		MyPlayerState->UpdateScore_Server(Player1Score, Player2Score);
	}
}
