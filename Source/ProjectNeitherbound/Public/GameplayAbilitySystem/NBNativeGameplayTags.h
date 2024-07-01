// Copyright fenryux

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
*	Singleton for storing Native Gameplay Tags
*/
class PROJECTNEITHERBOUND_API FNBNativeGameplayTags
{
public:
	static const FNBNativeGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	//~ Begin Character Vital Attributes Tags
	FGameplayTag Character_Attributes_Vital_Health;
	FGameplayTag Character_Attributes_Vital_Mana;
	FGameplayTag Character_Attributes_Vital_MaxHealth;
	FGameplayTag Character_Attributes_Vital_MaxMana;
	//~ End Character Vital Attributes Tags

	//~ Begin Character Combat Attributes Tags
	FGameplayTag Character_Attributes_Combat_Movement_Speed;
	FGameplayTag Character_Attributes_Combat_Critical_Chance;
	FGameplayTag Character_Attributes_Combat_Critical_Multiplier;
	//~ End Character Combat Attributes Tags
	
	//~ Begin Character Combat Tags
	FGameplayTag Character_Combat_Damage_Type_Fire;
	FGameplayTag Character_Combat_Damage_Type_Cold;
	FGameplayTag Character_Combat_Damage_Type_Lightning;
	FGameplayTag Character_Combat_Damage_Type_Physical;
	//~ End Character Combat Tags

	//~ Begin Character Damage Resistances Tags
	FGameplayTag Character_Combat_Damage_Resistance_Fire;
	FGameplayTag Character_Combat_Damage_Resistance_Cold;
	FGameplayTag Character_Combat_Damage_Resistance_Lightning;
	FGameplayTag Character_Combat_Damage_Resistance_Physical;
	//~ End Character Damage Resistances Tags

	//~ Begin Character State Tags
	FGameplayTag Character_State_Movement_Rooted;
	FGameplayTag Character_State_Movement_Slowed;
	FGameplayTag Character_State_Status_Bleeding;
	FGameplayTag Character_State_Status_Stunned;
	FGameplayTag Character_State_Status_Burning;
	FGameplayTag Character_State_Status_Frozen;
	FGameplayTag Character_State_Status_Shocked;
	FGameplayTag Character_State_Vital_Alive;
	FGameplayTag Character_State_Vital_Dead;
	//~ End Character State Tags

private:
	static FNBNativeGameplayTags GameplayTags;

};
