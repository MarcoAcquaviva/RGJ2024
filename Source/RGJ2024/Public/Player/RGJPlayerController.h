// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RGJPlayerController.generated.h"

class ARGJ_ShoppingItem;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class RGJ2024_API ARGJPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	void PlayerTick(const float DeltaTime) override;

protected: 
	void BeginPlay() override;
	void SetupInputComponent() override;

private: 
	FHitResult CursorHit;
	void CursorTrace();
	void HitShoppingItem();

	TObjectPtr<ARGJ_ShoppingItem> LastActorHit;
	TObjectPtr<ARGJ_ShoppingItem> ThisActorHit;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> ClickAction;

	void OnComplete_ClickAction();
};
