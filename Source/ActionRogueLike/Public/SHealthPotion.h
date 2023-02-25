// Fill out your copyright notice in the Description page of Project Settings.

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

protected:

	

public:
	void Interact_Implementation(APawn* InstigatorPawn);

};
