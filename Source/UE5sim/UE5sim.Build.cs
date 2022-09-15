// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System;
using System.IO;

public class UE5sim : ModuleRules
{
	public UE5sim(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnforceIWYU = true;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "Wakefield" ,"Sockets" , "Networking"});
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "../../Binaries/Win64/libprotobuf.lib"));
        PrivateDependencyModuleNames.AddRange(new string[] { "GoogleProtocolBuffers" });
    }
}
