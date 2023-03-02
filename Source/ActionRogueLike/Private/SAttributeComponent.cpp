// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttributeComponent.h"

// Sets default values for this component's properties
USAttributeComponent::USAttributeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	Health = 100.0f;
	HealthMax = 100.0f;
}


bool USAttributeComponent::IsAlive() const
{
	return Health > 0.0f;
}

bool USAttributeComponent::ApplyHealthChange(float Delta)
{
	bool bHealthChanged = false;

	//float NewHealth = Health + Delta;
	float NewHealth = FMath::Clamp(Health + Delta, 0.0f, HealthMax);

	if (NewHealth != Health)
	{
		bHealthChanged = true;
		float ActualDelta = NewHealth - Health;
		Health = NewHealth;
		OnHealthChanged.Broadcast(nullptr, this, HealthMax, Health, ActualDelta);
	}

	return bHealthChanged;
}

float USAttributeComponent::GetHealthFraction()
{
	return Health / HealthMax;
}

bool USAttributeComponent::HealFullHealth()
{
	return ApplyHealthChange(HealthMax - Health);
}
