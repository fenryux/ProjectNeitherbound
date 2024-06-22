// Copyright fenryux

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TargetInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTargetInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTNEITHERBOUND_API ITargetInterface
{
	GENERATED_BODY()

public:
	//~ Begin Highlighting current target under mouse location
	virtual void HighlightActor() = 0;
	virtual void UnhighlightActor() = 0;
	//~ End Highlighting current target under mouse location

	//~ Begin Interact with target under mouse location
	virtual void InteractWith() = 0;
	//~ End Interact with target under mouse location
};
