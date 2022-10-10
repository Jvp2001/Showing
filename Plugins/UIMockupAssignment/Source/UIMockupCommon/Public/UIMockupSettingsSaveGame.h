// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "UObject/Object.h"
#include "UIMockupSettingsSaveGame.generated.h"


USTRUCT(BlueprintType)
struct FGameSettings
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	int32 MasterVolume;
	UPROPERTY(BlueprintReadOnly)
	int32 Brightness;
	
};
/**
 * 
 */
UCLASS()
class UIMOCKUPCOMMON_API UUIMockupSettingsSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Game Settings")
	FGameSettings GameSettings;
	UPROPERTY(BlueprintReadOnly, Category = "Game Settings")
	FString PlayerName;
};
