// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/UIMockup_MainWidget.h"

#include "Components/Button.h"
#include "UIMockupUserInterface.h"
#include "Components/WidgetSwitcher.h"
#include "Misc/MessageDialog.h"
#include "UI/Widgets/UIMockup_MainMenuWidget.h"

UWidgetSwitcher* UUIMockup_MainWidget::GetWidgetSwitcher() const
{
	return WidgetManager;
}

TMap<FString, UUserWidget*> UUIMockup_MainWidget::GetValidWidgets() const
{
	return ValidWidgets;
}


void UUIMockup_MainWidget::OnWidgetSwitched(UUserWidget* NewWidget)
{
	// ActiveWidgetHistory.Push(WidgetManager->GetChildIndex());
	
}

void UUIMockup_MainWidget::Goto(const FString& WidgetName)  const
{
	UE_LOG(LogTemp, Log, TEXT("WidgetName: %s"), *WidgetName);
	if (UUserWidget* Widget = ValidWidgets.FindChecked(WidgetName))
	{
		UWidget* Item = WidgetManager->GetActiveWidget();
		ActiveWidgetHistory.Add(Item);
		UE_LOG(LogUIMockup, Log, TEXT("ActiveWidgetHistory.Push(%d)"), WidgetManager->GetActiveWidgetIndex());
		WidgetManager->SetActiveWidget(Widget);
		
	}
}

void UUIMockup_MainWidget::GoBack() const
{
	//Print the active widget history to the screen
	auto CurrentActiveHistory = ActiveWidgetHistory;
	
	   if(not ActiveWidgetHistory.Num())
	   		return;
	
	UUIMockup_Widget* Widget = Cast<UUIMockup_Widget>(ActiveWidgetHistory.Pop()); 
	UE_LOG(LogUIMockup, Log, TEXT("ActiveWidgetHistory.Pop() --> %s"), *Widget->GetName());
	RootWidgetClass = UUIMockup_MainMenuWidget::StaticClass();
	if(Widget and Widget->StaticClass() != RootWidgetClass)
		WidgetManager->SetActiveWidget(Widget);
}

void UUIMockup_MainWidget::NativeConstruct()
{
	Super::NativeConstruct();
	MainMenuWidget = CreateMenuWidget<UUIMockup_MainMenuWidget>(MainMenuWidgetClass);
	OptionsMenuWidget = CreateMenuWidget<UUIMockup_OptionsMenuWidget>(OptionsMenuWidgetClass);
	AudioSettingsWidget = CreateMenuWidget<UUIMockup_AudioSettingsWidget>(AudioSettingsWidgetClass);
	DisplaySettingsWidget = CreateMenuWidget<UUIMockup_DisplaySettingsWidget>(DisplaySettingsWidgetClass);
	UserSettingsWidget = CreateMenuWidget<UUIMockup_UserSettingsWidget>(UserSettingsWidgetClass);
	HostJoinMenuWidget = CreateMenuWidget<UUIMockup_HostJoinMenuWidget>(HostJoinMenuWidgetClass);

	AddAllWidgets(MainMenuWidget, OptionsMenuWidget, AudioSettingsWidget, DisplaySettingsWidget, UserSettingsWidget, HostJoinMenuWidget);
	SetMainMenuInterfaces(MainMenuWidget, OptionsMenuWidget, AudioSettingsWidget, DisplaySettingsWidget, UserSettingsWidget, HostJoinMenuWidget);
#if WITH_EDITOR

	//Log as warning all the keynames in the ValidWidgets map
	for (auto& Elem : ValidWidgets)
	{
		UE_LOG(LogTemp, Warning, TEXT("Key: %s"), *Elem.Key);
	}
#endif

	WidgetManager->SetActiveWidget(MainMenuWidget);
	ActiveWidgetHistory.Add(MainMenuWidget);

	

}

void UUIMockup_MainWidget::NativePreConstruct()
{

	Super::NativePreConstruct();
	
}