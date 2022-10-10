// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "UIMockup_ButtonTextBlock.generated.h"

/**
 * 
 */
UCLASS()
class UIMOCKUPUSERINTERFACE_API UUIMockup_ButtonTextBlock : public UTextBlock
{
	GENERATED_BODY()
	
	public:
	
	UUIMockup_ButtonTextBlock(const FObjectInitializer& ObjectInitialiser);
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif
protected:
virtual TSharedRef<SWidget> RebuildWidget() override;
#if WITH_EDITOR
virtual TSharedRef<SWidget> RebuildDesignWidget(TSharedRef<SWidget> Content) override;
#endif

private:
	UPROPERTY()
	USlateWidgetStyleAsset* StyleAsset = nullptr;
};
