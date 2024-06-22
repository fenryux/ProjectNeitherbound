// Copyright fenryux

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

	//~ Begin ITargetInterface
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;
	virtual void InteractWith() override;
	//~ End ITargetInterface

	virtual UAttributeSet* GetAttributeSet() const override;
	
protected:
	virtual void BeginPlay() override;
};
