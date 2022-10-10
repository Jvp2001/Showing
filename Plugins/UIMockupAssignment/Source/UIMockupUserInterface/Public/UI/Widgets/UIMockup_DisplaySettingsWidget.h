// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIMockup_WidgetWithBackButton.h"
#include "UIMockup_DisplaySettingsWidget.generated.h"

/**
 * 
 */
UCLASS()
class UIMOCKUPUSERINTERFACE_API UUIMockup_DisplaySettingsWidget : public UUIMockup_WidgetWithBackButton
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
protected:
	UFUNCTION()
	void OnBrightnessSliderChanged(float NewValue);
	
private:
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess, BindWidget))
	class USlider* BrightnessSlider;
};
