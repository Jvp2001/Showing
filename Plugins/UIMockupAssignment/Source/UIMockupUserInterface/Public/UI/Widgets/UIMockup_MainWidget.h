// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIMockup_MainMenuWidget.h"
#include "UI/UIMockupUtilities.h"
#include "UI/Interfaces/UIMockup_MainWidgetInterface.h"
#include "UI/Interfaces/UIMockup_WidgetSwitcherInterface.h"
#include "UObject/Object.h"
#include "UI/Widgets/UIMockup_Widget.h"
#include "UIMockup_MainWidget.generated.h"



//Forward declaring here for clarity.
class UUIMockup_MainMenuWidget;
class UUIMockup_OptionsMenuWidget;
class UUIMockup_AudioSettingsWidget;
class UUIMockup_DisplaySettingsWidget;
class UUIMockup_UserSettingsWidget;
class UUIMockup_HostJoinMenuWidget;
/**
 * 
 */
UCLASS()
class UIMOCKUPUSERINTERFACE_API UUIMockup_MainWidget : public UUIMockup_Widget, public IUIMockup_MainWidgetInterface
{
	GENERATED_BODY()

public:
	//~ IUIMockup_MainWidgetInterface
	virtual void GoBack() const override;
	virtual void OnWidgetSwitched(UUserWidget* NewWidget) override;
	virtual void Goto(const FString& WidgetName) const override;
	//~ End of IUIMockup_MainWidgetInterface

	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	virtual UWidgetSwitcher* GetWidgetSwitcher() const override;
	virtual TMap<FString, UUserWidget*> GetValidWidgets() const override;

protected:
	template <typename TUserWidget>
	TUserWidget* CreateMenuWidget(TSubclassOf<TUserWidget> WidgetClass);
	
	template <class TUserWidget, class ... TUserWidgets>
	void AddAllWidgets(TUserWidget&& First, TUserWidgets&& ... Widgets) const;

	template <typename TUserWidget>
	void AddAllWidgets(TUserWidget&& Widget) const;

	template <class TUserWidget =class UUIMockup_MenuWidget>
void SetMainMenuInterfaces(const TUserWidget*First);

