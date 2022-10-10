// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/UIMockup_DisplaySettingsWidget.h"

#include "UIMockupGameSettingsSubsystem.h"
#include "Components/Slider.h"
#include "Kismet/GameplayStatics.h"

void UUIMockup_DisplaySettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UUIMockupGameSettingsSubsystem* MockupGameSettingsSubsystem = UGameplayStatics::GetGameInstance(this)->GetSubsystem<UUIMockupGameSettingsSubsystem>();
	check(MockupGameSettingsSubsystem);
	BrightnessSlider->SetMinValue(0.f);
	BrightnessSlider->SetMaxValue(100.f);
	BrightnessSlider->SetValue(MockupGameSettingsSubsystem->GetGameSettings().Brightness);
	BrightnessSlider->OnValueChanged.AddUniqueDynamic(this, &ThisClass::OnBrightnessSliderChanged);
}


void UUIMockup_DisplaySettingsWidget::OnBrightnessSliderChanged(float NewValue)
{
	UUIMockupGameSettingsSubsystem* UIMockupGameSettingsSubsystem = UGameplayStatics::GetGameInstance(this)->GetSubsystem<UUIMockupGameSettingsSubsystem>();
	check(UIMockupGameSettingsSubsystem);
	UIMockupGameSettingsSubsystem->SetBrightness(NewValue);
}
