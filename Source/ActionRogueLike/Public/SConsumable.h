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

public:	

	void TimeOut();
	void ShowConsumable();
	void SetConsumableState(bool isActive);
	bool IsActive();

};
