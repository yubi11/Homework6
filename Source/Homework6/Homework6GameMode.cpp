// Copyright Epic Games, Inc. All Rights Reserved.

#include "Homework6GameMode.h"
#include "Homework6Character.h"
#include "UObject/ConstructorHelpers.h"

AHomework6GameMode::AHomework6GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
