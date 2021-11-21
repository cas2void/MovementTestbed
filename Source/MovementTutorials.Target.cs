using UnrealBuildTool;
using System.Collections.Generic;

public class MovementTutorialsTarget : TargetRules
{
	public MovementTutorialsTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "MovementTutorials" } );
	}
}
