// Copyright fenryux


#include "Player/NBPlayerState.h"

#include "GameplayAbilitySystem/NBAbilitySystemComponent.h"
#include "GameplayAbilitySystem/NBAttributeSet.h"

ANBPlayerState::ANBPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UNBAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UNBAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ANBPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
