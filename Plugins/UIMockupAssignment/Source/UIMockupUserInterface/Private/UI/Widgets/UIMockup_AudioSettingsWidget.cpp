// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/UIMockup_AudioSettingsWidget.h"

#include "UIMockupGameSettingsSubsystem.h"
#include "Components/Slider.h"
#include "Kismet/GameplayStatics.h"

void UUIMockup_AudioSettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	UUIMockupGameSettingsSubsystem* MockupGameSettingsSubsystem = UGameplayStatics::GetGameInstance(this)->GetSubsystem<UUIMockupGameSettingsSubsystem>();
	check(MockupGameSettingsSubsystem);
	VolumeSlider->SetMinValue(0.f);
	VolumeSlider->SetMaxValue(100.f);
	VolumeSlider->SetValue(MockupGameSettingsSubsystem->GetGameSettings().MasterVolume);
	VolumeSlider->OnValueChanged.AddUniqueDynamic(this, &ThisClass::OnVolumeSliderChanged);
}

void UUIMockup_AudioSettingsWidget::OnVolumeSliderChanged(float NewValue)
{
	UUIMockupGameSettingsSubsystem* GameSettingsSubsystem = GetGameInstance()->GetSubsystem<UUIMockupGameSettingsSubsystem>();
	check(GameSettingsSubsystem);
	GameSettingsSubsystem->SetVolume(NewValue);
	
}
