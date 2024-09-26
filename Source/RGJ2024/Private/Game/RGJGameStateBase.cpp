// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/RGJGameStateBase.h"
#include "RGJ_ShoppingItem.h"
#include "Kismet/GameplayStatics.h"
#include "Game/RGJGameModeBase.h"
#include "Kismet/KismetMathLibrary.h"
#include "Struct/ShopAttributeInfo.h"
#include "Containers/Set.h"


bool ARGJGameStateBase::CheckIfGameEnded()
{
	if (CurretMoneyValue >= MaxMoneyUsable)
		return true;

	if (SpawnCounter >= NumberOfItemToSpawn)
	{
		for (auto Item : AllShopItems)
		{
			if (Item == nullptr) continue;
			if (!Item->IsDestroyed)
				return false;
		}
		return true;
	}

	return false;
}

bool ARGJGameStateBase::DidPlayerWin()
{
	if (CurretMoneyValue >= MaxMoneyUsable)
		return false;

	return true;
}

float ARGJGameStateBase::GetTotalAmout()
{
	float amout = 0.f;

	for (auto& Item : AllShopItems)
	{
		amout += Item->GetPrice();
	}
	return amout;
}


void ARGJGameStateBase::InitAttributes()
{
	int32 NumberOfItems = Attributes.Num();

	TSet<int32> RandomIndex;
	TSet<E_ShopAttribute> AttributesChosenType;
	while (AttributesChosen.Num() < MaxAttributePerGame)
	{
		int32 randomValue = UKismetMathLibrary::RandomInteger(Attributes.Num());
		FShopAttributeInfo& randomAttChosen = Attributes[randomValue];
		if (!RandomIndex.Contains(randomValue) && !AttributesChosenType.Contains(randomAttChosen.Type))
		{
			RandomIndex.Add(randomValue);
			FShopAttributeInfo attChosen;
			attChosen.Type = randomAttChosen.Type;
			attChosen.Value = 0.f;
			attChosen.BackgroundImage = randomAttChosen.BackgroundImage;
			attChosen.FillImage = randomAttChosen.FillImage;
			AttributesChosenType.Add(randomAttChosen.Type);
			AttributesChosen.Add(randomAttChosen.Type ,attChosen);
		}
	}

}

void ARGJGameStateBase::UpdateInStatistics()
{
	CalculateAttributeValue();
}

float ARGJGameStateBase::GetAttributeValue(E_ShopAttribute value)
{
	if (AttributesChosen.Contains(value))
		return AttributesChosen[value].Value;
	return 0.0f;
}

void ARGJGameStateBase::AddAttributeToCollection(TArray<FShopAttributeInfo> Array)
{
	for (FShopAttributeInfo item : Array)
	{
		AllShopItemCollected.Add(item);
	}
}

void ARGJGameStateBase::CalculateAttributeValue()
{
	if (AllShopItemCollected.IsEmpty() || AttributesChosen.IsEmpty())
		return;

	ResetAttributeChosenStatistics();

	for (auto& shop : AllShopItemCollected)
		if (AttributesChosen.Contains(shop.Type))
			AttributesChosen[shop.Type].Value += shop.Value;

}

void ARGJGameStateBase::ResetAttributeChosenStatistics()
{
	TArray<E_ShopAttribute> ItemInfoKeys;
	AttributesChosen.GetKeys(ItemInfoKeys);
	for (auto& item : ItemInfoKeys)
		AttributesChosen[item].Value = 0;
}
