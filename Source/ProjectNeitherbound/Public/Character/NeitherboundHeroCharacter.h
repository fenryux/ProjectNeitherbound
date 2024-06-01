// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/NeitherboundCharacterBase.h"
#include "NeitherboundHeroCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class PROJECTNEITHERBOUND_API ANeitherboundHeroCharacter : public ANeitherboundCharacterBase
{
	GENERATED_BODY()

public:
	ANeitherboundHeroCharacter();

	FORCEINLINE TObjectPtr<UCameraComponent> GetCameraComponent() const { return this->CameraComponent; }

	FORCEINLINE TObjectPtr<USpringArmComponent> GetCameraBoom() const { return this->CameraBoom; }

protected:
	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	
};
