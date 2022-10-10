// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Components/UIMockup_Button.h"

#include "Editor.h"
#include "UIMockupUserInterface.h"
#include "UI/UIMockupUtilities.h"
#include "Kismet/GameplayStatics.h"
#include "Styling/SlateWidgetStyleAsset.h"

#define LOCTEXT_NAMESPACE "UIMockup_Button"


UUIMockup_Button::UUIMockup_Button(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{

	
static USlateWidgetStyleAsset* StyleAsset = UUIMockupUtilities::GetStyleAsset(this, TEXT("UIMockupButtonStyle"));
	

	if(not StyleAsset)
		return;
	SButton::FArguments ButtonArguments;

	ButtonArguments.ButtonStyle(StyleAsset);
	WidgetStyle = *ButtonArguments._ButtonStyle;
	
	
	
}
#if WITH_EDITOR
const FText UUIMockup_Button::GetPaletteCategory()
{
	return UIMOCKUP_COMPONENTS_PALETTE_CATEGORY;
	
}
#endif

#undef LOCTEXT_NAMESPACE