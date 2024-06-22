// Copyright fenryux


#include "Character/NBHeroCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/NBPlayerController.h"
#include "Player/NBPlayerState.h"
#include "UI/HUD/NBHUD.h"

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
	AddCharacterAbilities();
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

	if(TObjectPtr<ANBPlayerController> PlayerController = Cast<ANBPlayerController>(GetController()))
		if(ANBHUD* HUD = Cast<ANBHUD>(PlayerController->GetHUD()))
			HUD->InitOverlay(PlayerController, State, AbilitySystemComponent, AttributeSet);

	InitDefaultAttributes();
}

void ANBHeroCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
