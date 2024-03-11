// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawnCpp.generated.h"



UCLASS()
class PINGPONGCPP_API AMyPawnCpp : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

	UPROPERTY()
	class USpringArmComponent* SpringArm;

	float y = 0;

public:
	// Sets default values for this pawn's properties
	AMyPawnCpp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	class UMyPawnMovementComponentCpp* MyPawnMovementComponent;

	UFUNCTION(Server, Reliable)
	void MoveRight_Server(float AxisValue);

	UFUNCTION(NetMulticast, Reliable)
	void MoveRight_Multicast(float AxisValue);

	void Turn(float AxisValue);
};
