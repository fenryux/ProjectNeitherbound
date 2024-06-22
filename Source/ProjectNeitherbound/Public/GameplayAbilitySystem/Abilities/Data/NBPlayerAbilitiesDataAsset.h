// Copyright fenryux

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Engine/DataAsset.h"
#include "NBPlayerAbilitiesDataAsset.generated.h"

class UInputAction;

USTRUCT()
struct FGameplayInputAbilityInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="GameplayInputAbilityInfo")
	TSubclassOf<UGameplayAbility> GameplayAbilityClass;

	UPROPERTY(EditAnywhere, Category="GameplayInputAbilityInfo")
	TObjectPtr<UInputAction> InputAction;

	UPROPERTY(VisibleAnywhere, Category="GameplayInputAbilityInfo")
	int32 InputId;

	bool IsValid() const { return GameplayAbilityClass && InputAction; }

	bool operator==(const FGameplayInputAbilityInfo& Other) const
	{
		return GameplayAbilityClass == Other.GameplayAbilityClass && InputAction == Other.InputAction; 
	}

	bool operator!=(const FGameplayInputAbilityInfo& Other) const
	{
		return !operator==(Other);
	}

	friend uint32 GetTypeHash(const FGameplayInputAbilityInfo& Item)
	{
		return HashCombine(GetTypeHash(Item.GameplayAbilityClass), GetTypeHash(Item.InputAction));
	}
};

/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API UNBPlayerAbilitiesDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UNBPlayerAbilitiesDataAsset();
	
	const TSet<FGameplayInputAbilityInfo>& GetInputAbilities() const;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
protected:
	// Purely to remove any duplicates
	UPROPERTY(EditAnywhere, Category="GameplayAbilitySystem")
	TSet<FGameplayInputAbilityInfo> InputAbilities;
	
};
