// Fill out your copyright notice in the Description page of Project Settings.


#include "RGJ_ShoppingItem.h"
#include "Components/WidgetComponent.h"
#include "HUD/Widget/RGJPriceWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Sound/SoundCue.h"

// Sets default values
ARGJ_ShoppingItem::ARGJ_ShoppingItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetHidden(true);
	

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetSimulatePhysics(false);
	SetRootComponent(Mesh);

	PriceWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("PriceWidgetComponent"));
	PriceWidgetComponent->AttachToComponent(Mesh, FAttachmentTransformRules::KeepWorldTransform);
	HideWidget();	
}

void ARGJ_ShoppingItem::Destroyed()
{
	IsDestroyed = true;
	if (OnDestorySound)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), OnDestorySound, GetActorLocation());
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


