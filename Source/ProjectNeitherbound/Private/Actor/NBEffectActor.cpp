// Copyright fenryux


#include "Actor/NBEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Components/SphereComponent.h"
#include "GameplayAbilitySystem/NBAttributeSet.h"


ANBEffectActor::ANBEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh   = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");

	SetRootComponent(Mesh);
	Sphere->SetupAttachment(Mesh);
}

void ANBEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: Change this to apply a GameplayEffect. For now big NoNo const_cast hack!
	if(IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UNBAttributeSet* NBAttributeSet = Cast<UNBAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UNBAttributeSet::StaticClass()));
		UNBAttributeSet* MutableNBAttributeSet = const_cast<UNBAttributeSet*>(NBAttributeSet);
		MutableNBAttributeSet->SetHealth(NBAttributeSet->GetHealth() + 50.f);
		MutableNBAttributeSet->SetMana(NBAttributeSet->GetMana() - 10.f);
		Destroy();
	}
}

void ANBEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void ANBEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ANBEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ANBEffectActor::EndOverlap);
}

