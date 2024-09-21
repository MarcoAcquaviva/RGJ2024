// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "RGJGameStateBase.generated.h"

UENUM(BlueprintType)
enum class E_ShopAttribute : uint8
{
	Fame UMETA(DisplayName = "Fame") ,
	Gioco UMETA(DisplayName = "Gioco"),
	Batteria UMETA(DisplayName = "Batteria"),
	Sole UMETA(DisplayName = "Sole"),
	Notte UMETA(DisplayName = "Notte"),
	Lavoro UMETA(DisplayName = "Lavoro"),
};

USTRUCT(BlueprintType)
struct FShopAttributeInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	E_ShopAttribute Type = E_ShopAttribute::Batteria;

	UPROPERTY(EditAnywhere)
	float Value = 0;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UObject> Image;
};

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
	UPROPERTY(BlueprintReadWrite)
	TArray<ARGJ_ShoppingItem*> AllShopItems;
	UPROPERTY(BlueprintReadWrite)
	TArray<ARGJ_ShoppingItem*> AllShopItemCollected;
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

	UPROPERTY(EditAnywhere)
	TArray<FShopAttributeInfo> Attributes;

	UPROPERTY(VisibleAnywhere)
	TArray<FShopAttributeInfo> AttributesChosen;

	UPROPERTY(EditAnywhere)
	int32 MaxAttributePerGame = 3;

	bool CheckIfGameEnded();
	bool DidPlayerWin();

	UFUNCTION(BlueprintCallable)
	float GetTotalAmout();

	UFUNCTION(BlueprintCallable)
	void CalculateAttributeValue();

	UFUNCTION(BlueprintCallable)
	void InitAttributes();
private: 

};
