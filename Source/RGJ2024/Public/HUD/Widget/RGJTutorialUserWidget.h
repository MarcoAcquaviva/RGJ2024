// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RGJTutorialUserWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class RGJ2024_API URGJTutorialUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere)
	TArray<FString> Infos;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> TextBox_Tutorial;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> TextBox_ButtonNext;

	UFUNCTION(BlueprintCallable)
	void GetNextPage();

	UFUNCTION(BlueprintCallable)
	void GetPreviousPage();

	UFUNCTION(BlueprintCallable)
	void UpdatePage();
private:
	int32 CurrentPage = 0;

};
