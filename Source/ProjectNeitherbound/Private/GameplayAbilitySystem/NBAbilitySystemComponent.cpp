// Copyright fenryux


#include "GameplayAbilitySystem/NBAbilitySystemComponent.h"

void UNBAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for(const auto AbilityClass : StartupAbilities)
	{
		auto AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		GiveAbilityAndActivateOnce(AbilitySpec);
	}
}
