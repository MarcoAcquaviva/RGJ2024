// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RGJUserWidget.generated.h"

class URGJTutorialUserWidget;
/**
 * 
 */
UCLASS()
class RGJ2024_API URGJUserWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;
	
};
