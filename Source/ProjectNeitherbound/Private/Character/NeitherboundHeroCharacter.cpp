// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NeitherboundHeroCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ANeitherboundHeroCharacter::ANeitherboundHeroCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate              = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane         = true;
	GetCharacterMovement()->bSnapToPlaneAtStart       = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll  = false;
	bUseControllerRotationYaw   = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-45.f, 180.f, 0.f));
	CameraBoom->bDoCollisionTest = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;
	
	PrimaryActorTick.bCanEverTick          = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ANeitherboundHeroCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
