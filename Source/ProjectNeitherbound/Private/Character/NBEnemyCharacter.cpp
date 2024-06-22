// Copyright fenryux


#include "Character/NBEnemyCharacter.h"
#include "GameplayAbilitySystem/NBAbilitySystemComponent.h"
#include "GameplayAbilitySystem/Attributes/NBEnemyAttributeSet.h"
#include "GameplayAbilitySystem/Attributes/NBPlayerAttributeSet.h"


ANBEnemyCharacter::ANBEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UNBAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UNBEnemyAttributeSet>("AttributeSet");
}

void ANBEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

UAttributeSet* ANBEnemyCharacter::GetAttributeSet() const
{
	return AttributeSet;
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

void ANBEnemyCharacter::InteractWith()
{
	UNBEnemyAttributeSet* EnemyAttributeSet = Cast<UNBEnemyAttributeSet>(GetAttributeSet());
}
