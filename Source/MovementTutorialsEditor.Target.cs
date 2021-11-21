using UnrealBuildTool;
using System.Collections.Generic;

public class MovementTutorialsEditorTarget : TargetRules
{
	public MovementTutorialsEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "MovementTutorials" } );
	}
}
