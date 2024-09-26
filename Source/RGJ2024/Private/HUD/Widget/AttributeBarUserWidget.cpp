// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/Widget/AttributeBarUserWidget.h"
#include "Game/RGJGameStateBase.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ProgressBar.h"
#include "Styling/SlateTypes.h"
#include "Styling/SlateBrush.h"

void UAttributeBarUserWidget::NativeOnInitialized()
{
	GameState = Cast<ARGJGameStateBase>(UGameplayStatics::GetGameState(this));	
}

void UAttributeBarUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	SetShopAttributePercentage();
}

void UAttributeBarUserWidget::SetAttributeInfo(const FShopAttributeInfo& info)
{
	AttributeInfo = info;
	SetShopAttributeImage();
	SetShopAttributePercentage();
}

void UAttributeBarUserWidget::SetShopAttributePercentage()
{
	float percentValue = GetMaxPercentagaRatio();
	ProgressBar->SetPercent(percentValue);
}

void UAttributeBarUserWidget::SetShopAttributeImage()
{
	FSlateBrush Background;
	Background.SetResourceObject(AttributeInfo.BackgroundImage);
	FSlateBrush Foreground;
	Foreground.SetResourceObject(AttributeInfo.FillImage);
	FProgressBarStyle progressBarStyle;
	progressBarStyle.SetBackgroundImage(Background);
	progressBarStyle.SetFillImage(Foreground);
	ProgressBar->SetWidgetStyle(progressBarStyle);
}

float UAttributeBarUserWidget::GetMaxPercentagaRatio()
{
	if (GameState)
	{
		float currValue = AttributeInfo.Value;
		float maxValue = 100;
		for (auto& attribute : GameState->Attributes)
			if (attribute.Type == AttributeInfo.Type)
				maxValue = attribute.Value;
		return currValue / maxValue;
	}

	return 0.f;
}
