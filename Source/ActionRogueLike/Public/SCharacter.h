#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USInteractionComponent;
class ASProjectile;
class USAttributeComponent;

enum ATTRIBUTE;

UCLASS()
class ACTIONROGUELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, Category = "Utility")
	TSubclassOf<ASProjectile> UtilityProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<ASProjectile> PrimaryProjectileClass;	

	UPROPERTY(EditAnywhere, Category = "Attack")
	UAnimMontage* AttackAnim;

	UPROPERTY(EditAnywhere, Category = "Ultimate")
	TSubclassOf<ASProjectile> UltimateProjectileClass;

	FTimerHandle TimerHandle_PrimaryAttack;


public:

	ASCharacter();

protected:

	virtual void PostInitializeComponents();

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	USInteractionComponent* InteractionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attribute")
	USAttributeComponent* AttributeComp;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void MoveJump();

	void PrimaryAttack_TimeElasped();
	void PrimaryAttack();
	void Teleport_TimeElasped();
	void Teleport();
	void Blackhole_TimeElasped();
	void Blackhole();
	void PrimaryInteract();

	void SpawnProjectile(TSubclassOf<ASProjectile> ClassToSpawn);

	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComp, float HealthMax, float NewHealth, float Delta);


public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
