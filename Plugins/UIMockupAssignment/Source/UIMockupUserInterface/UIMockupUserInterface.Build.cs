using UnrealBuildTool;

public class UIMockupUserInterface : ModuleRules
{
    public UIMockupUserInterface(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        CppStandard = CppStandardVersion.Cpp17;  
        PublicIncludePaths.AddRange(new [] {"UIMockupUserInterface/Public", "UIMockupCommon/Public"});
        PrivateIncludePaths.AddRange(new [] {"UIMockupUserInterface/Private"});
        
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "UIMockupCommon",
                "UMG", 
                


            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
            }
        );
    }
}