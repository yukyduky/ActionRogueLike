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
	RespawnTime = 3.0f;

	bIsActive = true;
}

// Called when the game starts or when spawned
void ASConsumable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASConsumable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASConsumable::TimeOut()
{
	GetWorldTimerManager().SetTimer(TimerHandle_TimeOut, this, &ASConsumable::ShowConsumable, RespawnTime);
	SetConsumableState(false);
}

void ASConsumable::ShowConsumable()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_TimeOut);
	SetConsumableState(true);
}

void ASConsumable::SetConsumableState(bool isActive)
{
	this->bIsActive = isActive;
	RootComponent->SetVisibility(bIsActive, true);
	SetActorEnableCollision(bIsActive);
}

bool ASConsumable::IsActive()
{
	return bIsActive;
}

