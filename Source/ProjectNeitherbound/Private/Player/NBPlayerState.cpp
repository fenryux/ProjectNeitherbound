// Copyright fenryux


#include "Player/NBPlayerState.h"

#include "GameplayAbilitySystem/NBAbilitySystemComponent.h"
#include "GameplayAbilitySystem/Attributes/NBPlayerAttributeSet.h"

ANBPlayerState::ANBPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UNBAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UNBPlayerAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ANBPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
