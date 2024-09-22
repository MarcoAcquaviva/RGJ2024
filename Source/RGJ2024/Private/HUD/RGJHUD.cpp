// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/RGJHUD.h"
#include "HUD/Widget/RGJUserWidget.h"
#include "HUD/Widget/RGJTutorialUserWidget.h"
#include "HUD/Widget/RGJPauseWidget.h"
#include "HUD/Widget/EndGameWidget.h"
#include "HUD/Widget/InitialPageUserWidget.h"
#include "Kismet/GameplayStatics.h"

void ARGJHUD::InitOverlay()
{
	UUserWidget* NewWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerWidgetClass);
	NewWidget->AddToViewport();
	NewWidget->SetVisibility(ESlateVisibility::Hidden);
	PlayerWidget = Cast<URGJUserWidget>(NewWidget);

	UUserWidget* TutorialUserWidget = CreateWidget<UUserWidget>(GetWorld(), TutorialWidgetClass);
	TutorialUserWidget->AddToViewport();
	TutorialUserWidget->SetVisibility(ESlateVisibility::Hidden);
	TutorialWidget = Cast<URGJTutorialUserWidget>(TutorialUserWidget);
	TutorialWidget->UpdatePage();
	
	UUserWidget* PauseUserWidget = CreateWidget<UUserWidget>(GetWorld(), PauseWidgetClass);
	PauseUserWidget->AddToViewport();
	PauseWidget = Cast<URGJPauseWidget>(PauseUserWidget);
	PauseUserWidget->SetVisibility(ESlateVisibility::Hidden);

	UUserWidget* EndGameUserWidget = CreateWidget<UUserWidget>(GetWorld(), EndWidgetClass);
	EndGameUserWidget->AddToViewport();
	EndGameUserWidget->SetVisibility(ESlateVisibility::Hidden);
	EndWidget = Cast<UEndGameWidget>(EndGameUserWidget);

	UUserWidget* InitialGameUserWidget = CreateWidget<UUserWidget>(GetWorld(), InitialPageWidgetClass);
	InitialGameUserWidget->AddToViewport();
	InitialGameUserWidget->SetVisibility(ESlateVisibility::Visible);
	InitialPageWidget = Cast<UInitialPageUserWidget>(InitialGameUserWidget);

	UGameplayStatics::SetGamePaused(GetWorld(), true);
}
