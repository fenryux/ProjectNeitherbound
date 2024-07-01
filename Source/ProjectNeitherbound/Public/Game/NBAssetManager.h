// Copyright fenryux

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "NBAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API UNBAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static const UNBAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
	
};
