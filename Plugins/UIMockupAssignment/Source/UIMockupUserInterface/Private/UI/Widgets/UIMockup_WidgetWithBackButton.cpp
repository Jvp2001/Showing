// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/UIMockup_WidgetWithBackButton.h"

#include "UI/Components/UIMockup_BackButton.h"

void UUIMockup_WidgetWithBackButton::NativeConstruct()
{


	Super::NativeConstruct();

	BackButton->SetMainWidgetInterface(this);
	BackButton->OnClicked.AddUniqueDynamic(this, &ThisClass::OnBackButtonClicked);
}

void UUIMockup_WidgetWithBackButton::OnBackButtonClicked()
{
	GetMainWidgetInterfaceChecked()->GoBack();
}
