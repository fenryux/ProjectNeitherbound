// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NeitherboundCharacterBase.generated.h"

UCLASS(Abstract)
class PROJECTNEITHERBOUND_API ANeitherboundCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ANeitherboundCharacterBase();

protected:
	virtual void BeginPlay() override;

};
