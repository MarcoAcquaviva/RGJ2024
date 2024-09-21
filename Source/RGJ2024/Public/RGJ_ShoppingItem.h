// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RGJ_ShoppingItem.generated.h"

class UWidgetComponent;
class UProjectileMovementComponent;
class USoundCue;
class UParticleSystem;
struct FShopAttributeInfo;
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
	void PlaySpawnSound();
	void PlaySpawnEmitter();

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
	UPROPERTY(EditAnywhere, Category="OnDestroy")
	TObjectPtr<UParticleSystem> OnDestoryParticle;

	UPROPERTY(EditAnywhere, Category="OnSpawn")
	TObjectPtr<USoundCue> OnSpawnSound;
	UPROPERTY(EditAnywhere, Category="OnSpawn")
	TObjectPtr<UParticleSystem> OnSpawnParticle;

	UPROPERTY(EditAnywhere)
	TArray<FShopAttributeInfo> Attributes;

public:
	FORCEINLINE float GetPrice() const { return Price; }
	FORCEINLINE TArray<FShopAttributeInfo>  GetAttributes() const { return Attributes; }
};
