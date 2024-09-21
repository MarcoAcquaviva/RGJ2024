// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RGJ_ShoppingItem.generated.h"

class UWidgetComponent;
class UProjectileMovementComponent;
class USoundCue;

UCLASS()
class RGJ2024_API ARGJ_ShoppingItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ARGJ_ShoppingItem();
	virtual void Destroyed() override;

protected:
	virtual void BeginPlay() override;

public:	

	void HideWidget();
	void ShowWidget();

	bool IsClickable = true;
	bool PriceAdded = false;
	bool IsDestroyed = false;

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UWidgetComponent> PriceWidgetComponent;
	UPROPERTY(EditAnywhere)
	float Price = 0;

	UPROPERTY(EditAnywhere, Category="OnDestroy")
	TObjectPtr<USoundCue> OnDestorySound;

public:
	FORCEINLINE float GetPrice() const { return Price; }
};
