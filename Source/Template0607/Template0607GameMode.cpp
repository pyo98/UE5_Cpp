// Copyright Epic Games, Inc. All Rights Reserved.

#include "Template0607GameMode.h"
#include "Template0607Character.h"
#include "UObject/ConstructorHelpers.h"

ATemplate0607GameMode::ATemplate0607GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
