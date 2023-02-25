// Fill out your copyright notice in the Description page of Project Settings.


#include "SConsumable.h"
#include "Components/StaticMeshComponent.h"
#include <SCharacter.h>

// Sets default values
ASConsumable::ASConsumable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;
	BaseMesh->SetCollisionProfileName("Consumable");

	StatAmount = 0.0f;
}

// Called when the game starts or when spawned
void ASConsumable::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASConsumable::TimeOut_TimeElasped()
{

}

// Called every frame
void ASConsumable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASConsumable::TimeOut(float AmountOfSeconds)
{
	//GetWorldTimerManager().SetTimer(TimerHandle_TimeOut, this, &ASConsumable::TimeOut_TimeElasped, 0.2f);
	GetWorldTimerManager().SetTimer(TimerHandle_TimeOut, this, &ASConsumable::ShowConsumable, AmountOfSeconds);
	BaseMesh->SetVisibility(false);
}

void ASConsumable::ShowConsumable()
{
	BaseMesh->SetVisibility(true);
}


