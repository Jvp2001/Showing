using UnrealBuildTool;

public class UIMockupGameFramework : ModuleRules
{
    public UIMockupGameFramework(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new []{"UIMockupUserInterface/Public", "UIMockupCommon/Public"});
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "UIMockupUserInterface",
                "UMG",
                "UIMockupCommon",
 "Slate",
                "SlateCore",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
               
            }
        );
    }
}