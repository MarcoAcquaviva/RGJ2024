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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	E_ShopAttribute Type = E_ShopAttribute::Batteria;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Value = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly )
	TArray<FShopAttributeInfo> Attributes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<E_ShopAttribute, FShopAttributeInfo> AttributesChosen;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxAttributePerGame = 3;

	bool CheckIfGameEnded();
	bool DidPlayerWin();

	UFUNCTION(BlueprintCallable)
	float GetTotalAmout();

	UFUNCTION(BlueprintCallable)
	void CalculateAttributeValue();

	UFUNCTION(BlueprintCallable)
	void InitAttributes();

	void UpdateInStatistics();
private: 

};
