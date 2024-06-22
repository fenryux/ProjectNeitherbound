// Copyright fenryux


#include "GameplayAbilitySystem/Abilities/Data/NBPlayerAbilitiesDataAsset.h"

UNBPlayerAbilitiesDataAsset::UNBPlayerAbilitiesDataAsset()
{
}

const TSet<FGameplayInputAbilityInfo>& UNBPlayerAbilitiesDataAsset::GetInputAbilities() const
{
	return InputAbilities;
}

void UNBPlayerAbilitiesDataAsset::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	const FProperty* Property = PropertyChangedEvent.Property;
	
	if (Property &&
		Property->GetFName() == GET_MEMBER_NAME_CHECKED(UNBPlayerAbilitiesDataAsset, InputAbilities) &&
		InputAbilities.IsEmpty())
	{
		TArray<FGameplayInputAbilityInfo> InputAbilitiesArray = InputAbilities.Array();
		InputAbilities.Reset();

		for(int32 i = 0; i < InputAbilitiesArray.Num(); ++i)
		{
			FGameplayInputAbilityInfo& Info = InputAbilitiesArray[i];
			Info.InputId = i;
			InputAbilities.Add(Info);
		}
	}
}
