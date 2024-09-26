// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/CassaAnimInstance.h"
#include "RGJ_ShoppingItem.h"
#include "Actor/CassaActor.h"

void UCassaAnimInstance::NativeInitializeAnimation()
{
	Cassa = Cast<ACassaActor>(GetOwningActor());
}

void UCassaAnimInstance::OnGrab_Montage()
{
	TArray<ARGJ_ShoppingItem*> localItemsToGrab = ItemsToGrab;
	for (auto item : localItemsToGrab)
	{
		ItemsToGrab.Remove(item);
		item->AttachToActor(Cassa, FAttachmentTransformRules::KeepWorldTransform, "GrabSokect");
		item->Destroy();
	}
}
