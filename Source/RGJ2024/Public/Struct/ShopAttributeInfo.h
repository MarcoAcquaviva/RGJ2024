// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShopAttributeInfo.generated.h"

UENUM(BlueprintType)
enum class E_ShopAttribute : uint8
{
	Fame UMETA(DisplayName = "Fame"),
	Gioco UMETA(DisplayName = "Gioco"),
	Batteria UMETA(DisplayName = "Batteria"),
	Sole UMETA(DisplayName = "Sole"),
	Notte UMETA(DisplayName = "Notte"),
	Lavoro UMETA(DisplayName = "Lavoro"),

	E_MAX UMETA(DisplayName ="Max")
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct RGJ2024_API FShopAttributeInfo
{
	GENERATED_BODY()

	FShopAttributeInfo() {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	E_ShopAttribute Type = E_ShopAttribute::Batteria;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UObject> BackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UObject> FillImage;

};