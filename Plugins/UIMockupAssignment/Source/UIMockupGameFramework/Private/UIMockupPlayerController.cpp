// Fill out your copyright notice in the Description page of Project Settings.


#include "UIMockupPlayerController.h"


// Useful header for various DSP-related utility functions.
#include "UIMockupGameSettingsSubsystem.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/MessageDialog.h"
#include "UI/Widgets/UIMockup_MainWidget.h"


AUIMockupPlayerController::AUIMockupPlayerController()
{
	bShowMouseCursor = true;

}

void AUIMockupPlayerController::BeginPlay()
{

	Super::BeginPlay();
	checkf(MainWidgetClass, TEXT("MainWidgetClass cannot be null!"));

	//Get a reference to the UIMockupGameSettingsSubsystem
		MainWidget = CreateWidget<UUIMockup_MainWidget>(this, MainWidgetClass);
		MainWidget->AddToViewport();
	
	
}
