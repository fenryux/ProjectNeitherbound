// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/NBCharacterBase.h"
#include "Interface/TargetInterface.h"
#include "NBEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API ANBEnemyCharacter : public ANBCharacterBase, public ITargetInterface
{
	GENERATED_BODY()

public:
	ANBEnemyCharacter();
	
	virtual void Tick(float DeltaSeconds) override;
	
	virtual void HighlightActor() override;

	virtual void UnhighlightActor() override;
};
