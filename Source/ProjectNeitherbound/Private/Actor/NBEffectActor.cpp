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
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	if(!TargetASC)
		return;

	check(GameplayEffectClass);
	FGameplayEffectContextHandle EffectContext = TargetASC->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	FGameplayEffectSpecHandle EffectSpec = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContext);
	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpec.Data.Get());
}

