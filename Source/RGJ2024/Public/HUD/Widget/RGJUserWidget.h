// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RGJUserWidget.generated.h"

class URGJTutorialUserWidget;
class ARGJGameStateBase;
class UAttributeBarUserWidget;
/**
 * 
 */
UCLASS()
class RGJ2024_API URGJUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void NativeOnInitialized() override;
	UFUNCTION(BlueprintCallable)
	void InitBars();

public:	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ARGJGameStateBase> GameState;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UAttributeBarUserWidget> BarraLeft;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UAttributeBarUserWidget> BarraMiddle;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UAttributeBarUserWidget> BarraRight;
protected:
};
