// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/EditableTextBox.h"
#include "UIMockup_EditableTextBlock.generated.h"

/**
 * 
 */
UCLASS()
class UIMOCKUPUSERINTERFACE_API UUIMockup_EditableTextBlock : public UEditableTextBox
{
	GENERATED_BODY()

public:
	UUIMockup_EditableTextBlock();
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
virtual void OnCreationFromPalette() override;
#endif
protected:
	virtual void OnWidgetRebuilt() override;
private:
	UPROPERTY()
	USlateWidgetStyleAsset* StyleAsset;
	

};
