#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "SBTService_CheckLowHealth.generated.h"

class USAttributeComponent;

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API USBTService_CheckLowHealth : public UBTService
{
	GENERATED_BODY()
	
protected:

	USBTService_CheckLowHealth();

	FTimerHandle TimerHandle_SeekCover;

	UPROPERTY(EditAnywhere, Category = "AI");
	float TimeUntilCanSeekCoverAgain;

	UPROPERTY(EditAnywhere, Category = "AI");
	FBlackboardKeySelector SeekCoverKey;

	UPROPERTY(EditAnywhere, Category = "AI");
	float LowHealthFraction;


	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

};
