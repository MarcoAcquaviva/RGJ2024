// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RGJUserWidget.generated.h"

class URGJTutorialUserWidget;
class ARGJGameStateBase;
class UButton;
/**
 * 
 */
UCLASS()
class RGJ2024_API URGJUserWidget : public UUserWidget
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	float GetPercent(int index);

	UFUNCTION(BlueprintCallable)
	UObject* GetImage(int index);

	UFUNCTION(BlueprintCallable)
	void InitBars();

	UFUNCTION(BlueprintCallable)
	void UpdatePercentages();

	UFUNCTION(BlueprintCallable)
	void UpdatePercentages();

protected:
	TObjectPtr<ARGJGameStateBase> RGJGameState;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> BarraLeft;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> BarraMiddle;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> BarraRight;
};
