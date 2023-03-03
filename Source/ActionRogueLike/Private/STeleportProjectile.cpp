#include "STeleportProjectile.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"


ASTeleportProjectile::ASTeleportProjectile()
{
	FlyTime = 0.2f;
	TeleportDelay = 0.2f;
}

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
