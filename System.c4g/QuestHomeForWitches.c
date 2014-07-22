
#strict 2
#appendto _STY

static const gQuestHomeForWitchesStageFindEntry = 2;


func CreateQuests()
{
	CreateQuest("HomeForWitches");
	_inherited();
}

func DscQuestHomeForWitches( bool bPhases )
{
	if( bPhases ) return[
	              	   // Dummy-Stage
	              	   [1,0,0],
	            	   // Dummy-Stage
	            	   [2,0,0],

	                     ];

	return [ "Ein Heim für Hexen" ];
}
