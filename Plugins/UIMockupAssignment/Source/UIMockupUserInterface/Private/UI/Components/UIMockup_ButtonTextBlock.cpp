// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Components/UIMockup_ButtonTextBlock.h"

#include "UIMockupUserInterface.h"
#include "UI/UIMockupUtilities.h"

#define LOCTEXT_NAMESPACE "UIMockup_ButtonTextBlock"

UUIMockup_ButtonTextBlock::UUIMockup_ButtonTextBlock(const FObjectInitializer& ObjectInitialiser)
	: Super(ObjectInitialiser)

{
	StyleAsset = UUIMockupUtilities::GetStyleAsset(
		this, TEXT("UIMockupButtonTextBlockStyles"));
	if (not StyleAsset)
		return;
}
#if WITH_EDITOR

const FText UUIMockup_ButtonTextBlock::GetPaletteCategory()
{
	return UIMOCKUP_COMPONENTS_PALETTE_CATEGORY;
}

TSharedRef<SWidget> UUIMockup_ButtonTextBlock::RebuildDesignWidget(TSharedRef<SWidget> Content)
{
	return Super::RebuildDesignWidget(Content);
}

#endif

TSharedRef<SWidget> UUIMockup_ButtonTextBlock::RebuildWidget()
{
	return Super::RebuildWidget();
	// MyTextBlock->SetTextStyle(StyleAsset->GetStyleChecked<FTextBlockStyle>());
	//
	// return MyTextBlock.ToSharedRef();
}

#undef LOCTEXT_NAMESPACE
