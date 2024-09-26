// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/Widget/RGJUserWidget.h"
#include "Kismet//GameplayStatics.h"
#include "Game/RGJGameStateBase.h"
#include "HUD/Widget/AttributeBarUserWidget.h"
#include "Kismet/BlueprintMapLibrary.h"

void URGJUserWidget::NativeOnInitialized()
{
	GameState = Cast<ARGJGameStateBase>(UGameplayStatics::GetGameState(this));
}

void URGJUserWidget::InitBars()
{
	int32 counter = 0;
	for (auto& value : GameState->AttributesChosen)
	{
		if (counter == 0)
			BarraLeft->SetAttributeInfo(value.Value);
		else if(counter == 1)
			BarraMiddle->SetAttributeInfo(value.Value);
		else if(counter == 2)
			BarraRight->SetAttributeInfo(value.Value);
		counter++;
	}

}
