// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RGJHUD.generated.h"

class URGJUserWidget;

/**
 * 
 */
UCLASS()
class RGJ2024_API ARGJHUD : public AHUD
{
	GENERATED_BODY()
	
public :

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> PlayerWidgetClass;
protected: 
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<URGJUserWidget> PlayerWidget;

	UFUNCTION(BlueprintCallable)
	virtual void InitOverlay();
};
