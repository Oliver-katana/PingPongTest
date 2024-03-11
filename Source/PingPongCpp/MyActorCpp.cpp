// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorCpp.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GateCpp.h"
#include "MyGameStateBaseCpp.h"
#include "MyGameModeBaseCpp.h"


// Sets default values
AMyActorCpp::AMyActorCpp()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	SetReplicateMovement(true);

	//Creating ball

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = VisualMesh;

	VisualMesh->SetSimulatePhysics(true);
	VisualMesh->GetBodyInstance()->SetMassOverride(0.1f);
	VisualMesh->SetLinearDamping(0.0f);
	VisualMesh->SetAngularDamping(0.0f);
	VisualMesh->SetEnableGravity(false);
	VisualMesh->SetConstraintMode(EDOFMode::XYPlane);

	VisualMesh->SetNotifyRigidBodyCollision(true);
	VisualMesh->SetGenerateOverlapEvents(true);
	VisualMesh->SetCollisionProfileName(TEXT("PhysicsActor"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(SphereVisualAsset.Object);
		VisualMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	VisualMesh->OnComponentHit.AddDynamic(this, &AMyActorCpp::OnHit);
	VisualMesh->OnComponentBeginOverlap.AddDynamic(this, &AMyActorCpp::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AMyActorCpp::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyActorCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActorCpp::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (GetLocalRole() == ROLE_Authority)
	{
		PlayHitSound();
	}
}

void AMyActorCpp::PlayHitSound_Implementation()
{
	if (HitSound)
	{
		UGameplayStatics::PlaySound2D(this, HitSound);
	}
}

void AMyActorCpp::PlayGoalSound_Implementation()
{
	if (GoalSound)
	{
		UGameplayStatics::PlaySound2D(this, GoalSound);
	}
}

void AMyActorCpp::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AGateCpp* Gate = Cast<AGateCpp>(OtherActor);
	AMyGameStateBaseCpp* GameState = Cast<AMyGameStateBaseCpp>(UGameplayStatics::GetGameState(GetWorld()));

	if (Gate && GameState)
	{
		AMyGameModeBaseCpp* GameMode = Cast<AMyGameModeBaseCpp>(UGameplayStatics::GetGameMode(GetWorld()));
		if (GameMode)
		{
			if (Gate->ActorHasTag(TEXT("Gate1")))
			{
				++GameState->Player1Score;
			}
			if (Gate->ActorHasTag(TEXT("Gate2")))
			{
				++GameState->Player2Score;
			}
			PlayGoalSound();
			Destroy();
			GameMode->SpawnBall();
		}
	}
}
