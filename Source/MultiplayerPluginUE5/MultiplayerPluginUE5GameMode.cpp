// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiplayerPluginUE5GameMode.h"
#include "MultiplayerPluginUE5Character.h"
#include "UObject/ConstructorHelpers.h"

AMultiplayerPluginUE5GameMode::AMultiplayerPluginUE5GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
