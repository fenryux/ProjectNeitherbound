// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

UENUM(BlueprintType)
enum class ENBAbilityInputID : uint8
{
	None             UMETA(DisplayName = "None"),
	Confirm          UMETA(DisplayName = "Confirm"),
	Cancel           UMETA(DisplayName = "Cancel"),
	IA_Ability1      UMETA(DisplayName = "Ability1"),	
	IA_Ability2      UMETA(DisplayName = "Ability2"),
	IA_Ability3      UMETA(DisplayName = "Ability3"),
	IA_Ability4      UMETA(DisplayName = "Ability4"),
	IA_Ability5      UMETA(DisplayName = "Ability5"),
	IA_DodgeRoll     UMETA(DisplayName = "DodgeRoll ")	
};

