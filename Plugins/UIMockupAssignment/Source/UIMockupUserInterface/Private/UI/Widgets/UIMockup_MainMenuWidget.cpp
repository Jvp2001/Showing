// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/UIMockup_MainMenuWidget.h"

#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Misc/MessageDialog.h"
#include "UI/UIMockupUtilities.h"
#include "UI/Widgets/UIMockup_OptionsMenuWidget.h"
#include "UI/Widgets/UIMockup_UserSettingsWidget.h"

void UUIMockup_MainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	PlayButton->OnClicked.AddDynamic(this, &ThisClass::PlayGame);
	OptionsButton->OnClicked.AddDynamic(this, &ThisClass::GotoOptions);
	ExitButton->OnClicked.AddDynamic(this, &ThisClass::ExitGame);
}

void UUIMockup_MainMenuWidget::PlayGame() 
{
	GetMainWidgetInterfaceChecked()->Goto(UUIMockup_UserSettingsWidget::StaticClass()->GetName());
}

void UUIMockup_MainMenuWidget::GotoOptions() 
{
	const FString WidgetName = UUIMockup_OptionsMenuWidget::StaticClass()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("Options Widget Name: %s"), *WidgetName);
	GetMainWidgetInterfaceChecked()->Goto(WidgetName);
}

void UUIMockup_MainMenuWidget::ExitGame()
{
	switch (FMessageDialog::Open(EAppMsgType::YesNo, FText::FromString(TEXT("Are you sure you want quit?"))))
	{
	case EAppReturnType::Yes:
		UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
		break;

	case EAppReturnType::No:
	default:
		break;
	}
}
