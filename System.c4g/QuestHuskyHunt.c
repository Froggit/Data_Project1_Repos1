
#strict 2
#appendto _STY

static gQuestHuskyHunt_Husky;
static gQuestHuskyHunt_HuskyDead;

func DscQuestHuskyHunt( bool bPhases )
{
	if( bPhases ) return[
	             		[1,"IsNight()",["pQuest->~SetStage(2,0,true)",]], // Dummy-Stage
	             		[2,"true",[
	             		       "gQuestHuskyHunt_Husky=CreateObject(HSKY,0,0,-1)",
	             		       "gQuestHuskyHunt_Husky->SetPosition(2193,735)",
	             		       "FadeInNew(gQuestHuskyHunt_Husky,0,true,20))",
	             		       "pQuest->~SetStage(3,0,true)",]],
	             		[3,"true","GetStory()->~HuskyHuntCheck()"],
	             		[4,"true",[
	             			      "pQuest->~SetStage(-1,pActivePlayer)",        // für den aktiven wird sie wieder erfolgreich
	             			      "pQuest->~SetStage(-2,pActivePlayer,true)"	// für alle ist die Quest gescheitert
	             		           ]]
	                     ];

	return [ "Die Waldbestie" ];
}

func HuskyHuntCheck()
{
	if (!gQuestHuskyHunt_Husky) return;
	if (!(gQuestHuskyHunt_Husky->~GetAlive()))
	{
		SetQuestStage("HuskyHunt",4,0,true);
		return;
	}

	if (IsDay())
	{
		Log("Fading out Husky");
		FadeOutNew(gQuestHuskyHunt_Husky,255,true,20);
		SetQuestStage("HuskyHunt",1,0,true);
	}
}
