// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/RGJPawn.h"
#include "Components/SkeletalMeshComponent.h"


// Sets default values
ARGJPawn::ARGJPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeleton Mese"));
	SkeletonMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SkeletonMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	
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

void ARGJPawn::PlayMontage()
{
	 UAnimInstance* AnimInstance =  SkeletonMesh->GetAnimInstance();
	if (OnGrabMontage && AnimInstance)
	{
		AnimInstance->Montage_Play(OnGrabMontage);
	}
}

void ARGJPawn::SetHandPosition(FVector NewPosition)
{
	if (SkeletonMesh)
	{
		SkeletonMesh->SetWorldLocation(NewPosition);
	}
}


