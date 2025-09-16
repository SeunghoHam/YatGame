// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class YG : ModuleRules
{
	public YG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"YG",
			"YG/Variant_Platforming",
			"YG/Variant_Platforming/Animation",
			"YG/Variant_Combat",
			"YG/Variant_Combat/AI",
			"YG/Variant_Combat/Animation",
			"YG/Variant_Combat/Gameplay",
			"YG/Variant_Combat/Interfaces",
			"YG/Variant_Combat/UI",
			"YG/Variant_SideScrolling",
			"YG/Variant_SideScrolling/AI",
			"YG/Variant_SideScrolling/Gameplay",
			"YG/Variant_SideScrolling/Interfaces",
			"YG/Variant_SideScrolling/UI",
			
			"YG/Widgtes",
			"YG/Widgtes/Panel",
			"YG/SubSystems",
			"YG/DataAssets"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
