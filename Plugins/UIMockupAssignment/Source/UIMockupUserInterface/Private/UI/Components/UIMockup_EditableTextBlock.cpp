// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Components/UIMockup_EditableTextBlock.h"

#include "UIMockupUserInterface.h"
#include "UI/UIMockupUtilities.h"
#include "Widgets/Input/SEditableTextBox.h"
#define LOCTEXT_NAMESPACE "UIMockup_EditableTextBlock"
UUIMockup_EditableTextBlock::UUIMockup_EditableTextBlock()
{
	StyleAsset = UUIMockupUtilities::GetStyleAsset(this, TEXT("UIMockupEditableTextBoxStyles"));
	if(not StyleAsset)
	{
		return;
		// UE_LOG(LogUIMockup, Error, TEXT("Could not find UIMockupEditableTextBoxStyles in %s"), *GetPathName());
	}
	SEditableTextBox::FArguments DefaultArgs;
	DefaultArgs.Style(StyleAsset->GetStyleChecked<FEditableTextBoxStyle>());
	WidgetStyle = *DefaultArgs._Style; 
}

#if WITH_EDITOR
  const FText UUIMockup_EditableTextBlock::GetPaletteCategory()
{
	return UIMOCKUP_COMPONENTS_PALETTE_CATEGORY;
	
}

void UUIMockup_EditableTextBlock::OnCreationFromPalette()
{
	Super::OnCreationFromPalette();

	// MyEditableTextBlock->SetStyle(StyleAsset->GetStyleChecked<FEditableTextBoxStyle>());
}


#endif

void UUIMockup_EditableTextBlock::OnWidgetRebuilt()
{
	Super::OnWidgetRebuilt();

	
	
}
#undef LOCTEXT_NAMESPACE