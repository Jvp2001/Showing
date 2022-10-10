// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIMockup_Widget.generated.h"

/**
 * 
 */
UCLASS()
class UIMOCKUPUSERINTERFACE_API UUIMockup_Widget : public UUserWidget
{
	GENERATED_BODY()
public:
#if WITH_EDITOR
	
	virtual const FText GetPaletteCategory() override;
#endif
	
};


