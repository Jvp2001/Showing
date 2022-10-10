// Fill out your copyright notice in the Description page of Project Settings.



#include "UI/Widgets/UIMockup_MenuWidget.h"

#include "UI/Components/UIMockup_ButtonWithText.h"

void UUIMockup_MenuWidget::SetMainWidgetInterface(UObject* NewMainWidgetInterface) const
{
	MainWidgetInterface = NewMainWidgetInterface;
}

IUIMockup_MainWidgetInterface* UUIMockup_MenuWidget::GetMainWidgetInterface() const
{
	return Cast<IUIMockup_MainWidgetInterface>(MainWidgetInterface);
}

IUIMockup_MainWidgetInterface* UUIMockup_MenuWidget::GetMainWidgetInterfaceChecked() const
{
	return CastChecked<IUIMockup_MainWidgetInterface>(MainWidgetInterface);
}


