#include "SBlackholeProjectile.h"
#include "Components/SphereComponent.h"

ASBlackholeProjectile::ASBlackholeProjectile()
{

}

void ASBlackholeProjectile::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SphereComp->OnComponentHit.Clear();
}
