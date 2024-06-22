// Copyright fenryux

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "NBPlayerAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API UNBPlayerAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UNBPlayerAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/*
	 * Gameplay Effects application handling, like clamping changed Health to Max Health, etc. 
	 */
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	//~ Begin Vitality Attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Vitality Attributes");
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UNBPlayerAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxHealth, Category="Vitality Attributes");
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UNBPlayerAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Mana, Category="Vitality Attributes");
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UNBPlayerAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxMana, Category="Vitality Attributes");
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UNBPlayerAttributeSet, MaxMana);
	//~ End Vitality Attributes

	//~ Begin Combat Attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_AttackRange, Category = "Combat Attributes");
	FGameplayAttributeData AttackRange;
	ATTRIBUTE_ACCESSORS(UNBPlayerAttributeSet, AttackRange);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CriticalStrikeChance, Category = "Combat Attributes");
	FGameplayAttributeData CriticalStrikeChance;
	ATTRIBUTE_ACCESSORS(UNBPlayerAttributeSet, CriticalStrikeChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CriticalStrikeMultiplier, Category = "Combat Attributes");
	FGameplayAttributeData CriticalStrikeMultiplier;
	ATTRIBUTE_ACCESSORS(UNBPlayerAttributeSet, CriticalStrikeMultiplier);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MovementSpeed, Category = "Combat Attributes");
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UNBPlayerAttributeSet, MovementSpeed);
	//~ End Combat Attributes

protected:
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	UFUNCTION()
	void OnRep_AttackRange(const FGameplayAttributeData& OldAttackRange) const;
	
	UFUNCTION()
	void OnRep_CriticalStrikeChance(const FGameplayAttributeData& OldCriticalStrikeChance) const;

	UFUNCTION()
	void OnRep_CriticalStrikeMultiplier(const FGameplayAttributeData& OldCriticalStrikeMultiplier) const;

	UFUNCTION()
	void OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed) const;
};
