// Copyright fenryux


#include "UI/WidgetController/OverlayWidgetController.h"

#include "GameplayAbilitySystem/Attributes/NBPlayerAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const TObjectPtr<UNBPlayerAttributeSet> NBAttributeSet = CastChecked<UNBPlayerAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(NBAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(NBAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(NBAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(NBAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const TObjectPtr<UNBPlayerAttributeSet> NBAttributeSet = CastChecked<UNBPlayerAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(NBAttributeSet->GetHealthAttribute())
		.AddUObject(this, &UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(NBAttributeSet->GetMaxHealthAttribute())
		.AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(NBAttributeSet->GetManaAttribute())
		.AddUObject(this, &UOverlayWidgetController::ManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(NBAttributeSet->GetMaxManaAttribute())
		.AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
