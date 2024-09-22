// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/Widget/RGJTutorialUserWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "HUD/RGJHUD.h"
#include "HUD/Widget/RGJUserWidget.h"

void URGJTutorialUserWidget::GetNextPage()
{
	++CurrentPage;
	if (CurrentPage >= Infos.Num())
	{
		CurrentPage = Infos.Num();
		RemoveFromParent();
		UGameplayStatics::SetGamePaused(GetWorld(), false);
		const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		AHUD* HUD = PlayerController->GetHUD();
		ARGJHUD* RGJHUD = Cast<ARGJHUD>(HUD);
		URGJUserWidget* UserWidget = RGJHUD->GetUserWidget();
		UserWidget->SetVisibility(ESlateVisibility::Visible);
		return;
	}
	UpdatePage();
}

void URGJTutorialUserWidget::GetPreviousPage()
{
	--CurrentPage;
	if (CurrentPage <= 0)
	{
		CurrentPage = 0;
		RemoveFromParent();
		return;
	}

	UpdatePage();
}

void URGJTutorialUserWidget::UpdatePage()
{
	if (TextBox_Tutorial)
	{
		TextBox_Tutorial->SetText(FText::FromString( Infos[CurrentPage]));
	}

	if (CurrentPage == Infos.Num()-1)
	{
		TextBox_ButtonNext->SetText(FText::FromString(TEXT("Start")));
	}
}
