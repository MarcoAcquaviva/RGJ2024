// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EndGameWidget.generated.h"

class UTextBlock;
class USizeBox;
class UAttributeBarUserWidget;
/**
 * 
 */
UCLASS()
class RGJ2024_API UEndGameWidget : public UUserWidget
{
	GENERATED_BODY()
public: 

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> TextBox_GameStatus;

	UFUNCTION(BlueprintImplementableEvent)
	void SetBars();

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,meta = (BindWidget))
	TObjectPtr<UAttributeBarUserWidget> Progress_StateOne;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UAttributeBarUserWidget> Progress_StateTwo;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UAttributeBarUserWidget> Progress_StateThree;

	FORCEINLINE UTextBlock* GetTextGameStatus() const { return TextBox_GameStatus; }

};
