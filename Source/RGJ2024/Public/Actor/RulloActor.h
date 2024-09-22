// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RulloActor.generated.h"

class ARGJ_ShoppingItem;
class UBoxComponent;

UCLASS()
class RGJ2024_API ARulloActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARulloActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;


private:

protected:
	UPROPERTY(EditAnywhere, BluePrintReadOnly)
	TObjectPtr<UStaticMeshComponent> Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> BoxCollision;

	UFUNCTION()
	void InitRandomObject();

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<ARGJ_ShoppingItem>> ObjectsToSpawn;
	FTimerHandle SpawnItemHandler;

	void SpawnShopItem();
	FTransform GetSpawnTransform();
	bool AreItemSpawned = false;
};