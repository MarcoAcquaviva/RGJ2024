// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/Widget/RGJUserWidget.h"
#include "Kismet//GameplayStatics.h"
#include "Game/RGJGameStateBase.h"

void URGJUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

float URGJUserWidget::GetPercent(int index)
{
	ARGJGameStateBase* GameState = Cast< ARGJGameStateBase>(UGameplayStatics::GetGameState(GetWorld()));
	if (GameState)
	{
		if (GameState->AttributesChosen.Num() <= index)
			return 0;
		return GameState->AttributesChosen[index].Value;
	}
	return 0;
}
	
UObject* URGJUserWidget::GetImage(int index)
{
	ARGJGameStateBase* GameState = Cast< ARGJGameStateBase>(UGameplayStatics::GetGameState(GetWorld()));
	if (GameState)
	{
		if (GameState->AttributesChosen.Num() <= index)
			return nullptr;
		return GameState->AttributesChosen[index].Image;
	}
	return nullptr;
}


