// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/Widget/AttributeBarUserWidget.h"
#include "Components/Image.h"
#include "Styling/SlateBrush.h"
#include "RGJ_ShoppingItem.h"

void UAttributeBarUserWidget::SetPercentage()
{
	
}

void UAttributeBarUserWidget::SetImage()
{
	FSlateBrush Brush;
	Brush.SetResourceObject(AttributeInfo->Image);
	Image->SetBrush(Brush);
}
