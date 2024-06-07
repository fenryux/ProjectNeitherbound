// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NBEnemyCharacter.h"

#include "GameplayAbilitySystem/NBAbilitySystemComponent.h"
#include "GameplayAbilitySystem/NBAttributeSet.h"


ANBEnemyCharacter::ANBEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UNBAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UNBAttributeSet>("AttributeSet");
}

void ANBEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void ANBEnemyCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ANBEnemyCharacter::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
}

void ANBEnemyCharacter::UnhighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
}
