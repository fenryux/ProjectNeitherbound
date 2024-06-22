// Copyright fenryux


#include "UI/HUD/NBHUD.h"
#include "UI/Widget/NBUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* ANBHUD::GetOverlayWidgetController(const FWidgetControllerParams& WidgetControllerParams)
{
	if(!OverlayWidgetController)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WidgetControllerParams);

		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}

void ANBHUD::InitOverlay(APlayerController* PlayerController, APlayerState* PlayerState,
                         UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet)
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass uinitialized, fill out Blueprint class"))
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass uinitialized, fill out Blueprint class"))
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UNBUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	
	Widget->AddToViewport();
}

void ANBHUD::SetOverlayWidgetController(UOverlayWidgetController* WidgetController)
{
	this->OverlayWidgetController = WidgetController;
}
