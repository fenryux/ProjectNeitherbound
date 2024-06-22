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

	void InitOverlay(APlayerController* PlayerController, APlayerState* PlayerState, UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet
	                 * AttributeSet);

protected:
	void SetOverlayWidgetController(UOverlayWidgetController* WidgetController);

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UNBUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
};
