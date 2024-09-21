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


private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> BoxCollision;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<ARGJ_ShoppingItem>> ObjectsToSpawn;
	UFUNCTION()
	void SpawnRandomObject();
	FTimerHandle SpawnItemHandler;
	int SpawnCounter = 0;
	int NumberOfItemToSpawn = 10;

};