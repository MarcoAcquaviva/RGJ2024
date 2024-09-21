// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/RGJPlayerController.h"
#include "Engine/HitResult.h"
#include "RGJ_ShoppingItem.h"
#include "Input/RGJEnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void ARGJPlayerController::PlayerTick(const float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();

	HitShoppingItem();
}

void ARGJPlayerController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Hand;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ARGJPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	URGJEnhancedInputComponent* RGJInputComponent = CastChecked<URGJEnhancedInputComponent>(InputComponent);
	check(ClickAction);

	RGJInputComponent->BindAction(ClickAction, ETriggerEvent::Completed, this, &ARGJPlayerController::OnComplete_ClickAction);
}

void ARGJPlayerController::CursorTrace()
{
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);

	if (!CursorHit.bBlockingHit) return;

}

void ARGJPlayerController::HitShoppingItem()
{
	ARGJ_ShoppingItem* ItemFound = Cast<ARGJ_ShoppingItem>(CursorHit.GetActor());

	LastActorHit = ThisActorHit;
	ThisActorHit = ItemFound;

	if (LastActorHit != ThisActorHit)
	{
		if (LastActorHit) LastActorHit->HideWidget();
		if (ThisActorHit) ThisActorHit->ShowWidget();
	}

}

void ARGJPlayerController::OnComplete_ClickAction()
{
	if (!CursorHit.bBlockingHit) return;

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Clicked!"));
}
