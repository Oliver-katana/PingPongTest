// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawnCpp.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/BoxComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyPawnMovementComponentCpp.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"


// Sets default values
AMyPawnCpp::AMyPawnCpp()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	//Creating platform
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	RootComponent = VisualMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -50.0f));
		VisualMesh->SetWorldScale3D(FVector(0.2f, 2.0f, 1.0f));
		VisualMesh->SetCollisionProfileName(TEXT("Pawn"));
		VisualMesh->SetGenerateOverlapEvents(false);
	}

	//Add SpringArm Component
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(VisualMesh);
	SpringArm->SetRelativeLocation(FVector(1000.0f, 0.0f, 100.0f));
	SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 1000.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	//Attach camera
	UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	//Add MovementComponent
	MyPawnMovementComponent = CreateDefaultSubobject<UMyPawnMovementComponentCpp>(TEXT("MovementComponent"));
	MyPawnMovementComponent->UpdatedComponent = RootComponent;
}

// Called when the game starts or when spawned
void AMyPawnCpp::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyPawnCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyPawnCpp::MoveRight_Server_Implementation(float AxisValue)
{
	MoveRight_Multicast(AxisValue);
}

void AMyPawnCpp::MoveRight_Multicast_Implementation(float AxisValue)
{
	this->AddMovementInput(GetActorRightVector(), AxisValue);
}

void AMyPawnCpp::Turn(float AxisValue)
{
	y += AxisValue;
	SpringArm->SetRelativeRotation(FRotator(-45.0f, y, 0.0f));
}




