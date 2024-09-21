// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/RGJPawn.h"

// Sets default values
ARGJPawn::ARGJPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARGJPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARGJPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


