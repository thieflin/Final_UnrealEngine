// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinCounterC/CurrentCoinCounter.h"
#include "Engine/Engine.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include <Runtime/Core/Public/Misc/OutputDeviceNull.h>

// Sets default values
ACurrentCoinCounter::ACurrentCoinCounter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	canSpawnDoor = false;
	canExecuteSpawn = true;
	neededCoins = 23;
}

// Called when the game starts or when spawned
void ACurrentCoinCounter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACurrentCoinCounter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	WinFunction();
}

void ACurrentCoinCounter::UpdateCoins(int coinValue)
{
	totalCoins += coinValue;
}

int ACurrentCoinCounter::UpdateCoinText()
{
	return totalCoins;
}

void ACurrentCoinCounter::WinFunction() //Esto podria hacerlo en un amnager pero bueno vamos probando, primero fujnciona despues lujo
{
	if (totalCoins == neededCoins && canExecuteSpawn)
	{
		canSpawnDoor = true;
		canExecuteSpawn = false;
		//FOutputDeviceNull ar;
		//const FString command = FString::Printf((TEXT("SetCanSpawn true")));
		//if (Cc) {
		//	Cc->CallFunctionByNameWithArguments(*command, ar, NULL, true);
		//}
		
	}
}

void ACurrentCoinCounter::SwitchPls()
{
	canSpawnDoor = false;
}

bool ACurrentCoinCounter::ReturnWinCondition()
{
	return canSpawnDoor;
}

