// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/RGJGameStateBase.h"
#include "RGJ_ShoppingItem.h"



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

float ARGJGameStateBase::GetTotalAmout()
{
	float amout = 0.f;

	for (auto Item : AllShopItems)
	{
		amout += Item->GetPrice();
	}
	return amout;
}
