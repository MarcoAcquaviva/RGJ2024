// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/Widget/RGJTutorialUserWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void URGJTutorialUserWidget::GetNextPage()
{
	++CurrentPage;
	if (CurrentPage >= Infos.Num())
	{
		CurrentPage = Infos.Num();
		RemoveFromParent();
		UGameplayStatics::SetGamePaused(GetWorld(), false);
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
