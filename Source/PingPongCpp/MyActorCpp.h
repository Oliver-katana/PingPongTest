// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Sound/SoundCue.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorCpp.generated.h"

UCLASS()
class PINGPONGCPP_API AMyActorCpp : public AActor
{
	GENERATED_BODY()
private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(NetMulticast, Reliable)
	void PlayHitSound();

	UFUNCTION(NetMulticast, Reliable)
	void PlayGoalSound();


	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


public:
	// Sets default values for this actor's properties
	AMyActorCpp();

	UPROPERTY(EditAnywhere, category = "Components")
	class UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere, Category = "BallSounds")
	USoundCue* HitSound;

	UPROPERTY(EditAnywhere, Category = "BallSounds")
	USoundCue* GoalSound;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
