// Copyright fenryux

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NBUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API UNBUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
	
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
