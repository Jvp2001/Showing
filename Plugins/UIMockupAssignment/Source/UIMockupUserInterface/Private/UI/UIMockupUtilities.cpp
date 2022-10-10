#include "UI/UIMockupUtilities.h"

#include "Styling/SlateWidgetStyleAsset.h"
#include "UObject/ConstructorHelpers.h"
#include "UIMockupSettings.h"


FString UUIMockupUtilities::GetStylesPath(UObject* WorldContextObject)
{

	auto UISettings = GetDefault<UUIMockupSettings>();
	check(UISettings);
	FString Path =  UISettings->GetWidgetStylesPath();
	checkf(!Path.IsEmpty(), TEXT("Path Cannot be empty!"));
	return Path;

}

FString UUIMockupUtilities::CreateStyleAssetPath(UObject* WorldContextObject, const FStringView AssetName)
{
	FString StylesPath = GetStylesPath(WorldContextObject);
	StylesPath += "/";
	StylesPath += AssetName;
	return StylesPath;
}
USlateWidgetStyleAsset* UUIMockupUtilities::GetStyleAsset(UObject* WorldContextObject, const FStringView AssetName)
{
	const FString StyleAssetPath = CreateStyleAssetPath(WorldContextObject, AssetName);
	const ConstructorHelpers::FObjectFinder<USlateWidgetStyleAsset> SlateStyleAsset(*StyleAssetPath);
	return SlateStyleAsset.Object;
}
USlateWidgetStyleAsset* UUIMockupUtilities::GetStyleAssetChecked(UObject* WorldContextObject, const FStringView AssetName)
{
	USlateWidgetStyleAsset* SlateStyleAsset = GetStyleAsset(WorldContextObject, AssetName);
	checkf(SlateStyleAsset, TEXT("StyleSheet: %s was not found!"), *SlateStyleAsset->GetName())
	return SlateStyleAsset;
}
