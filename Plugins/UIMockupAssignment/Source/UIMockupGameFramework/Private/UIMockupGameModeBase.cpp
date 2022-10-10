// Copyright Epic Games, Inc. All Rights Reserved.


#include "UIMockupGameModeBase.h"

#include "UIMockupPlayerController.h"

AUIMockupGameModeBase::AUIMockupGameModeBase()
{
	PlayerControllerClass = AUIMockupPlayerController::StaticClass();
}
