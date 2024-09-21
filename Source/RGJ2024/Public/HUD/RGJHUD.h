// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RGJHUD.generated.h"

class URGJUserWidget;
class URGJTutorialUserWidget;
class URGJPauseWidget;
class UEndGameWidget;

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
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> PauseWidgetClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> EndWidgetClass;
protected: 
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<URGJUserWidget> PlayerWidget;

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<URGJTutorialUserWidget> TutorialWidget;

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<URGJPauseWidget> PauseWidget;

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UEndGameWidget> EndWidget;

	UFUNCTION(BlueprintCallable) 
	virtual void InitOverlay();

public:

	URGJPauseWidget* GetPauseWidget()const { return PauseWidget; }
	UEndGameWidget* GetEndGameWidget()const { return EndWidget; }
};
