// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/CarrelloActor.h"
#include "Components/StaticMeshComponent.h"
#include "Game/RGJGameModeBase.h"
#include "Game/RGJGameStateBase.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ACarrelloActor::ACarrelloActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LayerUno = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LayerUno"));
	LayerUno->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	LayerUno->SetSimulatePhysics(false);
	LayerDue = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LayerDue"));
	LayerDue->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	LayerDue->SetSimulatePhysics(false);
	LayerDue->bHiddenInGame = true;
	LayerDue->AttachToComponent(LayerUno, FAttachmentTransformRules::KeepWorldTransform);
	LayerTre = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LayerTre"));
	LayerTre->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	LayerTre->SetSimulatePhysics(false);
	LayerTre->bHiddenInGame = true;
	LayerTre->AttachToComponent(LayerUno,FAttachmentTransformRules::KeepWorldTransform);
}

// Called when the game starts or when spawned
void ACarrelloActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACarrelloActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	GameState = GameState == nullptr? Cast<ARGJGameStateBase>(UGameplayStatics::GetGameState(GetWorld())): GameState;
	int OneThird = GameState->NumberOfItemToSpawn  / 3;
	float moduleOfOneThird = GameState->SpawnCounter % OneThird;
	if (moduleOfOneThird == 0)
	{
		if (GameState->SpawnCounter <= OneThird)
		{
			LayerUno->bHiddenInGame = true;
			LayerDue->bHiddenInGame = false ;
		}
		else if (GameState->SpawnCounter >= (OneThird * 2) && GameState->SpawnCounter <= (OneThird * 3))
		{
			LayerDue->bHiddenInGame = true;
			LayerTre->bHiddenInGame = false;
		}
		else if (GameState->SpawnCounter >= (OneThird * 3))
		{
			LayerTre->bHiddenInGame = true;
		}
	}
	

}

