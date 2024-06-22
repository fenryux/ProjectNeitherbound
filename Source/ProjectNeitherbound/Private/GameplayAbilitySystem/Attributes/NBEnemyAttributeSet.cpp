// Copyright fenryux


#include "GameplayAbilitySystem/Attributes/NBEnemyAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UNBEnemyAttributeSet::UNBEnemyAttributeSet()
{
}

void UNBEnemyAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//~ Begin Resource Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UNBEnemyAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNBEnemyAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	//~ End Resource Attributes

	//~ Begin Combat Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UNBEnemyAttributeSet, AttackRange, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNBEnemyAttributeSet, MovementSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNBEnemyAttributeSet, EnemyLevel, COND_None, REPNOTIFY_Always);
	//~ End Combat Attributes
}

void UNBEnemyAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if(Attribute == GetHealthAttribute())
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
}

void UNBEnemyAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if(Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
}

void UNBEnemyAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBEnemyAttributeSet, Health, OldHealth);
}

void UNBEnemyAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBEnemyAttributeSet, Health, OldMaxHealth);
}

void UNBEnemyAttributeSet::OnRep_AttackRange(const FGameplayAttributeData& OldAttackRange) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBEnemyAttributeSet, Health, OldAttackRange);
}

void UNBEnemyAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBEnemyAttributeSet, Health, OldMovementSpeed);
}

void UNBEnemyAttributeSet::OnRep_EnemyLevel(const FGameplayAttributeData& OldEnemyLevel) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNBEnemyAttributeSet, Health, OldEnemyLevel);
}

