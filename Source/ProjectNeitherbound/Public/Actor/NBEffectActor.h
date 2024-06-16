// Copyright fenryux

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NBEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class PROJECTNEITHERBOUND_API ANBEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ANBEffectActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;
};
