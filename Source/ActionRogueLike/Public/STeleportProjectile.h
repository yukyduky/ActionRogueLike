#pragma once

#include "CoreMinimal.h"
#include <SProjectile.h>
#include "STeleportProjectile.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASTeleportProjectile : public ASProjectile
{
	GENERATED_BODY()
	
public:	
	ASTeleportProjectile();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float FlyTime;
	UPROPERTY(EditAnywhere)
	float TeleportDelay;

	FTimerHandle TimerHandle_FlyTime;

	void TeleportInstigator();
	virtual void KillProjectile() override;

};
