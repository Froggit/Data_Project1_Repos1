
#strict 2
#appendto _STY

static gObjWhip, g_bProstHasWhip, g_bProstFree;

func DscQuestWhipped( bool bPhases )
{
	if( bPhases ) return[
		         			// Dummy-Stage
		         			[1,0,0],
		         			[2,0,0],
		         			// Peitsche abgegeben -> Belohnung erhalten
		         			// nicht-materielle Belohnung
		         			[3,"true",[
		         			      "pQuest->~GiveReward(pActivePlayer,\"pPlayer->~DoMoney(50)\")",	// der Spieler kriegt 50 Gold, die anderen nichts
		         			      "pQuest->~SetStage(-1,pActivePlayer)",							// für den aktiven wird sie wieder erfolgreich
		         			      "pQuest->~SetStage(-2,pActivePlayer,true)",								// für alle ist die Quest gescheitert
		         			      ],1],
		         			// nicht-materielle Belohnung
		         			[4,"true",[
		         			      "pQuest->~GiveReward(pActivePlayer,\"pPlayer->~DoMoney(50)\")",	// der Spieler kriegt 50 Gold, die anderen nichts
		         			      "pQuest->~SetStage(-1,pActivePlayer)",							// für den aktiven wird sie wieder erfolgreich
		         			      "pQuest->~SetStage(-2,pActivePlayer,true)",								// für alle ist die Quest gescheitert
		         			      ],1]
		                     ];


	return [ "Ausgefallene Wünsche." ];
}
