// Fill out your copyright notice in the Description page of Project Settings.


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
			CurrentActor->HighlightActor();
	}
	else
	{
		if(!CurrentActor)
			LastActor->UnhighlightActor();
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

void ANBPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ANBPlayerController::Move);
}

void ANBPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector  = InputActionValue.Get<FVector2d>();
	const FRotator  Rotation         = GetControlRotation();
	
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector  ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector  RightDirection   = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<ANBHeroCharacter>())
	{
		ControlledPawn->FaceRotation(YawRotation);
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection,   InputAxisVector.X);
	}
}