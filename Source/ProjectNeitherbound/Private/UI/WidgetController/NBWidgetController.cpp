// Copyright fenryux


#include "UI/WidgetController/NBWidgetController.h"


FWidgetControllerParams::FWidgetControllerParams(APlayerController* PlayerController, APlayerState* PlayerState,
	UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet)
: PlayerController(PlayerController), PlayerState(PlayerState), AbilitySystemComponent(AbilitySystemComponent), AttributeSet(AttributeSet)
{
}

void UNBWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WidgetControllerParams)
{
	PlayerController       = WidgetControllerParams.PlayerController;
	PlayerState            = WidgetControllerParams.PlayerState;
	AbilitySystemComponent = WidgetControllerParams.AbilitySystemComponent;
	AttributeSet           = WidgetControllerParams.AttributeSet;
}

void UNBWidgetController::BroadcastInitialValues()
{ }

void UNBWidgetController::BindCallbacksToDependencies()
{ }
