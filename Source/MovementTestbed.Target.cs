using UnrealBuildTool;
using System.Collections.Generic;

public class MovementTestbedTarget : TargetRules
{
	public MovementTestbedTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "MovementTestbed" } );
	}
}
