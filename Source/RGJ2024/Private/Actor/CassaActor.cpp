// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/CassaActor.h"
#include "RGJ_ShoppingItem.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/TextBlock.h"
#include "Components/SkeletalMeshComponent.h"
#include "HUD/Widget/RGJPriceWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Game/RGJGameStateBase.h"
#include "HUD/RGJHUD.h"
#include "Player/RGJPlayerController.h"
#include "AnimInstance/CassaAnimInstance.h"

// Sets default values
ACassaActor::ACassaActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Overlap);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	HandMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hand"));
	HandMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	HandMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	HandMesh->SetupAttachment(Mesh);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	BoxCollision->SetupAttachment(Mesh);

	PriceWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("PriceWidgetComponent"));
	PriceWidgetComponent->SetVisibility(true);
	PriceWidgetComponent->SetupAttachment(Mesh);
	UpdatePriceWidget();
}

// Called when the game starts or when spawned
void ACassaActor::BeginPlay()
{
	Super::BeginPlay();
	UpdatePriceWidget();

}

// Called every frame
void ACassaActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TSet<AActor*> OverlappingActor;
	BoxCollision->GetOverlappingActors(OverlappingActor);

	for (auto Actor : OverlappingActor)
	{
		ARGJ_ShoppingItem* ShoppingItem = Cast< ARGJ_ShoppingItem>(Actor);
		if (ShoppingItem && !ShoppingItem->PriceAdded && !ShoppingItem->IsDestroyed)
		{
			ARGJGameStateBase* GameState = Cast<ARGJGameStateBase>(UGameplayStatics::GetGameState(GetWorld()));

			if (GameState)
			{
				GameState->CurretMoneyValue += ShoppingItem->GetPrice();
				PriceSum = GameState->CurretMoneyValue;
				UpdatePriceWidget();
				ShoppingItem->PriceAdded = true;
				UCassaAnimInstance* animInstance = Cast<UCassaAnimInstance>(HandMesh->GetAnimInstance());
				animInstance->ItemsToGrab.Add(ShoppingItem);
				//prendo l'anim instance e aggiungo i prodotti 
				//Eseguo il montage
				//Eseguo il notify che mi distrugge tutto ed attacca i socket
				PlayGrabMontage();
			}
		}
	}
}

void ACassaActor::UpdatePriceWidget()
{
	if (PriceWidgetComponent)
	{
		URGJPriceWidget* PriceWidget = Cast<URGJPriceWidget>(PriceWidgetComponent->GetWidget());
		if (PriceWidget)
		{
			UTextBlock* TextBlock = PriceWidget->PriceTextBox;
			if (TextBlock)
			{
				TextBlock->SetText(FText::FromString(FString::SanitizeFloat(PriceSum)));
			}
		}
	}
}

void ACassaActor::PlayGrabMontage()
{
	UAnimInstance* AnimInstance = HandMesh->GetAnimInstance();
	if (AnimInstance)
	{
		if (OnGrabMontage)
		{
			AnimInstance->Montage_Play(OnGrabMontage);
		}
	}
}

