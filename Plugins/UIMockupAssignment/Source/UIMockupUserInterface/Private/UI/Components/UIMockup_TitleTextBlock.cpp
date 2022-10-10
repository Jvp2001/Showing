// Fill out your copyright notice in the Description page of Project Settings.



#include "UI/Components/UIMockup_TitleTextBlock.h"

#include "UIMockupUserInterface.h"
#include "UI/UIMockupUtilities.h"

#define LOCTEXT_NAMESPACE "UIMockup_TitleTextBlock"

UUIMockup_TitleTextBlock::UUIMockup_TitleTextBlock()
{
	// StyleAsset = UUIMockupUtilities::GetStyleAsset(this, TEXT("UIMockupTitleTextBlockStyles"));
	// if(not StyleAsset)
	// {
	// 	return;
	// }
	// SlateFontInfo = StyleAsset->GetStyleChecked<FTextBlockStyle>()->Font;
	
}
#if WITH_EDITOR
const FText UUIMockup_TitleTextBlock::GetPaletteCategory()
{
	return UIMOCKUP_COMPONENTS_PALETTE_CATEGORY;
}

TSharedRef<SWidget> UUIMockup_TitleTextBlock::RebuildDesignWidget(TSharedRef<SWidget> Content)
{
	return Super::RebuildDesignWidget(Content);
	// MyTextBlock->SetTextStyle(StyleAsset->GetStyleChecked<FTextBlockStyle>());
	// return MyTextBlock.ToSharedRef();

}

#endif

TSharedRef<SWidget> UUIMockup_TitleTextBlock::RebuildWidget()
{
	return Super::RebuildWidget();
	
}

void UUIMockup_TitleTextBlock::OnWidgetRebuilt()
{

	Super::OnWidgetRebuilt();
}

#undef LOCTEXT_NAMESPACE


