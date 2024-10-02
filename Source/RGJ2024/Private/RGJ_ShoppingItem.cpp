// Fill out your copyright notice in the Description page of Project Settings.


#include "RGJ_ShoppingItem.h"
#include "Components/WidgetComponent.h"
#include "Components/BoxComponent.h"
#include "HUD/Widget/RGJPriceWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Sound/SoundCue.h"
#include "Game/RGJGameStateBase.h"
#include "Player/RGJPlayerController.h"

// Sets default values
ARGJ_ShoppingItem::ARGJ_ShoppingItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetHidden(true);
	

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh->SetSimulatePhysics(false);
	SetRootComponent(Mesh);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	BoxComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BoxComponent->SetSimulatePhysics(false);
	BoxComponent->SetupAttachment(Mesh);

	PriceWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("PriceWidgetComponent"));
	PriceWidgetComponent->SetupAttachment(Mesh);
	HideWidget();	
}

void ARGJ_ShoppingItem::Destroyed()
{
	IsDestroyed = true;
	if (OnDestorySound)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), OnDestorySound, GetActorLocation());
	}

	if (OnDestoryParticle)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OnDestoryParticle, GetActorTransform());
	}

	ARGJPlayerController* PlayerController = Cast<ARGJPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (PlayerController)
	{
		PlayerController->UpdateEndGame();
	}

	Super::Destroyed();
}

// Called when the game starts or when spawned
void ARGJ_ShoppingItem::BeginPlay()
{
	Super::BeginPlay();
	if (PriceWidgetComponent)
	{
		URGJPriceWidget* PriceWidget = Cast<URGJPriceWidget>(PriceWidgetComponent->GetWidget());
		if(PriceWidget)
			PriceWidget->PriceTextBox->SetText(FText::FromString(FString::SanitizeFloat(Price)));
	}
}

void ARGJ_ShoppingItem::HideWidget()
{
	PriceWidgetComponent->SetVisibility(false);
}

void ARGJ_ShoppingItem::ShowWidget()
{
	PriceWidgetComponent->SetVisibility(true);
}

void ARGJ_ShoppingItem::PlaySpawnSound()
{
	if (OnSpawnSound)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), OnSpawnSound, GetActorLocation());
	}
}

void ARGJ_ShoppingItem::PlaySpawnEmitter()
{
	if (OnSpawnParticle)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OnSpawnParticle, GetActorTransform());
	}
}


