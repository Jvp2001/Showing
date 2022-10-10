// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetSwitcher.h"
#include "UIMockup_MainWidgetInterface.generated.h"


// This class does not need to be modified.
UINTERFACE(MinimalAPI, NotBlueprintable, meta=( CannotImplementInterfaceInBlueprint ))
class UUIMockup_MainWidgetInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UIMOCKUPUSERINTERFACE_API IUIMockup_MainWidgetInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void GoBack() const = 0;
	/**
	 * @brief Called when the active widget is changed. This is called after the widget is changed, inside the Goto function.
	 * @see UIMockup_MainWidget::Goto
	 */
	virtual void Goto(const FString& WidgetName) const = 0;

	

	virtual UWidgetSwitcher* GetWidgetSwitcher() const = 0;
	virtual TMap<FString, UUserWidget*> GetValidWidgets() const = 0;
protected:
	virtual void OnWidgetSwitched(UUserWidget* NewWidget) = 0;

private:
	friend class IUIMockup_WidgetSwitcher;
};
