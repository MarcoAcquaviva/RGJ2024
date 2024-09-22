// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/RGJHUD.h"
#include "HUD/Widget/RGJUserWidget.h"
#include "HUD/Widget/RGJTutorialUserWidget.h"
#include "Kismet/GameplayStatics.h"

void ARGJHUD::InitOverlay()
{
	UUserWidget* NewWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerWidgetClass);
	NewWidget->AddToViewport();
	PlayerWidget = Cast<URGJUserWidget>(NewWidget);

	UUserWidget* TutorialUserWidget = CreateWidget<UUserWidget>(GetWorld(), TutorialWidgetClass);
	TutorialUserWidget->AddToViewport();
	TutorialWidget = Cast<URGJTutorialUserWidget>(TutorialUserWidget);

	UGameplayStatics::SetGamePaused(GetWorld(), true);
}
