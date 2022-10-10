// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIMockupSettingsSaveGame.h"
#include "UObject/Object.h"
#include "UIMockupGameSettingsSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UIMOCKUPCOMMON_API UUIMockupGameSettingsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "UIMockup|GameSettings")
	bool Save() const;
	UFUNCTION(BlueprintCallable, Category = "UIMockup|GameSettings")
	bool Load() const;

	UFUNCTION(BlueprintPure, Category = "UIMockup|GameSettings")
	FString GetPlayerName() const;
	UFUNCTION(BlueprintCallable, Category = "UIMockup|GameSettings")
	void SetPlayerName(const FString& NewPlayerName);
	
	UFUNCTION(BlueprintCallable, Category = "UIMockup|GameSettings")
	void SetBrightness(float Brightness);

	UFUNCTION(BlueprintCallable, Category = "UIMockup|GameSettings")
	void SetVolume(float Volume);

	UFUNCTION(BlueprintPure, Category = "UIMockup|GameSettings")
	FGameSettings GetGameSettings() const;
private:
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess))
	class UUIMockupSettingsSaveGame* SettingsSaveGame;

	UPROPERTY()
	const class UUIMockupSettings* Settings;
	
};
