// Fill out your copyright notice in the Description page of Project Settings.


#include "STeleportProjectile.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ASTeleportProjectile::ASTeleportProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	FlyTime = 0.2f;
	TeleportDelay = 0.2f;
}

// Called when the game starts or when spawned
void ASTeleportProjectile::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle_FlyTime, this, &ASTeleportProjectile::KillProjectile, FlyTime);
}

void ASTeleportProjectile::TeleportInstigator()
{
	APawn* ActorToTeleport = GetInstigator();
	if (ensure(ActorToTeleport))
	{
		ActorToTeleport->TeleportTo(this->GetActorLocation(), ActorToTeleport->GetActorRotation(), false, false);
		this->Destroy();
	}
}

void ASTeleportProjectile::KillProjectile()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_FlyTime);

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DeathEffect, GetActorLocation());
	MovementComp->StopMovementImmediately();
	SetActorEnableCollision(false);
	EffectComp->DeactivateSystem();

	FTimerHandle TimerHandle_TeleportDelay;
	GetWorldTimerManager().SetTimer(TimerHandle_TeleportDelay, this, &ASTeleportProjectile::TeleportInstigator, TeleportDelay);
}

