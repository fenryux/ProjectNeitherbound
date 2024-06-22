// Copyright fenryux

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "NBEnemyAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API UNBEnemyAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UNBEnemyAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Gameplay Effect application handling, like clamping changed Health to Max Health, etc.
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	//~ Begin Vitality Attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Vitality Attributes");
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UNBEnemyAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxHealth, Category="Vitality Attributes");
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UNBEnemyAttributeSet, MaxHealth);
	//~ End Vitality Attributes

	//~ Begin Combat Attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_AttackRange, Category = "Combat Attributes");
	FGameplayAttributeData AttackRange;
	ATTRIBUTE_ACCESSORS(UNBEnemyAttributeSet, AttackRange);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MovementSpeed, Category = "Combat Attributes");
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UNBEnemyAttributeSet, MovementSpeed);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_EnemyLevel, Category = "Combat Attributes");
	FGameplayAttributeData EnemyLevel;
	ATTRIBUTE_ACCESSORS(UNBEnemyAttributeSet, EnemyLevel);
	//~ End Combat Attributes
	
protected:
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_AttackRange(const FGameplayAttributeData& OldAttackRange) const;

	UFUNCTION()
	void OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed) const;
	
	UFUNCTION()
	void OnRep_EnemyLevel(const FGameplayAttributeData& OldEnemyLevel) const;
};
