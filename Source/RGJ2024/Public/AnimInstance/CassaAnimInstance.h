// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CassaAnimInstance.generated.h"

class ARGJ_ShoppingItem;
class ACassaActor;
/**
 * 
 */
UCLASS()
class RGJ2024_API UCassaAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public: 	
	virtual void NativeInitializeAnimation() override;

public:
	TObjectPtr<ACassaActor> Cassa;

	TArray<ARGJ_ShoppingItem*> ItemsToGrab;
	UFUNCTION(BlueprintCallable)
	void OnGrab_Montage();

	
};
