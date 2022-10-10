// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIMockup_MenuWidget.h"
#include "UIMockup_WidgetWithBackButton.generated.h"

/**
 * 
 */
UCLASS()
class UIMOCKUPUSERINTERFACE_API UUIMockup_WidgetWithBackButton : public UUIMockup_MenuWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	class UUIMockup_BackButton* GetBackButton() const { return BackButton; }

protected:

	UFUNCTION()
	virtual void OnBackButtonClicked();
private:
	
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess, BindWidget))
	UUIMockup_BackButton* BackButton;
	
	friend class UUIMockup_MainWidget;
	
};
