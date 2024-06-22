// Copyright fenryux

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "NBAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API UNBAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities);
};
