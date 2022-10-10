// // Fill out your copyright notice in the Description page of Project Settings.
//
//
// #include "UIMockup_WidgetSwitcher.h"
//
// #include "UIMockup_MainWidgetInterface.h"
// #include "Components/WidgetSwitcher.h"
//
//
// UWidgetSwitcher* IUIMockup_WidgetSwitcherInterface::GetWidgetSwitcher() const
// {
// 	return MainWidgetInterface->WidgetSwitcher;
// }
//
// UWidgetSwitcher* IUIMockup_WidgetSwitcherInterface::GetWidgetSwitcherChecked() const
// {
// 	UWidgetSwitcher* CurrentWidgetSwitcher = MainWidgetInterface->WidgetSwitcher;
// 	check(CurrentWidgetSwitcher)
// 	return CurrentWidgetSwitcher;
// }
//
// void IUIMockup_WidgetSwitcherInterface::SetMainWidgetInterface(IUIMockup_MainWidgetInterface* NewMainWidgetInterface)
// {
// 	MainWidgetInterface = NewMainWidgetInterface;
// }
//
// IUIMockup_MainWidgetInterface* IUIMockup_WidgetSwitcherInterface::GetMainWidgetInterface() const
// {
// 	return MainWidgetInterface;
// }
//
// IUIMockup_MainWidgetInterface* IUIMockup_WidgetSwitcherInterface::GetMainWidgetInterfaceChecked() const
// {
// 	IUIMockup_MainWidgetInterface* CurrentMainWidgetInterface = GetMainWidgetInterface();
// 	check(CurrentMainWidgetInterface)
// 	return CurrentMainWidgetInterface;
// }
