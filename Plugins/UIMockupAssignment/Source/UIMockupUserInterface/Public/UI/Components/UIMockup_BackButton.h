// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Components/UIMockup_ButtonWithText.h"
#include "UI/Interfaces/UIMockup_WidgetSwitcherInterface.h"
#include "UIMockup_BackButton.generated.h"

/**
 * 
 */
UCLASS()
class UIMOCKUPUSERINTERFACE_API UUIMockup_BackButton : public UUIMockup_ButtonWithText, public IUIMockup_WidgetSwitcherInterface
{
	GENERATED_BODY()

public:
	UUIMockup_BackButton();
	

	virtual void SetMainWidgetInterface(UObject* NewMainWidgetInterface) const override;
protected:
	//~ Begin UWidget Interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	//~ End UWidget Interface
	


	UPROPERTY()
	mutable UObject* MainWidgetInterface = nullptr;
	
	
};
