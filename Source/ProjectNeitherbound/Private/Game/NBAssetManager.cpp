// Copyright fenryux


#include "Game/NBAssetManager.h"

#include "GameplayAbilitySystem/NBNativeGameplayTags.h"

const UNBAssetManager& UNBAssetManager::Get()
{
	check(GEngine);

	return *Cast<UNBAssetManager>(GEngine->AssetManager);
}

void UNBAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FNBNativeGameplayTags::InitializeNativeGameplayTags();
}
