// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NBEnemyCharacter.h"


ANBEnemyCharacter::ANBEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
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
