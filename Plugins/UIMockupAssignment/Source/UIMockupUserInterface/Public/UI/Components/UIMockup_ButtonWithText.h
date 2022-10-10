// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "UIMockup_ButtonWithText.generated.h"

/**
 * 
 */
UCLASS()
class UIMOCKUPUSERINTERFACE_API UUIMockup_ButtonWithText : public UButton
{

	GENERATED_BODY()
public:
	UUIMockup_ButtonWithText();
	/** The text to display */
	UPROPERTY(EditAnywhere, Category=Content, meta=( MultiLine="true" ))
	FText Text = FText::FromString(TEXT("Text Block"));
	UPROPERTY(EditAnywhere, Category=Appearence, meta=(DisplayName="Justification"))
	TEnumAsByte<ETextJustify::Type> TextJustification = ETextJustify::Center;


#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;

protected:
	//~ Begin UWidget Interface
	/**
	 * @brief Get the user set name for this component and sets the TextBlock's text to the same value, but with the word Button removed. 
	 */
	FText GetDisplayLabelText();
#endif
	//Allows for the components to update automatically when any of their properties are changed. Instead of pressing compile after each time. 
	virtual void OnBindingChanged(const FName& Property) override;
	void ApplyButtonStyleAsset() const;
	virtual TSharedRef<SWidget> RebuildWidget() override;

public:

	virtual void SynchronizeProperties() override;
	//~ End UWidget Interface

	/** A bindable delegate to allow logic to drive the text of the widget */
	bool CanUseDisplayNameForText() const { return bUseDisplayNameForText; }
	UPROPERTY()
	FGetText TextDelegate;
protected:
	virtual TAttribute<FText> GetDisplayText();
			

	PROPERTY_BINDING_IMPLEMENTATION(FText, Text)


	TSharedPtr<STextBlock> MyTextBlock;

private:
	/**
	 * This will allow you to use the display name of the component for the child TextBlock's text. The word button will be removed.
	 */
	UPROPERTY(EditDefaultsOnly,Category="Utility")
	bool bUseDisplayNameForText = true;
	UPROPERTY()
	const USlateWidgetStyleAsset* ButtonStyleAsset;
	UPROPERTY()
	const USlateWidgetStyleAsset* ButtonTextStyleAsset;
};
