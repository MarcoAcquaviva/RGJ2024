// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/CassaActor.h"
#include "Components/BoxComponent.h"
#include "RGJ_ShoppingItem.h"
#include "Components/WidgetComponent.h"
#include "HUD/Widget/RGJPriceWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Game/RGJGameStateBase.h"

// Sets default values
ACassaActor::ACassaActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Overlap);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	BoxCollision->AttachToComponent(Mesh, FAttachmentTransformRules::KeepWorldTransform);

	PriceWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("PriceWidgetComponent"));
	PriceWidgetComponent->SetVisibility(true);
	PriceWidgetComponent->AttachToComponent(Mesh, FAttachmentTransformRules::KeepWorldTransform);
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
				//TODO: Aggiungere montage con evento a cui legarsi per ditruggere l'oggetto
				ShoppingItem->Destroyed();

				if (GameState->CheckIfGameEnded())
				{
					if (GEngine)
						GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("GAME IS OVER!"));
				}
			}
		}
	}
}

void ACassaActor::UpdatePriceWidget()
{
	if (PriceWidgetComponent)
	{
		URGJPriceWidget* PriceWidget = Cast< URGJPriceWidget>(PriceWidgetComponent->GetWidget());
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

