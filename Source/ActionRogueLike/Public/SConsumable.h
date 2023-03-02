// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGameplayInterface.h"
#include "SConsumable.generated.h"

class UStaticMeshComponent;
class USAttributeComponent;

UCLASS(ABSTRACT)
class ACTIONROGUELIKE_API ASConsumable : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASConsumable();

private:
	bool bIsActive;

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditAnywhere, Category = "Consumable")
	float StatAmount;

	UPROPERTY(EditAnywhere, Category = "Consumable")
	float RespawnTime;

	FTimerHandle TimerHandle_TimeOut;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void TimeOut();
	void ShowConsumable();
	void SetConsumableState(bool isActive);
	bool IsActive();

};
