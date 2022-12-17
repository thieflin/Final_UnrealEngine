// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	MaxLife = 100;
	PercentHp = 1;
	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentLife = MaxLife;
	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::GetDamage(float amountOfDmg) {

	CurrentLife -= amountOfDmg;
	PercentHp = CurrentLife / MaxLife;
	OnDamage.Broadcast(PercentHp);
	if (CurrentLife <= 0) 
	{
		UGameplayStatics::OpenLevel(GetWorld(), "LoseScene");
	}
}

