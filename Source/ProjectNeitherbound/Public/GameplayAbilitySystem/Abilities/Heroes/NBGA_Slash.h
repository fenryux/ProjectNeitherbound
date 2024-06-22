// Copyright fenryux

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySystem/Abilities/NBGameplayAbility.h"
#include "NBGA_Slash.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API UNBGA_Slash : public UNBGameplayAbility
{
	GENERATED_BODY()

public:
	UNBGA_Slash();

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSubclassOf<UGameplayEffect> DamageGameplayEffect;
	
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float Range;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float Damage;

	UFUNCTION()
	void OnCancelled(FGameplayTag EventTag, FGameplayEventData EventData);

	UFUNCTION()
	void OnCompleted(FGameplayTag EventTag, FGameplayEventData EventData);

	UFUNCTION()
	void EventReceived(FGameplayTag EventTag, FGameplayEventData EventData);
};
