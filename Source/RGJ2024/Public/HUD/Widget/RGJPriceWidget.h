// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RGJPriceWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class RGJ2024_API URGJPriceWidget : public UUserWidget
{
	GENERATED_BODY()
public: 
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> PriceTextBox;
};
