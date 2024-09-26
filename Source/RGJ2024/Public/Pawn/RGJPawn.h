// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RGJPawn.generated.h"

class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class RGJ2024_API ARGJPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARGJPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected: 
	UPROPERTY(EditAnywhere)
	TObjectPtr<USkeletalMeshComponent> SkeletonMesh;
	//UPROPERTY(EditAnywhere)
	//TObjectPtr<USpringArmComponent> SpringArm;
	//UPROPERTY(EditAnywhere)
	//TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAnimMontage> OnGrabMontage;

public:
	void PlayMontage();
	void SetHandPosition(FVector NewVector);
};
