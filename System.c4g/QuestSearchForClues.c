
#strict 2
#appendto _STY

func CreateQuests()
{
	CreateQuest("SearchForClues");
	_inherited();
}

func DscQuestTemplate( bool bPhases )
{
	if( bPhases ) return[];

	return [ "{{WPPL}} Spurensuche" ];
}
