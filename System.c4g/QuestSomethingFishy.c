
#strict 2
#appendto _STY

static gObjFishBarrel;
static gDeliveredFishBarrels;
static gBoughtFishBarrels;

static const gFishBarrel_PriceFactor_Reward = 200;
static const gFishBarrel_PriceFactor_Sell = 150;

func DscQuestSomethingFishy( bool bPhases )
{
	if( bPhases ) return[
		// Dummy-Stage
		[1,0,0],
		// TODO: eine richtige Belohnung, diese ist aus der Kelch-Quest kopiert
		// Fass abgegeben -> Belohnung erhalten
		[2,"true",[
		      Format("pQuest->~GiveReward(pActivePlayer,\"pPlayer->~DoMoney(%d)\")",gFishBarrel_PriceFactor_Reward*GetValue(0,FBRL)/100),	// der Spieler kriegt Gold, die anderen nichts
		      "pQuest->~SetStage(1,pActivePlayer)",								// Zur�cksetzen, damit er nicht dauernd Geld kriegt.
		      ],1],
		[3,"true",[
		      Format("pQuest->~GiveReward(pActivePlayer,\"pPlayer->~DoMoney(%d)\")",gFishBarrel_PriceFactor_Reward*GetValue(0,FBRL)/100),	// der Spieler kriegt Gold, die anderen nichts
		      "pQuest->~SetStage(-1,pActivePlayer)",							// f�r den aktiven wird sie wieder erfolgreich
		      "pQuest->~SetStage(-2,pActivePlayer,true)"								// f�r alle ist die Quest gescheitert
		      ],1]
     ];

	return [ "Eine Fuhre Fisch" ];
}
