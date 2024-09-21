// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EndGameWidget.generated.h"

class UTextBlock;
class USizeBox;
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
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USizeBox> SizeBox_GameRate;

	FORCEINLINE UTextBlock* GetTextGameStatus() const { return TextBox_GameStatus; }
	FORCEINLINE USizeBox* GetSizeBox() const { return SizeBox_GameRate; }

};
