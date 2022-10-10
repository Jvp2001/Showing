#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#define UIMOCKUP_COMPONENTS_PALETTE_CATEGORY LOCTEXT("Category", "UI Mockup Components")



DECLARE_LOG_CATEGORY_EXTERN(LogUIMockup, Log, All);

class FUIMockupUserInterfaceModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
