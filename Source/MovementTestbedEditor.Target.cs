using UnrealBuildTool;
using System.Collections.Generic;

public class MovementTestbedEditorTarget : TargetRules
{
	public MovementTestbedEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "MovementTestbed" } );
	}
}
