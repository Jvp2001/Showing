// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/UIMockup_Widget.h"

#define LOCTEXT_NAMESPACE "UIMockup_ComplexUIComponentWidget"
#if WITH_EDITOR

const FText UUIMockup_Widget::GetPaletteCategory()
{
		 return LOCTEXT("PaletteCategory", "UI Mockup Widgets");
	
}

#endif

#undef LOCTEXT_NAMESPACE
