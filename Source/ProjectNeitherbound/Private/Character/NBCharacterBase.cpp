// Copyright fenryux


#include "Character/NBCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "GameplayAbilitySystem/NBAbilitySystemComponent.h"

// Sets default values
ANBCharacterBase::ANBCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

UAbilitySystemComponent* ANBCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ANBCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ANBCharacterBase::InitDefaultAttributes() const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(DefaultAttributes);

	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultAttributes, 1.f, ContextHandle);

	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void ANBCharacterBase::AddCharacterAbilities()
{
	UNBAbilitySystemComponent* NbASC = CastChecked<UNBAbilitySystemComponent>(AbilitySystemComponent);

	if(!HasAuthority())
		return;

	NbASC->AddCharacterAbilities(StartupAbilities);
}
