// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIMockup_MenuWidget.h"
#include "UIMockup_WidgetWithBackButton.h"
#include "UIMockup_OptionsMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class UIMOCKUPUSERINTERFACE_API UUIMockup_OptionsMenuWidget : public UUIMockup_WidgetWithBackButton

{
	GENERATED_BODY()
public:
	UFUNCTION()
	void OnDisplayButtonClicked();
	UFUNCTION()
	void OnAudioButtonClicked();
	//~ Begin UUserWidget Interface
	virtual void NativeConstruct() override; 
	//~ End UUserWidget Interface
private:
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess, BindWidget))
	class UUIMockup_ButtonWithText* DisplayButton;
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess, BindWidget))
	UUIMockup_ButtonWithText* AudioButton;
	

};
