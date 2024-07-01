// Copyright fenryux


#include "GameplayAbilitySystem/NBNativeGameplayTags.h"
#include "NativeGameplayTags.h"

FNBNativeGameplayTags FNBNativeGameplayTags::GameplayTags;

void FNBNativeGameplayTags::InitializeNativeGameplayTags()
{
	//~ Begin Character Vital Attributes Tags
	GameplayTags.Character_Attributes_Vital_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.Attributes.Vital.Health"),
		FString("Represent character hit points")
	);
	GameplayTags.Character_Attributes_Vital_Mana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.Attributes.Vital.Mana"),
		FString("Represent character mana points")
	);
	GameplayTags.Character_Attributes_Vital_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.Attributes.Vital.MaxHealth"),
		FString("Represent character max hit points")
	);
	GameplayTags.Character_Attributes_Vital_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.Attributes.Vital.MaxMana"),
		FString("Represent character max mana points")
	);
	//~ End Character Vital Attributes Tags

	//~ Begin Character Combat Tags
	GameplayTags.Character_Attributes_Combat_Movement_Speed = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.Attributes.Combat.Movement.Speed"),
		FString("Represent character movement speed")
	);
	GameplayTags.Character_Attributes_Combat_Critical_Chance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.Attributes.Combat.Critical.Chance"),
		FString("Represent character critical hit chance")
	);
	GameplayTags.Character_Attributes_Combat_Critical_Multiplier = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.Attributes.Combat.Critical.Multiplier"),
		FString("Represent character critical hit damage multiplier")
	);
	GameplayTags.Character_Combat_Damage_Type_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.Combat.Damage.Type.Fire"),
		FString("Represent character's ability damage type - Fire")
	);
	GameplayTags.Character_Combat_Damage_Type_Cold = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.Combat.Damage.Type.Cold"),
		FString("Represent character's ability damage type - Cold")
	);
	GameplayTags.Character_Combat_Damage_Type_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.Combat.Damage.Type.Lightning"),
		FString("Represent character's ability damage type - Lightning")
	);
	GameplayTags.Character_Combat_Damage_Type_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.Combat.Damage.Type.Physical"),
		FString("Represent character's ability damage type - Physical")
	);
	//~ End Character Combat Tags

	//~ Begin Character Damage Resistance Tags
	GameplayTags.Character_Combat_Damage_Resistance_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.Combat.Damage.Resistance.Fire"),
		FString("Represent character's damage resistance - Fire")
	);
	GameplayTags.Character_Combat_Damage_Resistance_Cold = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.Combat.Damage.Resistance.Cold"),
		FString("Represent character's damage resistance - Cold")
	);
	GameplayTags.Character_Combat_Damage_Resistance_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.Combat.Damage.Resistance.Lightning"),
		FString("Represent character's damage resistance - Lightning")
	);
	GameplayTags.Character_Combat_Damage_Resistance_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.Combat.Damage.Resistance.Physical"),
		FString("Represent character's damage resistance - Physical")
	);
	//~ End Character Damage Resistance Tags

	//~ Begin Character State Tags
	GameplayTags.Character_State_Movement_Rooted = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.State.Movement.Rooted"),
		FString("Represent character's movement state - Rooted")
	);
	GameplayTags.Character_State_Movement_Slowed = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.State.Movement.Slowed"),
		FString("Represent character's movement state - Slowed")
	);
	GameplayTags.Character_State_Status_Bleeding = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.State.Status.Bleeding"),
		FString("Represent character's status effect - Bleeding")
	);
	GameplayTags.Character_State_Status_Stunned = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.State.Status.Stunned"),
		FString("Represent character's status effect - Stunned")
	);
	GameplayTags.Character_State_Status_Burning = UGameplayTagsManager::Get().AddNativeGameplayTag(
    	FName("Character.State.Status.Burning"),
    	FString("Represent character's status effect - Burning")
    );
	GameplayTags.Character_State_Status_Frozen = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.State.Status.Frozen"),
		FString("Represent character's status effect - Frozen")
	);
	GameplayTags.Character_State_Status_Shocked = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.State.Status.Shocked"),
		FString("Represent character's status effect - Shocked")
	);
	GameplayTags.Character_State_Vital_Alive = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.State.Vital.Alive"),
		FString("Represent character's vital status - Alive")
	);
	GameplayTags.Character_State_Vital_Dead = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Character.State.Vital.Dead"),
		FString("Represent character's vital status - Dead")
	);
	//~ End Character State Tags
}
