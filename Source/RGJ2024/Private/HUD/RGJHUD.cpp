// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/RGJHUD.h"
#include "HUD/Widget/RGJUserWidget.h"

void ARGJHUD::InitOverlay()
{
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), PlayerWidgetClass);
	PlayerWidget = Cast<URGJUserWidget>(Widget);
	if (PlayerWidget)
	{
		PlayerWidget->AddToViewport();
	}
}
