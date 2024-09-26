// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Struct/ShopAttributeInfo.h"
#include "AttributeBarUserWidget.generated.h"

class UProgressBar;
class ARGJGameStateBase;

/**
 *
 */
UCLASS()
class RGJ2024_API UAttributeBarUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TObjectPtr<ARGJGameStateBase> GameState;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UProgressBar> ProgressBar;

	UFUNCTION(BlueprintCallable)
	void SetAttributeInfo(const FShopAttributeInfo& info);
	UFUNCTION(BlueprintCallable)
	void SetShopAttributePercentage();
	UFUNCTION(BlueprintCallable)
	void SetShopAttributeImage();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMaxPercentagaRatio();

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	FShopAttributeInfo AttributeInfo;
};