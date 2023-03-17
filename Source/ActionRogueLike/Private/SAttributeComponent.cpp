#include "SAttributeComponent.h"

USAttributeComponent* USAttributeComponent::GetAttributes(AActor* FromActor)
{
	if (FromActor)
	{
		return Cast<USAttributeComponent>(FromActor->GetComponentByClass(USAttributeComponent::StaticClass()));
	}

	return nullptr;
}

bool USAttributeComponent::IsActorAlive(AActor* Actor)
{
	USAttributeComponent* AttributeComp = GetAttributes(Actor);
	if (AttributeComp)
	{
		return AttributeComp->IsAlive();
	}

	return false;
}

USAttributeComponent::USAttributeComponent()
{
	Health = 100.0f;
	HealthMax = 100.0f;
}


bool USAttributeComponent::IsAlive() const
{
	return Health > 0.0f;
}

bool USAttributeComponent::ApplyHealthChange(AActor* InstigatorActor, float Delta)
{
	bool bHealthChanged = false;

	//float NewHealth = Health + Delta;
	float NewHealth = FMath::Clamp(Health + Delta, 0.0f, HealthMax);

	if (NewHealth != Health)
	{
		bHealthChanged = true;
		float ActualDelta = NewHealth - Health;
		Health = NewHealth;
		OnHealthChanged.Broadcast(InstigatorActor, this, HealthMax, Health, ActualDelta);
	}

	return bHealthChanged;
}

float USAttributeComponent::GetHealthFraction()
{
	return Health / HealthMax;
}

bool USAttributeComponent::HealFullHealth()
{
	return ApplyHealthChange(GetOwner(), HealthMax - Health);
}
