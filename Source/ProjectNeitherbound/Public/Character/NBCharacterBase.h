// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NBCharacterBase.generated.h"

UCLASS(Abstract)
class PROJECTNEITHERBOUND_API ANBCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ANBCharacterBase();

protected:
	virtual void BeginPlay() override;

};
