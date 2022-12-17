// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CurrentCoinCounter.generated.h"


UCLASS()
class PARCIAL3RDPFINAL_API ACurrentCoinCounter : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACurrentCoinCounter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int totalCoins;	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int neededCoins;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool canSpawnDoor;
	UPROPERTY(EditAnywhere)
		bool canExecuteSpawn;

	UFUNCTION(BlueprintCallable)
		void UpdateCoins(int coinValue);

	UFUNCTION(BlueprintCallable)
		int UpdateCoinText();

	UFUNCTION(BlueprintCallable)
		void WinFunction();

	UFUNCTION(BlueprintCallable)
		bool ReturnWinCondition();

	UPROPERTY(EditAnywhere)
		class AActor* Cc;

	UFUNCTION(BlueprintCallable)
		void SwitchPls();

};
