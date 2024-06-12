// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/NBCharacterBase.h"
#include "NBHeroCharacter.generated.h"

class UNBAttributeSet;
class ANBPlayerState;
class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API ANBHeroCharacter : public ANBCharacterBase
{
	GENERATED_BODY()

public:
	ANBHeroCharacter();

protected:
	virtual void Tick(float DeltaSeconds) override;
	
	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();

};
