// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Auctoritas3GameMode.h"
#include "Auctoritas3PlayerController.h"
#include "AuctoritasPlayer.h"
#include "UObject/ConstructorHelpers.h"

#include "AuctoritasHUD.h"

AAuctoritas3GameMode::AAuctoritas3GameMode() : Super()
{
	// use our custom PlayerController class
	PlayerControllerClass = AAuctoritas3PlayerController::StaticClass();

	HUDClass = AuctoritasHUD::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}