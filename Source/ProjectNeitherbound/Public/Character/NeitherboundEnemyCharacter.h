// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/NeitherboundCharacterBase.h"
#include "Interface/TargetInterface.h"
#include "NeitherboundEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API ANeitherboundEnemyCharacter : public ANeitherboundCharacterBase, public ITargetInterface
{
	GENERATED_BODY()

public:
	ANeitherboundEnemyCharacter();
	
	virtual void Tick(float DeltaSeconds) override;
	
	virtual void HighlightActor() override;

	virtual void UnhighlightActor() override;
};
