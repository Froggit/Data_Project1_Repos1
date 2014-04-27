
#strict 2
#appendto _STY

static gObjFishBarrel;
static gDeliveredFishBarrels;

func DscQuestSomethingFishy( bool bPhases )
{
	if( bPhases ) return[
		// Dummy-Stage
		[1,0,0],
		// TODO: eine richtige Belohnung, diese ist aus der Kelch-Quest kopiert
		// Fass abgegeben -> Belohnung erhalten
		[2,"true",[
		      "pQuest->~GiveReward(pActivePlayer,\"pPlayer->~DoMoney(50)\")"	// der Spieler kriegt 50 Gold, die anderen nichts
		      ],1],
		[3,"true",[
		      "pQuest->~GiveReward(pActivePlayer,\"pPlayer->~DoMoney(50)\")",	// der Spieler kriegt 50 Gold, die anderen nichts
		      "pQuest->~SetStage(-1,pActivePlayer)",							// für den aktiven wird sie wieder erfolgreich
		      "pQuest->~SetStage(-2,pActivePlayer,true)"								// für alle ist die Quest gescheitert
		      ],1]
     ];

	return [ "Eine Fuhre Fisch" ];
}
