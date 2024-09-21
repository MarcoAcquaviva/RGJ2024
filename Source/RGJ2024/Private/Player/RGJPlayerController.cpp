// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/RGJPlayerController.h"
#include "Engine/HitResult.h"
#include "RGJ_ShoppingItem.h"
#include "Input/RGJEnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "Game/RGJGameStateBase.h"
#include "HUD/RGJHUD.h"
#include "HUD/Widget/RGJPauseWidget.h"
#include "HUD/Widget/EndGameWidget.h"
#include "Components/TextBlock.h"

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
	DefaultMouseCursor = EMouseCursor::Default;

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
	RGJInputComponent->BindAction(PauseAction, ETriggerEvent::Completed, this, &ARGJPlayerController::OnComplete_PauseGame);
	RGJInputComponent->BindAction(ExitAction, ETriggerEvent::Completed, this, &ARGJPlayerController::OnComplete_ExitGame);
}

void ARGJPlayerController::UpdateEndGame()
{
	ARGJGameStateBase* GameState = Cast<ARGJGameStateBase>(UGameplayStatics::GetGameState(GetWorld()));
	if (GameState->CheckIfGameEnded())
	{
		IsPaused = UGameplayStatics::IsGamePaused(GetWorld());
		ARGJHUD* HUD = Cast<ARGJHUD>(GetHUD());
		UEndGameWidget* EndGameWidget = HUD->GetEndGameWidget();
		if (EndGameWidget)
		{
			EndGameWidget->SetVisibility(ESlateVisibility::Visible);
			FString gameStatus = GameState->DidPlayerWin() ? "You Won" : "You Lost";
			EndGameWidget->TextBox_GameStatus->SetText(FText::FromString(gameStatus));
		}
		UGameplayStatics::SetGamePaused(GetWorld(), !IsPaused);
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("GAME IS OVER!"));
	}
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

void ARGJPlayerController::OnComplete_PauseGame()
{
	IsPaused = UGameplayStatics::IsGamePaused(GetWorld());
	ARGJHUD* HUD =  Cast<ARGJHUD>(GetHUD());
	URGJPauseWidget* PauseWidget = HUD->GetPauseWidget();
	if (PauseWidget)
	{
		PauseWidget->SetVisibility(ESlateVisibility::Visible);
	}
	UGameplayStatics::SetGamePaused(GetWorld(), !IsPaused);
}

void ARGJPlayerController::OnComplete_ExitGame()
{
	ConsoleCommand("Quit");
}

void ARGJPlayerController::OnComplete_ClickAction()
{
	if (!CursorHit.bBlockingHit) return;

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Clicked!"));

	ARGJ_ShoppingItem* ItemFound = Cast<ARGJ_ShoppingItem>(CursorHit.GetActor());
	if(ItemFound && ItemFound->IsClickable)
	ThisActorHit->Destroy();
	UpdateEndGame();
	
}


