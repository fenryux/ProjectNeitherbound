// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NBCharacterBase.h"

// Sets default values
ANBCharacterBase::ANBCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

UAbilitySystemComponent* ANBCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ANBCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}
