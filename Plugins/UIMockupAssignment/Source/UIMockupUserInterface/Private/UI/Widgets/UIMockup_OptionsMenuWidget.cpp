// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/UIMockup_OptionsMenuWidget.h"

#include "UI/UIMockupUtilities.h"
#include "UI/Components/UIMockup_BackButton.h"
#include "UI/Widgets/UIMockup_AudioSettingsWidget.h"
#include "UI/Widgets/UIMockup_DisplaySettingsWidget.h"


void UUIMockup_OptionsMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	DisplayButton->OnClicked.AddUniqueDynamic(this, &ThisClass::OnDisplayButtonClicked);
	AudioButton->OnClicked.AddUniqueDynamic(this, &ThisClass::OnAudioButtonClicked);
	
}

void UUIMockup_OptionsMenuWidget::OnDisplayButtonClicked()
{
	GetMainWidgetInterfaceChecked()->Goto(UUIMockup_DisplaySettingsWidget::StaticClass()->GetName());
}	


void UUIMockup_OptionsMenuWidget::OnAudioButtonClicked()
{
//Same as above but for audio settings
GetMainWidgetInterfaceChecked()->Goto(UUIMockup_AudioSettingsWidget::StaticClass()->GetName());
}
