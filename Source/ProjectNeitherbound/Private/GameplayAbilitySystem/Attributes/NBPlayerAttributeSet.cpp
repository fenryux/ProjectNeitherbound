// Copyright fenryux


#include "GameplayAbilitySystem/Attributes/NBPlayerAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UNBPlayerAttributeSet::UNBPlayerAttributeSet()
{
}

void UNBPlayerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//~ Begin Resource Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UNBPlayerAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNBPlayerAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNBPlayerAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNBPlayerAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	//~ End Resource Attributes

	//~ Begin Combat Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UNBPlayerAttributeSet, AttackRange, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNBPlayerAttributeSet, CriticalStrikeChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNBPlayerAttributeSet, CriticalStrikeMultiplier, COND_None, REPNOTIFY_Always);
	//~ End Combat Attributes

	//~ Begin Movement Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UNBPlayerAttributeSet, MovementSpeed, COND_None, REPNOTIFY_Always);
	//~ End Movement Attributes
}

void UNBPlayerAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if(Attribute == GetHealthAttribute())
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	if(Attribute == GetManaAttribute())
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
}

void UNBPlayerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if(Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
	if(Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}
}

void UNBPlayerAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBPlayerAttributeSet, Health, OldHealth);
}

void UNBPlayerAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBPlayerAttributeSet, MaxHealth, OldMaxHealth);
}

void UNBPlayerAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBPlayerAttributeSet, Mana, OldMana);
}

void UNBPlayerAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBPlayerAttributeSet, MaxMana, OldMaxMana);
}

void UNBPlayerAttributeSet::OnRep_AttackRange(const FGameplayAttributeData& OldAttackRange) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBPlayerAttributeSet, AttackRange, OldAttackRange);
}

void UNBPlayerAttributeSet::OnRep_CriticalStrikeChance(const FGameplayAttributeData& OldCriticalStrikeChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBPlayerAttributeSet, CriticalStrikeChance, OldCriticalStrikeChance);
}

void UNBPlayerAttributeSet::OnRep_CriticalStrikeMultiplier(const FGameplayAttributeData& OldCriticalStrikeMultiplier) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBPlayerAttributeSet, CriticalStrikeMultiplier, OldCriticalStrikeMultiplier);
}

void UNBPlayerAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBPlayerAttributeSet, MovementSpeed, OldMovementSpeed);
}

