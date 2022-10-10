// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "UObject/Object.h"
#include "UIMockup_TitleTextBlock.generated.h"

/**
 * 
 */
UCLASS()
class UIMOCKUPUSERINTERFACE_API UUIMockup_TitleTextBlock : public UTextBlock
{

	GENERATED_BODY()
public:
UUIMockup_TitleTextBlock();
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
protected:
	virtual TSharedRef<SWidget> RebuildDesignWidget(TSharedRef<SWidget> Content) override;
#endif
	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void OnWidgetRebuilt() override;

private:
	UPROPERTY()
	USlateWidgetStyleAsset* StyleAsset = nullptr;
	FSlateFontInfo SlateFontInfo;
};
