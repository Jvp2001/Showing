#pragma once
#include "CoreMinimal.h"
#include "Interfaces/UIMockup_WidgetSwitcherInterface.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UIMockupUtilities.generated.h"

/**
 * The WorldContextObject pins are just in case I want to expose these static member functions to Blueprint. 
 *
 */

 UCLASS()
class UUIMockupUtilities : public UBlueprintFunctionLibrary
{
 	GENERATED_BODY()
public:
 	

 	
 	UFUNCTION()
 	static FString GetStylesPath(UObject* WorldContextObject);

	                   
	static FString CreateStyleAssetPath(UObject* WorldContextObject, const FStringView AssetName);
    static USlateWidgetStyleAsset* GetStyleAsset(UObject* WorldContextObject, FStringView AssetName);
    static class USlateWidgetStyleAsset* GetStyleAssetChecked(UObject* WorldContextObject, const FStringView AssetName);

 
};
