// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UI/Widgets/UIMockup_Widget.h"
#include "UI/Interfaces/UIMockup_WidgetSwitcherInterface.h"
#include "UIMockup_MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class UIMOCKUPUSERINTERFACE_API UUIMockup_MenuWidget : public UUIMockup_Widget, public IUIMockup_WidgetSwitcherInterface
{
public:


private:
	GENERATED_BODY()
public:
	// virtual TScriptInterface<IUIMockup_MainWidgetInterface>& GetWidgetSwitcher() const override;
	// virtual TScriptInterface<IUIMockup_MainWidgetInterface>& GetWidgetSwitcherChecked() const override;
	virtual void SetMainWidgetInterface(UObject* NewMainWidgetInterface) const override;
	IUIMockup_MainWidgetInterface* GetMainWidgetInterface() const;
	IUIMockup_MainWidgetInterface* GetMainWidgetInterfaceChecked() const;
protected:

	UPROPERTY()
	mutable UObject* MainWidgetInterface = nullptr;

};
