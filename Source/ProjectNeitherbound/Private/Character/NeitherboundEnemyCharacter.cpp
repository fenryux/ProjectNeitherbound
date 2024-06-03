// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NeitherboundEnemyCharacter.h"


ANeitherboundEnemyCharacter::ANeitherboundEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ANeitherboundEnemyCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ANeitherboundEnemyCharacter::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
}

void ANeitherboundEnemyCharacter::UnhighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
}
