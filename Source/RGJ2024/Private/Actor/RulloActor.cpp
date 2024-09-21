// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/RulloActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "RGJ_ShoppingItem.h"
#include "Components/BoxComponent.h"

// Sets default values
ARulloActor::ARulloActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

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
	GetWorldTimerManager().SetTimer(SpawnItemHandler,this, &ARulloActor::SpawnRandomObject, 1, true);
}

void ARulloActor::SpawnRandomObject()
{
	int maxIndex = ObjectsToSpawn.Num();
	int randomIndex = UKismetMathLibrary::RandomInteger(maxIndex);
	TSubclassOf<ARGJ_ShoppingItem> ObjectToSpawn = ObjectsToSpawn[randomIndex];
	FVector SpawnPoint = Mesh->GetSocketLocation("SpawnPoint"); 
	FRotator SpawnRotation(0, 0, 0);
	FActorSpawnParameters SpawnInfo;

	GetWorld()->SpawnActor<ARGJ_ShoppingItem>(ObjectToSpawn, SpawnPoint, SpawnRotation, SpawnInfo);
	SpawnCounter++;
	if (SpawnCounter >= NumberOfItemToSpawn)
		GetWorldTimerManager().ClearTimer(SpawnItemHandler);
}



