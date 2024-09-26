// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Struct/ShopAttributeInfo.h"
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

public:
	/*Spawn*/
	UPROPERTY(BlueprintReadWrite)
	TArray<ARGJ_ShoppingItem*> AllShopItems;

	UPROPERTY(EditAnywhere, Category = "Debug")
	bool bUseDebugObject;

	UPROPERTY(EditAnywhere, Category = "Debug")
	TSubclassOf<ARGJ_ShoppingItem> DebugObject;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawn")
	int SpawnCounter = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn")
	int NumberOfItemToSpawn = 10;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Money")
	float MaxMoneyUsable = 20.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Money")
	float MoneyOfAllItems = 0.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly ,Category = "Money")
	float CurretMoneyValue = 0.f;

	UFUNCTION(BlueprintCallable)
	float GetTotalAmout();

	/*Attribute */
	UPROPERTY(BlueprintReadWrite)
	TArray<FShopAttributeInfo> AllShopItemCollected;

	UPROPERTY(EditAnywhere, BlueprintReadOnly )
	TArray<FShopAttributeInfo> Attributes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<E_ShopAttribute, FShopAttributeInfo> AttributesChosen;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxAttributePerGame = 3;

	UFUNCTION(BlueprintCallable)
	void InitAttributes();

	UFUNCTION(BlueprintCallable)
	void CalculateAttributeValue();

	void UpdateInStatistics();

	UFUNCTION(BlueprintCallable)
	float GetAttributeValue(E_ShopAttribute value);

	void AddAttributeToCollection(TArray<FShopAttributeInfo> Array);

	/*Core logic */
	bool CheckIfGameEnded();
	bool DidPlayerWin();

private: 
	
	void ResetAttributeChosenStatistics();


};
