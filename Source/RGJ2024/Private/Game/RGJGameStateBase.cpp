// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/RGJGameStateBase.h"
#include "RGJ_ShoppingItem.h"
#include "Kismet/GameplayStatics.h"
#include "Game/RGJGameModeBase.h"
#include "Kismet/KismetMathLibrary.h"



bool ARGJGameStateBase::CheckIfGameEnded()
{

	if (CurretMoneyValue >= MaxMoneyUsable)
		return true;

	if (SpawnCounter >= NumberOfItemToSpawn)
	{
		for (auto Item : AllShopItems)
		{
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

void ARGJGameStateBase::CalculateAttributeValue()
{
	for (auto& Item : AllShopItemCollected)
	{
		for (auto& attchChosen : AttributesChosen)
		{
			TArray<FShopAttributeInfo> shopsInfo = Item->GetAttributes();
			for (auto& shop : shopsInfo)
			{
				if (attchChosen.Type == shop.Type)
				{
					attchChosen.Value += shop.Value;
				}
			}
		}
	}
}

void ARGJGameStateBase::InitAttributes()
{
	int32 NumberOfItems = Attributes.Num();

	TSet<int32> RandomIndex;
	while (AttributesChosen.Num() < MaxAttributePerGame)
	{
		int32 randomValue = UKismetMathLibrary::RandomInteger(Attributes.Num());
		if (!RandomIndex.Contains(randomValue))
		{
			RandomIndex.Add(randomValue);
			FShopAttributeInfo attChosen;
			attChosen.Type = Attributes[randomValue].Type;
			AttributesChosen.Add(attChosen);
		}
	}

}

