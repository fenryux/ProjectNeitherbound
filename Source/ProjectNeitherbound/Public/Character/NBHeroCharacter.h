// Copyright fenryux

#pragma once

#include "CoreMinimal.h"
#include "Character/NBCharacterBase.h"
#include "NBHeroCharacter.generated.h"

class UNBPlayerAttributeSet;
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

	//~ Begin Replication Setup
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	//~ End Replication Setup

private:
	void InitAbilityActorInfo();

};
