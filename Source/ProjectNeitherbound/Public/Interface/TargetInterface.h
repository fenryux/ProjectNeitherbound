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
	virtual void HighlightActor() = 0;

	virtual void UnhighlightActor() = 0;
};