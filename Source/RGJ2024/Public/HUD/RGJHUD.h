// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RGJHUD.generated.h"

class URGJUserWidget;
class URGJTutorialUserWidget;

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
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> TutorialWidgetClass;
protected: 
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<URGJUserWidget> PlayerWidget;

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<URGJTutorialUserWidget> TutorialWidget;

	UFUNCTION(BlueprintCallable)
	virtual void InitOverlay();
};
