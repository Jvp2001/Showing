// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "UIMockupSettings.generated.h"

/**
 * Help from here https://www.tomlooman.com/unreal-engine-developer-settings/
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "UI Mockup Settings"))
class UIMOCKUPCOMMON_API UUIMockupSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	FString GetWidgetStylesPath() const { return WidgetStylesPath; }
	FString GetGameSettingsSaveSlotName() const { return GameSettingsSaveSlotName; }
private:
	UPROPERTY(Config, EditAnywhere, Category = "UI Mockup")
	FString WidgetStylesPath = TEXT("/Game/UIMockup/UMG/Styles");
	UPROPERTY(Config, EditAnywhere, Category = "UI Mockup")
	FString GameSettingsSaveSlotName = TEXT("GameSettings");
};
