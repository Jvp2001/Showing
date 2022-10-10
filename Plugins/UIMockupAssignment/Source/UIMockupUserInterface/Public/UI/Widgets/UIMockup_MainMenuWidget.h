// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIMockup_MenuWidget.h"
#include "UIMockup_MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class UIMOCKUPUSERINTERFACE_API UUIMockup_MainMenuWidget : public UUIMockup_MenuWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void PlayGame();
	UFUNCTION()
	void ExitGame();

	UFUNCTION()
	void GotoOptions();
	

	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess))
	class UButton* PlayButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess))
	class UButton* OptionsButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess))
	class UButton* ExitButton;

	friend class UUIMockup_MainWidget;
	
};
