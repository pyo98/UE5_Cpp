// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Template0607 : ModuleRules
{
	public Template0607(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "UMG", "Slate", "SlateCore" });
	}
}
