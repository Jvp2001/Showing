#include "UIMockupUserInterface.h"

#define LOCTEXT_NAMESPACE "FUIMockupUserInterfaceModule"
DEFINE_LOG_CATEGORY(LogUIMockup)

void FUIMockupUserInterfaceModule::StartupModule()
{
}

void FUIMockupUserInterfaceModule::ShutdownModule()
{
    
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FUIMockupUserInterfaceModule, UIMockupUserInterface)