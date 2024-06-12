// Copyright fenryux


#include "UI/WidgetController/NBWidgetController.h"

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
