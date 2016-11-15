// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class geVision : ModuleRules
{
	public geVision(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }
        
        // Link with OpenCV
        PublicIncludePaths.Add("/usr/local/include");
        PublicAdditionalLibraries.Add("/usr/local/lib/libopencv_core.dylib");
        PublicAdditionalLibraries.Add("/usr/local/lib/libopencv_highgui.dylib");
        PublicAdditionalLibraries.Add("/usr/local/lib/libopencv_imgproc.dylib");
        PublicAdditionalLibraries.Add("/usr/local/lib/libopencv_features2d.dylib");
        PublicAdditionalLibraries.Add("/usr/local/lib/libopencv_nonfree.dylib");
	}
}
