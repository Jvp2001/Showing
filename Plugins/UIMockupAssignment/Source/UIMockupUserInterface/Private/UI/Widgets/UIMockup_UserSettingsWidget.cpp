// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/UIMockup_UserSettingsWidget.h"

#include "UIMockupGameSettingsSubsystem.h"
#include "UIMockupUserInterface.h"
#include "Components/CheckBox.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/MessageDialog.h"
#include "UI/UIMockupUtilities.h"
#include "UI/Components/UIMockup_ButtonWithText.h"
#include "UI/Components/UIMockup_EditableTextBlock.h"
#include "UI/Widgets/UIMockup_HostJoinMenuWidget.h"

void UUIMockup_UserSettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UIMockupGameSettingsSubsystem = UGameplayStatics::GetGameInstance(this)->GetSubsystem<UUIMockupGameSettingsSubsystem>();
	check(UIMockupGameSettingsSubsystem);

	UsernameTextBlock->SetHintText(FText::FromString(TEXT("Username")));
	UsernameTextBlock->SetText(FText::FromString(TEXT("Player")));
	UsernameTextBlock->OnTextChanged.AddUniqueDynamic(this, &ThisClass::OnUsernameChanged);

	NextButton->OnClicked.AddUniqueDynamic(this, &ThisClass::OnNextButtonClicked);
	NextButton->bIsEnabledDelegate.BindDynamic(this, &ThisClass::IsNextButtonDisabled);
	

	
	
	
}

bool UUIMockup_UserSettingsWidget::IsUsernameValid() const
{
	FRegexMatcher UsernameMatcher(ValidUsernamePattern, UsernameTextBlock->GetText().ToString()); 
	return !UsernameTextBlock->GetText().IsEmpty() and UsernameMatcher.FindNext();
	
}

void UUIMockup_UserSettingsWidget::OnUsernameChanged(const FText& NewText)
{
	if(NewText.IsEmpty()) return;
	UsernameErrorTextBlock->SetVisibility(IsUsernameValid() ? ESlateVisibility::Hidden : ESlateVisibility::Visible);
	UsernameTextBlock->WidgetStyle = IsUsernameValid() ? DefaultUsernameTextBoxStyle : UsernameErrorEditableTextBoxStyle;
}

void UUIMockup_UserSettingsWidget::OnNextButtonClicked()
{

		GetMainWidgetInterfaceChecked()->Goto(UUIMockup_HostJoinMenuWidget::StaticClass()->GetName());
		//TODO: Write Save code here later.
		if(RememberUsernameCheckBox->IsChecked())
			UIMockupGameSettingsSubsystem->SetPlayerName(UsernameTextBlock->GetText().ToString());
	
}

bool UUIMockup_UserSettingsWidget::IsNextButtonDisabled()
{
	return IsUsernameValid();
}
