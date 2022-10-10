// Fill out your copyright notice in the Description page of Project Settings.


#include "UIMockupGameSettingsSubsystem.h"

#include "UIMockupSettings.h"
#include "Kismet/GameplayStatics.h"

void UUIMockupGameSettingsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Settings = GetDefault<UUIMockupSettings>();
	check(Settings);
	SettingsSaveGame = Cast<UUIMockupSettingsSaveGame>(UGameplayStatics::LoadGameFromSlot(Settings->GetGameSettingsSaveSlotName(), 0));                                                                                             
	if (not SettingsSaveGame)
	{
		SettingsSaveGame = Cast<UUIMockupSettingsSaveGame>(
			UGameplayStatics::CreateSaveGameObject(UUIMockupSettingsSaveGame::StaticClass()));
	
		SettingsSaveGame->GameSettings = {};
		SettingsSaveGame->PlayerName = FString(TEXT("Player"));

		UGameplayStatics::SaveGameToSlot(SettingsSaveGame, Settings->GetGameSettingsSaveSlotName(), 0);
	
	}
}

bool UUIMockupGameSettingsSubsystem::Save() const
{
	return UGameplayStatics::SaveGameToSlot(SettingsSaveGame, Settings->GetGameSettingsSaveSlotName(), 0);
}

bool UUIMockupGameSettingsSubsystem::Load() const
{
	return UGameplayStatics::LoadGameFromSlot(Settings->GetGameSettingsSaveSlotName(), 0);
}

FString UUIMockupGameSettingsSubsystem::GetPlayerName() const
{
	
	return SettingsSaveGame->PlayerName;
}

void UUIMockupGameSettingsSubsystem::SetPlayerName(const FString& NewPlayerName)
{
	SettingsSaveGame->PlayerName = NewPlayerName;
	Save();
}

void UUIMockupGameSettingsSubsystem::SetBrightness(float Brightness)
{
	SettingsSaveGame->GameSettings.Brightness = Brightness;
	Save();
}

void UUIMockupGameSettingsSubsystem::SetVolume(float Volume)
{
	SettingsSaveGame->GameSettings.MasterVolume = Volume;
	Save();
}


FGameSettings UUIMockupGameSettingsSubsystem::GetGameSettings() const
{
	return SettingsSaveGame->GameSettings;
}
