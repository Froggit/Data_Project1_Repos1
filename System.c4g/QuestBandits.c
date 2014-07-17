
#strict 2
#appendto _STY

func CreateQuests()
{
	CreateQuest("Bandits");
	Log("Created Bandit Quest");
	_inherited();
}

func DscQuestBandits( bool bPhases )
{
	if( bPhases ) return[];

	return [ "Das Banditennest" ];
}