// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RGJUserWidget.generated.h"

class URGJTutorialUserWidget;
class ARGJGameStateBase;
/**
 * 
 */
UCLASS()
class RGJ2024_API URGJUserWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	float GetPercent(int index);

	UFUNCTION(BlueprintCallable)
	UObject* GetImage(int index);

protected:
	TObjectPtr<ARGJGameStateBase> RGJGameState;
	
};
