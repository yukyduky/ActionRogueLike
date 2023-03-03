#include "SConsumable.h"
#include "Components/StaticMeshComponent.h"
#include <SCharacter.h>

ASConsumable::ASConsumable()
{
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;
	BaseMesh->SetCollisionProfileName("Consumable");

	StatAmount = 0.0f;
	RespawnTime = 3.0f;

	bIsActive = true;
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

