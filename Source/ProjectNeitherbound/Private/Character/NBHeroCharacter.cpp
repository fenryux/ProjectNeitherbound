// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NBHeroCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/NBPlayerState.h"

ANBHeroCharacter::ANBHeroCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate              = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane         = true;
	GetCharacterMovement()->bSnapToPlaneAtStart       = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll  = false;
	bUseControllerRotationYaw   = false;

	PrimaryActorTick.bCanEverTick          = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ANBHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//Server-side
	InitAbilityActorInfo();
}

void ANBHeroCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Client-side
	InitAbilityActorInfo();
}

void ANBHeroCharacter::InitAbilityActorInfo()
{
	ANBPlayerState* State = GetPlayerState<ANBPlayerState>();
	check(State);
	
	AbilitySystemComponent = State->GetAbilitySystemComponent();
	AttributeSet           = State->GetAttributeSet();

	AbilitySystemComponent->InitAbilityActorInfo(State, this);
}

void ANBHeroCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
