// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VungleIOS : ModuleRules
{
	public VungleIOS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				"VungleIOS/Public"
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"VungleIOS/Private",
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "Advertising",
				// ... add private dependencies that you statically link with here ...	
			}
			);


        PublicAdditionalFrameworks.Add(
            new UEBuildFramework(
            "VungleSDK",														// Framework name
            "../../ThirdPartyFrameworks/VungleSDK.embeddedframework.zip"		// Zip name
            )
        );

        PublicFrameworks.AddRange(
            new string[]
        {
            "EventKit",
            "MediaPlayer",
            "AdSupport",
            "CoreLocation",
            "SystemConfiguration",
            "MessageUI",
            "Security",
            "CoreTelephony"
        }
        );


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
