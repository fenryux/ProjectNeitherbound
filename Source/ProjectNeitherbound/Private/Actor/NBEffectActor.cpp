// Copyright fenryux


#include "Actor/NBEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayAbilitySystem/NBAbilitySystemComponent.h"

ANBEffectActor::ANBEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void ANBEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void ANBEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if(!TargetAbilitySystemComponent)
		return;

	check(GameplayEffectClass);
	FGameplayEffectContextHandle EffectContext = TargetAbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	FGameplayEffectSpecHandle EffectSpec = TargetAbilitySystemComponent->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContext);
	TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpec.Data.Get());
}

