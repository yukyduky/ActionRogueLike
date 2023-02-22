// Fill out your copyright notice in the Description page of Project Settings.


#include "STeleportProjectile.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "DrawDebugHelpers.h"


// Sets default values
ASTeleportProjectile::ASTeleportProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	FlyTime = 0.2f;
	TeleportDelay = 0.2f;
	bFlying = true;
}

// Called when the game starts or when spawned
void ASTeleportProjectile::BeginPlay()
{
	Super::BeginPlay();

	SphereComp->IgnoreActorWhenMoving(GetInstigator(), true);
}

void ASTeleportProjectile::Teleport()
{
	APawn* instigator = GetInstigator();
	instigator->TeleportTo(this->GetActorLocation(), instigator->GetActorRotation());
	this->Destroy();
}

void ASTeleportProjectile::KillProjectile()
{
	DeathEffectComp->Activate();
	MovementComp->StopMovementImmediately();
	EffectComp->Deactivate();
	bFlying = false;
}

// Called every frame
void ASTeleportProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FlyTime -= DeltaTime;

	if (FlyTime <= 0.0f && bFlying)
	{
		KillProjectile();
	}
	else if (!bFlying)
	{
		TeleportDelay -= DeltaTime;

		if (TeleportDelay <= 0.0f)
		{
			Teleport();
		}
	}
}

