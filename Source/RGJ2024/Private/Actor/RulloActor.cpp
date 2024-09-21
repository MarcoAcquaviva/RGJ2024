// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/RulloActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "RGJ_ShoppingItem.h"
#include "Components/BoxComponent.h"
#include "Game/RGJGameStateBase.h"
#include "TimeManagementClasses.h"

// Sets default values
ARulloActor::ARulloActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SetRootComponent(Mesh);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

}

// Called when the game starts or when spawned
void ARulloActor::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle MemberTimerHandle;
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ARulloActor::SpawnShopItem, 1.0f, true, 2.0f);
		
}

void ARulloActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	ARGJGameStateBase* GameState = Cast<ARGJGameStateBase>(UGameplayStatics::GetGameState(GetWorld()));
	if (GameState && !AreItemSpawned)
	{
		while (GameState->AllShopItems.Num() < GameState->NumberOfItemToSpawn)
		{
			InitRandomObject();
		}
		AreItemSpawned = true;
	}
}



void ARulloActor::InitRandomObject()
{
	int maxIndex = ObjectsToSpawn.Num();
	int randomIndex = UKismetMathLibrary::RandomInteger(maxIndex);
	TSubclassOf<ARGJ_ShoppingItem> ObjectToSpawn = ObjectsToSpawn[randomIndex];
	
	FActorSpawnParameters SpawnInfo;

	ARGJ_ShoppingItem* ItemSpawned = GetWorld()->SpawnActorDeferred<ARGJ_ShoppingItem>(ObjectToSpawn, GetSpawnTransform());
	ARGJGameStateBase* GameState = Cast<ARGJGameStateBase>(UGameplayStatics::GetGameState(GetWorld()));
	if (GameState)
	{
		GameState->AllShopItems.Add(ItemSpawned);
		if (GameState->AllShopItems.Num() >= GameState->NumberOfItemToSpawn)
			GetWorldTimerManager().ClearTimer(SpawnItemHandler);
	}

}

void ARulloActor::SpawnShopItem()
{
	ARGJGameStateBase* GameState = Cast<ARGJGameStateBase>(UGameplayStatics::GetGameState(GetWorld()));
	if (GameState)
	{
		if (GameState->SpawnCounter >= GameState->NumberOfItemToSpawn)
		{
			GetWorldTimerManager().ClearTimer(SpawnItemHandler);
			return;
		}
		ARGJ_ShoppingItem* ObjectToSpawn = GameState->AllShopItems[GameState->SpawnCounter];
		ObjectToSpawn->FinishSpawning(GetSpawnTransform());
		ObjectToSpawn->SetHidden(false);
		GameState->SpawnCounter++;
	}
}

FTransform ARulloActor::GetSpawnTransform()
{
	FVector SpawnPoint = Mesh->GetSocketLocation("SpawnPoint");
	FRotator SpawnRotation(0, 0, 0);
	FTransform SpawnTransform;
	SpawnTransform.SetLocation(SpawnPoint);
	SpawnTransform.SetRotation(SpawnRotation.Quaternion());
	return SpawnTransform;
}




