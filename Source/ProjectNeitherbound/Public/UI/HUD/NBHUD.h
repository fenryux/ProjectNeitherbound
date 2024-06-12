// Copyright fenryux

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "NBHUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
struct FWidgetControllerParams;
class UOverlayWidgetController;
class UNBUserWidget;
/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API ANBHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UNBUserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WidgetControllerParams);

	void InitOverlay(const TObjectPtr<APlayerController>& PlayerController, const TObjectPtr<APlayerState>& PlayerState, const TObjectPtr<UAbilitySystemComponent>& AbilitySystemComponent, const TObjectPtr<UAttributeSet>& AttributeSet);

protected:
	void SetOverlayWidgetController(const TObjectPtr<UOverlayWidgetController>& WidgetController);

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UNBUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
};