	template <class TUserWidget =class UUIMockup_MenuWidget, class ... TUserWidgets>
	void SetMainMenuInterfaces(const TUserWidget* First, TUserWidgets&& ... Rest);
private:
	/**
	 * @brief Marked as mutable because it's only used in const functions. Furthermore, the UIMockupUtilities::GetInterface function return a const pointer, due to how Epic's Cast function was implemented. 
	 */

	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess))
	mutable TMap<FString, UUserWidget*> ValidWidgets;

	UPROPERTY(EditDefaultsOnly, Category = "UI Mockup")
	 TSubclassOf<UUIMockup_MainMenuWidget> MainMenuWidgetClass; 
	UPROPERTY(BlueprintReadOnly, Category=Widgets, meta=(AllowPrivateAccess)) 
	UUIMockup_MainMenuWidget* MainMenuWidget;
	UPROPERTY(EditDefaultsOnly, Category = "UI Mockup")
	 TSubclassOf<UUIMockup_OptionsMenuWidget> OptionsMenuWidgetClass; 
	
	UPROPERTY(BlueprintReadOnly, Category=Widgets, meta=(AllowPrivateAccess)) 
	UUIMockup_OptionsMenuWidget* OptionsMenuWidget;
	UPROPERTY(EditDefaultsOnly, Category = "UI Mockup")
	 TSubclassOf<UUIMockup_AudioSettingsWidget> AudioSettingsWidgetClass; 
	
	UPROPERTY(BlueprintReadOnly, Category=Widgets, meta=(AllowPrivateAccess)) 
	UUIMockup_AudioSettingsWidget* AudioSettingsWidget;
	UPROPERTY(EditDefaultsOnly, Category = "UI Mockup")
	 TSubclassOf<UUIMockup_DisplaySettingsWidget> DisplaySettingsWidgetClass;
	
	 UPROPERTY(BlueprintReadOnly, Category=Widgets, meta=(AllowPrivateAccess)) 
	 UUIMockup_DisplaySettingsWidget* DisplaySettingsWidget;

	UPROPERTY(EditDefaultsOnly, Category = "UI Mockup")
	TSubclassOf<UUIMockup_UserSettingsWidget> UserSettingsWidgetClass; 
	UPROPERTY(BlueprintReadOnly, Category=Widgets, meta=(AllowPrivateAccess)) 
	UUIMockup_UserSettingsWidget* UserSettingsWidget;
	
	UPROPERTY(EditDefaultsOnly, Category = "UI Mockup")
	 TSubclassOf<UUIMockup_HostJoinMenuWidget> HostJoinMenuWidgetClass; 
	
	UPROPERTY(BlueprintReadOnly, Category=Widgets, meta=(AllowPrivateAccess)) 
	UUIMockup_HostJoinMenuWidget* HostJoinMenuWidget;


	

	/**
	* @brief Marked as mutable because it's only used in const functions. Furthermore, the UIMockupUtilities::GetInterface function return a const pointer, due to how Epic's Cast function was implemented. 
	*/
	UPROPERTY(BlueprintReadOnly, DisplayName="Widget Switcher", meta=(BindWidget, AllowPrivateAccess))
	mutable class UWidgetSwitcher* WidgetManager;

	
	// UPROPERTY(BlueprintReadOnly, Category=Widgets, meta=(AllowPrivateAccess))
	// UUIMockup_MainWidget* MainMenuWidget;
	/**
	* @brief Marked as mutable because it's only used in const functions. Furthermore, the UIMockupUtilities::GetInterface function return a const pointer, due to how Epic's Cast function was implemented. 
	* Using as a stack to keep track of the previous widgets
	*/
	UPROPERTY()
	mutable TArray<class UWidget*> ActiveWidgetHistory;


	/**
	 * This is the widget that will be displayed when the game starts. So the Switch widget system will start from this widget.
	 */
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> RootWidgetClass = UUIMockup_MainMenuWidget::StaticClass();

	friend class IUIMockup_WidgetSwitcher;
};


template <typename TUserWidget>
TUserWidget* UUIMockup_MainWidget::CreateMenuWidget(TSubclassOf<TUserWidget> WidgetClass)
{
	check(WidgetClass)
	TUserWidget* Widget = CreateWidget<TUserWidget>(GetWorld(), WidgetClass);
	if (IUIMockup_WidgetSwitcherInterface* WidgetSwitcher = Cast<IUIMockup_WidgetSwitcherInterface>(Widget))
	{
		WidgetSwitcher->SetMainWidgetInterface(this);
	}
	return Widget;
}


template <typename TUserWidget, typename ... TUserWidgets>
void UUIMockup_MainWidget::AddAllWidgets(TUserWidget&& First, TUserWidgets&&... Widgets)    const
{
	AddAllWidgets(First);
	AddAllWidgets(Widgets...);
}

template <typename TUserWidget>
void UUIMockup_MainWidget::AddAllWidgets(TUserWidget&& Widget) const 
{
	WidgetManager->AddChild(Widget);
	ValidWidgets.Add(Widget->StaticClass()->GetName(), Widget);
	
}

template <class TUserWidget>
void UUIMockup_MainWidget::SetMainMenuInterfaces(const TUserWidget* First)
{
	CastChecked<IUIMockup_WidgetSwitcherInterface>(First)->SetMainWidgetInterface(this);

}

template <class TUserWidget, class ... TUserWidgets>
void UUIMockup_MainWidget::SetMainMenuInterfaces(const TUserWidget* First, TUserWidgets&&... Rest)
{
	SetMainMenuInterfaces(First);
	SetMainMenuInterfaces(Rest...);
}
