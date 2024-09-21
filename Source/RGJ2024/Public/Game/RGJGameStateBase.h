// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "RGJGameStateBase.generated.h"

class ARGJ_ShoppingItem;

/**
 * 
 */
UCLASS()
class RGJ2024_API ARGJGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
	TArray<ARGJ_ShoppingItem*> AllShopItems;
	UPROPERTY(VisibleAnywhere, Category = "Spawn")
	int SpawnCounter = 0;
	UPROPERTY(EditAnywhere, Category = "Spawn")
	int NumberOfItemToSpawn = 10;
	UPROPERTY(EditAnywhere, Category = "Money")
	float MaxMoneyUsable = 20.5f;
	UPROPERTY(EditAnywhere, Category = "Money")
	float MoneyOfAllItems = 0.f;
	UPROPERTY(VisibleAnywhere, Category = "Money")
	float CurretMoneyValue = 0.f;

	bool CheckIfGameEnded();

	UFUNCTION(BlueprintCallable)
	float GetTotalAmout();

};
