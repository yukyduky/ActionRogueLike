#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <SProjectile.h>
#include "SBlackholeProjectile.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASBlackholeProjectile : public ASProjectile
{
	GENERATED_BODY()
	
public:	

	ASBlackholeProjectile();

protected:

	virtual void PostInitializeComponents() override;

public:	

};
