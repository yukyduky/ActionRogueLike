#include "SAttributeComponent.h"

USAttributeComponent::USAttributeComponent()
{
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
