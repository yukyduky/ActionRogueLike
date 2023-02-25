// Fill out your copyright notice in the Description page of Project Settings.


#include "SHealthPotion.h"
#include <SCharacter.h>
#include "Components/StaticMeshComponent.h"
#include <SAttributeComponent.h>


ASHealthPotion::ASHealthPotion()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StatAmount = 20.0f;
}


void ASHealthPotion::Interact_Implementation(APawn* InstigatorPawn)
{
	if (BaseMesh->IsVisible() && ensure(InstigatorPawn))
	{
		ASCharacter* InstigatorCharacter = Cast<ASCharacter>(InstigatorPawn);

		if (InstigatorCharacter->ApplyConsumable(ATTRIBUTE::HEALTH, StatAmount))
		{
			TimeOut(3.0f);
		}
	}
}