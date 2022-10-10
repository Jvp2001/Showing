// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Components/UIMockup_BackButton.h"

#include "UI/UIMockupUtilities.h"

UUIMockup_BackButton::UUIMockup_BackButton()
	:Super()
{
;
}

void UUIMockup_BackButton::SetMainWidgetInterface(UObject* NewMainWidgetInterface) const
{
	MainWidgetInterface = NewMainWidgetInterface;
}

TSharedRef<SWidget> UUIMockup_BackButton::RebuildWidget()
{
	Text = FText::FromString(TEXT("Back"));
	TextJustification = ETextJustify::Center;
	// OnClicked.AddUniqueDynamic(this, &ThisClass::Back);
	return Super::RebuildWidget();
	
}
