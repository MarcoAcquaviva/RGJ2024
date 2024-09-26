// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CassaActor.generated.h"

class UBoxComponent;
class UWidgetComponent;
class UAnimMontage;
class USkeletalMeshComponent;

UCLASS()
class RGJ2024_API ACassaActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACassaActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	UFUNCTION(BlueprintCallable)
	void UpdatePriceWidget();

private: 
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> BoxCollision;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USkeletalMeshComponent> HandMesh;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UWidgetComponent> PriceWidgetComponent;
	float PriceSum;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAnimMontage> OnGrabMontage;
	void PlayGrabMontage();


public:

	FORCEINLINE USkeletalMeshComponent* GetHandMesh() const { return HandMesh; }
};
