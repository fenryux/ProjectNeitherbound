// Copyright fenryux


#include "Player/NBPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Character/NBHeroCharacter.h"
#include "Interface/TargetInterface.h"

ANBPlayerController::ANBPlayerController()
{
	bReplicates = true;
}

void ANBPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void ANBPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);

	if(!CursorHit.bBlockingHit)
		return;

	LastActor    = CurrentActor;
	CurrentActor = Cast<ITargetInterface>(CursorHit.GetActor());

	if(!LastActor)
	{
		if(CurrentActor)
		{
			CurrentActor->HighlightActor();
		}
	}
	else
	{
		if(!CurrentActor)
		{
			LastActor->UnhighlightActor();
		}
		else if(LastActor != CurrentActor)
		{
			LastActor->UnhighlightActor();
			CurrentActor->HighlightActor();
		}
	}
}

void ANBPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(HeroContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(Subsystem)
		Subsystem->AddMappingContext(HeroContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Type::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}