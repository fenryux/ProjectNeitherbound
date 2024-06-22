// Copyright fenryux

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NBPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class ITargetInterface;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API ANBPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ANBPlayerController();

	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> HeroContext;

	void CursorTrace();

	//~ Begin Target Actors 
	ITargetInterface* LastActor;
	ITargetInterface* CurrentActor;
	//~ End Target Actors
};
