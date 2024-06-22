// Copyright fenryux

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ProjectNeitherbound/ProjectNeitherbound.h"
#include "NBGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API UNBGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UNBGameplayAbility();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Ability")
	ENBAbilityInputID AbilityInputID = ENBAbilityInputID::None;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Ability")
	ENBAbilityInputID AbilityID = ENBAbilityInputID::None;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Ability")
	bool ActivateAbilityOnGranted = false;

	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	
};
