// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIMockupGameSettingsSubsystem.h"
#include "GameFramework/PlayerController.h"
#include "UIMockupPlayerController.generated.h"

// ========================================================================
// FUIMockupPlayerControllerSettings
// This is the source effect's setting struct. 
// ========================================================================

UCLASS()
class  AUIMockupPlayerController final : public APlayerController
{
	GENERATED_BODY()
public:
	AUIMockupPlayerController();
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> MainWidgetClass;
	UPROPERTY(BlueprintReadOnly, Category="Widgets", meta=(AllowPrivateAccess))
	class UUIMockup_MainWidget* MainWidget = nullptr;
	UPROPERTY()
	UUIMockupGameSettingsSubsystem* UIMockupGameSettingsSubsystem;
};
