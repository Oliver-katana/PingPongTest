// Fill out your copyright notice in the Description page of Project Settings.


#include "GateCpp.h"
#include "Components/BoxComponent.h"

// Sets default values
AGateCpp::AGateCpp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionComponent"));

	BoxComponent->SetCollisionProfileName(TEXT("Gate"));
}

// Called when the game starts or when spawned
void AGateCpp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGateCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

