// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIMockupGameSettingsSubsystem.h"
#include "UIMockup_WidgetWithBackButton.h"
#include "UIMockup_UserSettingsWidget.generated.h"

/**
 * 
 */
UCLASS()
class UIMOCKUPUSERINTERFACE_API UUIMockup_UserSettingsWidget : public UUIMockup_WidgetWithBackButton
{
	
private:
	GENERATED_BODY()


protected:
	//~ Begin UUserWidget Interface
	virtual void NativeConstruct() override;
	UFUNCTION()
	bool IsUsernameValid() const;

	//TODO: Remove
	//virtual TSharedRef<SWidget> RebuildWidget() override;
	//~ End UUserWidget Interface

	UFUNCTION()
	void OnUsernameChanged(const FText& NewText);
	UFUNCTION()
	void OnNextButtonClicked();

	UFUNCTION()
	bool IsNextButtonDisabled();
	
private:
	FEditableTextBoxStyle DefaultUsernameTextBoxStyle;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess))
	FEditableTextBoxStyle UsernameErrorEditableTextBoxStyle;
	UPROPERTY(EditDefaultsOnly)
	FString ValidUsernamePattern = TEXT("^[a-zA-Z0-9_]{3,16}$");
	UPROPERTY(EditDefaultsOnly)
	FString ErrorText = TEXT("Username must be between 3 and 16 characters and can only contain letters, numbers and underscores");
	
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess, BindWidget))
	class UTextBlock* UsernameErrorTextBlock;
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess, BindWidget))
	class UUIMockup_EditableTextBlock* UsernameTextBlock;

	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess, BindWidget))
	class UCheckBox* RememberUsernameCheckBox;
	
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess, BindWidget))
	class UUIMockup_ButtonWithText* NextButton;

	UPROPERTY()
	UUIMockupGameSettingsSubsystem* UIMockupGameSettingsSubsystem;
};
