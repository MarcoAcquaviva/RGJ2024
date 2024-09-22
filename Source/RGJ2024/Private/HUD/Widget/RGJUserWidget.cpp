// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/Widget/RGJUserWidget.h"
#include "Kismet//GameplayStatics.h"
#include "Game/RGJGameStateBase.h"
#include "Components/Button.h"

float URGJUserWidget::GetPercent(int index)
{
	ARGJGameStateBase* GameState = Cast<ARGJGameStateBase>(UGameplayStatics::GetGameState(GetWorld()));
	if (GameState)
	{
		if (GameState->AttributesChosen.Num() <= index)
			return 0;

		float maxValue = 1;
		TArray<FShopAttributeInfo>ShopAttributes;
		GameState->AttributesChosen.GenerateValueArray(ShopAttributes);
		FShopAttributeInfo AttributeChosen = ShopAttributes[index];

		for (auto& attribute : GameState->Attributes)
			if (attribute.Type == AttributeChosen.Type)
				maxValue = attribute.Value;
		return AttributeChosen.Value / maxValue;
	}
	return 0;
}
	
UObject* URGJUserWidget::GetImage(int index)
{
	ARGJGameStateBase* GameState = Cast< ARGJGameStateBase>(UGameplayStatics::GetGameState(GetWorld()));
	if (GameState)
	{
		TArray<FShopAttributeInfo>ShopAttributes;
		GameState->AttributesChosen.GenerateValueArray(ShopAttributes);
		FShopAttributeInfo AttributeChosen = ShopAttributes[index];
		if (GameState->AttributesChosen.Num() <= index)
			return nullptr;
		return AttributeChosen.Image;
	}
	return nullptr;
}

void URGJUserWidget::InitBars()
{
}


