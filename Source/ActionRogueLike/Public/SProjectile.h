#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SProjectile.generated.h"

class USphereComponent;
class UParticleSystemComponent;
class UProjectileMovementComponent;
class UAudioComponent;

UCLASS(ABSTRACT)
class ACTIONROGUELIKE_API ASProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ASProjectile();



protected:
	virtual void PostInitializeComponents() override;

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* DeathEffect;

	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* CastEffect;

	UPROPERTY(EditAnywhere, Category = "Effects")
	TSubclassOf<UCameraShakeBase> ShakeEffect;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UParticleSystemComponent* EffectComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UProjectileMovementComponent* MovementComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* AudioComp;

	UPROPERTY(EditAnywhere, Category = "Sound");
	USoundBase* ImpactSound;

	virtual void KillProjectile();

	UFUNCTION()
	virtual void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
