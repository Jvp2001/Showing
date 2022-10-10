// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Components/UIMockup_ButtonWithText.h"


#include "UIMockupUserInterface.h"

#include "Blueprint/WidgetTree.h"
#include "Widgets/SWidget.h"

#include "UI/UIMockupUtilities.h"
#define LOCTEXT_NAMESPACE "UIMockup_ButtonWithText"

UUIMockup_ButtonWithText::UUIMockup_ButtonWithText()
{
	ButtonStyleAsset = UUIMockupUtilities::GetStyleAsset(this, TEXT("UIMockupButtonStyle"));

	ButtonTextStyleAsset = UUIMockupUtilities::GetStyleAsset(this, TEXT("UIMockupButtonTextBlockStyles"));
}
#if WITH_EDITOR

const FText UUIMockup_ButtonWithText::GetPaletteCategory()
{
	return UIMOCKUP_COMPONENTS_PALETTE_CATEGORY;
}

#endif


FText UUIMockup_ButtonWithText::GetDisplayLabelText()
{

	if (FString CurrentDisplayLabel = GetDisplayLabel(); !CurrentDisplayLabel.IsEmpty() and bUseDisplayNameForText)
	{

		CurrentDisplayLabel.RemoveFromEnd("Button");

		FText InText = FText::FromString(CurrentDisplayLabel);
		UE_LOG(LogUIMockup, Log, TEXT("Class: %s\nInText: %s"), *StaticClass()->GetName(), *InText.ToString());
		Text = InText;
		UE_LOG(LogUIMockup, Log, TEXT("Class: %s\nText: %s"), *StaticClass()->GetName(), *Text.ToString());

	}
	return Text;
}

TSharedRef<SWidget> UUIMockup_ButtonWithText::RebuildWidget()
{
	
	MyTextBlock =
		SNew(STextBlock)
	.Justification(TextJustification)
	.Text(GetDisplayLabelText());
	if (ButtonTextStyleAsset)
	{
		MyTextBlock->SetTextStyle(ButtonTextStyleAsset->GetStyleChecked<FTextBlockStyle>());
	}
	MyButton = SNew(SButton)
		.OnClicked(BIND_UOBJECT_DELEGATE(FOnClicked, SlateHandleClicked))
		.OnPressed(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandlePressed))
		.OnReleased(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandlePressed))
		.OnHovered_UObject(this, &ThisClass::SlateHandleHovered)
		.ClickMethod(ClickMethod)
		.TouchMethod(TouchMethod)
		.PressMethod(PressMethod)
		.IsFocusable(IsFocusable)
		.VAlign(VAlign_Center)
	[
		
		MyTextBlock.ToSharedRef()
	];
	if (ButtonStyleAsset)
	{
		ApplyButtonStyleAsset();
	}
	return MyButton.ToSharedRef();
}

TAttribute<FText> UUIMockup_ButtonWithText::GetDisplayText()
{
	return PROPERTY_BINDING(FText, Text);
}

void UUIMockup_ButtonWithText::OnBindingChanged(const FName& Property)
{
	Super::OnBindingChanged(Property);
	if (!MyTextBlock)
		return;

	if (static const FName TextProperty = GET_MEMBER_NAME_CHECKED(ThisClass, TextDelegate); Property == TextProperty and not bUseDisplayNameForText)
	{
		MyTextBlock->SetText(GetDisplayText());
	}

}

void UUIMockup_ButtonWithText::ApplyButtonStyleAsset() const
{
	MyButton->SetButtonStyle(ButtonStyleAsset->GetStyleChecked<FButtonStyle>());
}

void UUIMockup_ButtonWithText::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	if (MyTextBlock)
	{
		// TAttribute<FText> InText = GetDisplayLabel();
	
		UE_LOG(LogUIMockup, Log, TEXT("Button Text: %s"), *Text.ToString());
		if(!bUseDisplayNameForText)
			MyTextBlock->SetText(GetDisplayText());
		// MyTextBlock->SetTextStyle(ButtonTextStyleAsset->GetStyleChecked<FTextBlockStyle>());
	}
	if (MyButton)
	{
		ApplyButtonStyleAsset();
	}
	// if (bUseDisplayNameForText)
	// {
	// 	if (const FString CurrentDisplayLabel = GetDisplayLabel(); !CurrentDisplayLabel.IsEmpty())
	// 	{
	// 		static constexpr uint8 ButtonWordLength = 7;
	// 		MyTextBlock->SetText(FText::FromString(CurrentDisplayLabel.LeftChop(CurrentDisplayLabel.Len() - ButtonWordLength)));
	// 	}
	// }
	//

}


#undef LOCTEXT_NAMESPACE
