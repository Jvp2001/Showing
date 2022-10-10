// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIMockup_MainWidgetInterface.h"
#include "UObject/Interface.h"
#include "UIMockup_WidgetSwitcherInterface.generated.h"

class UWidgetSwitcher;
// This class does not need to be modified.
UINTERFACE()
class UUIMockup_WidgetSwitcherInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UIMOCKUPUSERINTERFACE_API IUIMockup_WidgetSwitcherInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void SetMainWidgetInterface(UObject* NewMainWidgetInterface) const = 0;

private:
	
	friend class IUIMockup_WidgetSwitcher;
	
	
};
