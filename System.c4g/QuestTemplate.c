
#strict 2
#appendto _STY

func CreateQuests()
{
	CreateQuest("Template");
	_inherited();
}

func DscQuestTemplate( bool bPhases )
{
	if( bPhases ) return[];

	return [ "Template" ];
}