// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SBTService_CheckLowHealth.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "SAttributeComponent.h"


USBTService_CheckLowHealth::USBTService_CheckLowHealth()
{
	LowHealthFraction = 0.3f;
	TimeUntilCanSeekCoverAgain = 60.0f;
}

void USBTService_CheckLowHealth::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if (!GetWorld()->GetTimerManager().IsTimerActive(TimerHandle_SeekCover))
	{
		UBlackboardComponent* BlackBoardComp = OwnerComp.GetBlackboardComponent();
		if (ensure(BlackBoardComp))
		{
			float CurrentHealth = BlackBoardComp->GetValueAsFloat("CurrentHealth");
			float MaxHealth = BlackBoardComp->GetValueAsFloat("MaxHealth");

			AAIController* MyController = OwnerComp.GetAIOwner();
			if (ensure(MyController))
			{
				APawn* AIPawn = MyController->GetPawn();
				if (ensure(AIPawn))
				{
					USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(AIPawn->GetComponentByClass(USAttributeComponent::StaticClass()));

					bool bSeekCover = AttributeComp->GetHealthFraction() < LowHealthFraction;

					BlackBoardComp->SetValueAsBool(SeekCoverKey.SelectedKeyName, bSeekCover);

					if (bSeekCover)
					{
						GetWorld()->GetTimerManager().SetTimer(TimerHandle_SeekCover, TimeUntilCanSeekCoverAgain, false, 0.0f);
					}
				}
			}
		}
	}
}
