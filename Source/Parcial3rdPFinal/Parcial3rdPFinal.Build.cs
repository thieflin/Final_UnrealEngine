// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Parcial3rdPFinal : ModuleRules
{
	public Parcial3rdPFinal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
