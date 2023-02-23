// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <SProjectile.h>
#include "STeleportProjectile.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASTeleportProjectile : public ASProjectile
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASTeleportProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float FlyTime;
	UPROPERTY(EditAnywhere)
	float TeleportDelay;

	FTimerHandle TimerHandle_FlyTime;

	void TeleportInstigator();
	virtual void KillProjectile() override;

};
