#include "SHealthPotion.h"
#include <SCharacter.h>
#include "Components/StaticMeshComponent.h"
#include <SAttributeComponent.h>


ASHealthPotion::ASHealthPotion()
{
	StatAmount = 20.0f;
}


void ASHealthPotion::Interact_Implementation(APawn* InstigatorPawn)
{
	if (IsActive() && ensure(InstigatorPawn))
	{
		USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(InstigatorPawn->GetComponentByClass(USAttributeComponent::StaticClass()));
		if (AttributeComp)
		{
			if (AttributeComp->ApplyHealthChange(this, StatAmount))
			{
				TimeOut();
			}
		}
	}
}