#pragma once

#include "CoreMinimal.h"
#include "SConsumable.h"
#include "SHealthPotion.generated.h"


UCLASS()
class ACTIONROGUELIKE_API ASHealthPotion : public ASConsumable
{
	GENERATED_BODY()

public:

	ASHealthPotion();

public:

	void Interact_Implementation(APawn* InstigatorPawn);

};
