// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "UIMockup_Button.generated.h"

/**                              
 */
UCLASS()
class UIMOCKUPUSERINTERFACE_API UUIMockup_Button : public UButton
{
	GENERATED_BODY()
public:
   UUIMockup_Button(const FObjectInitializer& ObjectInitializer);
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif
	
	
};
