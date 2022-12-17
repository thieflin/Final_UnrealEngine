// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageReceived, float, Amount);

UCLASS(ClassGroup = (Custom), Blueprintable, meta = (BlueprintSpawnableComponent))
class PARCIAL3RDPFINAL_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CurrentLife;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxLife;	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PercentHp;

	UFUNCTION(BlueprintCallable)
		void GetDamage(float amountOfDmg);

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FOnDamageReceived OnDamage;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
