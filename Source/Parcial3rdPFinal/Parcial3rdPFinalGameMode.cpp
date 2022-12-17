// Copyright Epic Games, Inc. All Rights Reserved.

#include "Parcial3rdPFinalGameMode.h"
#include "Parcial3rdPFinalCharacter.h"
#include "UObject/ConstructorHelpers.h"

AParcial3rdPFinalGameMode::AParcial3rdPFinalGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
