// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CarrelloActor.generated.h"

class ARGJGameStateBase;

UCLASS()
class RGJ2024_API ACarrelloActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACarrelloActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent>LayerUno;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent>LayerDue;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent>LayerTre;

	ARGJGameStateBase* GameState;

};
