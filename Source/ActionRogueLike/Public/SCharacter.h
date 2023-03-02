// Fill out your copyright notice in the Description page of Project Settings.

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
	// Sets default values for this character's properties
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

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
