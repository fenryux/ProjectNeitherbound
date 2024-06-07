// Copyright fenryux

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "NBAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API UNBAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UNBAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	//~ Begin Resource Attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Resource Attributes");
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UNBAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxHealth, Category="Resource Attributes");
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UNBAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Mana, Category="Resource Attributes");
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UNBAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxMana, Category="Resource Attributes");
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UNBAttributeSet, MaxMana);

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	//~ End Resource Attributes
};
