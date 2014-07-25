
#strict 2

static gDrawbridge, gBlimpWorkshop, gBlacksmithHouse, gInn, gFarmhouse, gAdventurerTent, gIgloo1, gIgloo2;
static gNPCQueen, gNPCFarmer, gNPCWitch, gNPCBlacksmith, gNPCInventor, gNPCCitizen, gNPCAdventurer1, gNPCAdventurer2, gNPCInnkeeper, gNPCProstitute ;
static gNPCGuard1, gNPCGuard2, gNPCGuard3, gNPCLumberjack, gNPCInuk1, gNPCInuk2;
static gNPCGrandmaster, gPCPlayer, gPCPlayer2;
static gNPCCourtmage, gpIntroCandle1, gpIntroCandle2, gpIntroCandle3, gpIntroChandelier, gpIntroTorch;

static giPlrEnemy, giPlrFriend;

func Initialize()
{

}

func DoStartSzen()
{

	RemoveAll(TIME);
	CreateObject(DARK,0,0,-1);
	CreateObject(TIME,0,0,-1);

	FindObjects( Find_Func("SetLightOff",1) );
	FindObjects( Find_Func("SetLightOn") );


	giPlrEnemy = 0;
	giPlrFriend = 1;

	gpIntroCandle1 = Object(302);
	gpIntroCandle2 = Object(303);
	gpIntroCandle3 = Object(301);
	gpIntroChandelier = Object(300);
	gpIntroTorch = Object(211);

	gDrawbridge = FindObject(CPT3);

	// Glühwürmchen erstellen

	CreateObject(FFAC, 627, 705, -1);
	CreateObject(FFAC, 1905, 770, -1);
	CreateObject(FFAC, 2170, 745, -1);
	CreateObject(FFAC, 2675, 490, -1);

	// Königin erstellen
	gNPCQueen = CreateObject( _PRC,0,0,giPlrFriend);
	MakeCrewMember( gNPCQueen, giPlrFriend );
	gNPCQueen->SetPosition(40,660);
	gNPCQueen->SetDir(1);
	gNPCQueen->SetName("$NPCQueen$");
	//AttachDialogue(gNPCQueen,"");

	// Hexe erstellen
	gNPCWitch = CreateObject( CLNK,0,0,giPlrFriend );
	MakeCrewMember( gNPCWitch, giPlrFriend );
	gNPCWitch->~SetName("Frau");
	gNPCWitch->~SetPosition(1170,750);
	AttachDialogue(gNPCWitch,"Alvelin");
	CreateContents(TIM1,gNPCWitch); // a dummy such that he does not collect the last barrel after ejecting it
	CreateContents(LAXE,gNPCWitch); // lumberjack's axe for looting the witch

	// Schmied erstellen
	gNPCBlacksmith = CreateObject( CLNK,0,0,giPlrFriend );
	MakeCrewMember( gNPCBlacksmith, giPlrFriend );
	gNPCBlacksmith->~SetName("Heinz");
	gNPCBlacksmith->~SetPosition(1515,770);
	AttachDialogue(gNPCBlacksmith,"Heinz");

	// Erfinder erstellen
	gNPCInventor = CreateObject( CLNK,0,0,giPlrFriend );
	MakeCrewMember( gNPCInventor, giPlrFriend );
	gNPCInventor->~SetName("Ingalf");
	gNPCInventor->SetPosition(865,800);
	AttachDialogue(gNPCInventor,"Ingalf");

	// Bürger erstellen
	gNPCCitizen = CreateObject( CLNK,0,0,giPlrFriend );
	MakeCrewMember( gNPCCitizen, giPlrFriend );
	gNPCCitizen->~SetName("Odilbert");
	gNPCCitizen->SetPosition(1215,750);
	AttachDialogue(gNPCCitizen,"Odilbert");

	// Abenteurer erstellen
	gNPCAdventurer1 = CreateObject( CLNK,0,0,giPlrFriend );
	MakeCrewMember( gNPCAdventurer1, giPlrFriend );
	gNPCAdventurer1->~SetName("Gernot");
	gNPCAdventurer1->SetPosition(2715,495);
	AttachDialogue(gNPCAdventurer1,"Gernot");

	// Abenteurer erstellen
	gNPCAdventurer2 = CreateObject( CLNK,0,0,giPlrFriend );
	MakeCrewMember( gNPCAdventurer2, giPlrFriend );
	gNPCAdventurer2->~SetName("Linnert");
	gNPCAdventurer2->SetPosition(2740,495);
	AttachDialogue(gNPCAdventurer2,"Linnert");

	// Farmer erstellen
	gNPCFarmer = CreateObject( CLNK,0,0,giPlrFriend );
	MakeCrewMember( gNPCFarmer, giPlrFriend );
	gNPCFarmer->~SetName("Armin");
	gNPCFarmer->SetPosition(1840,765);
	AttachDialogue(gNPCFarmer,"Armin");
	AttachDayNightCycle(gNPCFarmer,"Armin");
	CreateContents(TIM1,gNPCFarmer); // a dummy such that he does not collect items

	// Wirtin erstellen
	gNPCInnkeeper = CreateObject( CLNK,0,0,giPlrFriend );
	MakeCrewMember( gNPCInnkeeper, giPlrFriend );
	gNPCInnkeeper->~SetName("Bernika");
	gNPCInnkeeper->SetPosition(1315,750);
	AttachDialogue(gNPCInnkeeper,"Bernika");

	// Dirne erstellen
	gNPCProstitute = CreateObject( CLNK,0,0,giPlrFriend );
	MakeCrewMember( gNPCProstitute, giPlrFriend );
	gNPCProstitute->~SetName("Rovena");
	gNPCProstitute->SetPosition(1435,770);
	AttachDialogue(gNPCProstitute,"Rovena");

	// Wache erstellen
	gNPCGuard1 = CreateObject( CLNK,0,0,giPlrFriend );
	MakeCrewMember( gNPCGuard1, giPlrFriend );
	gNPCGuard1->~SetName("Helmar");
	gNPCGuard1->SetPosition(1615, 769);
	gNPCGuard1->SetDir(1);
	AttachDialogue(gNPCGuard1,"Helmar");

	// Wache erstellen
	gNPCGuard2 = CreateObject( CLNK,0,0,giPlrFriend );
	MakeCrewMember( gNPCGuard2, giPlrFriend );
	gNPCGuard2->~SetName("Eboreus");
	gNPCGuard2->SetPosition(395,690);
	AttachDialogue(gNPCGuard2,"Eboreus");

	// Wache erstellen
	gNPCGuard3 = CreateObject( CLNK,0,0,giPlrFriend );
	MakeCrewMember( gNPCGuard3, giPlrFriend );
	gNPCGuard3->~SetName("Radulf");
	gNPCGuard3->SetPosition(225, 448);
	AttachDialogue(gNPCGuard3,"Radulf");

	// Holzfäller erstellen
	gNPCLumberjack = CreateObject( CLNK,0,0,giPlrFriend );
	MakeCrewMember( gNPCLumberjack, giPlrFriend );
	gNPCLumberjack->~SetName("Answin");
	gNPCLumberjack->SetPosition(2000,755);
	AttachDialogue(gNPCLumberjack,"Answin");

	// Inuk erstellen
	gNPCInuk1 = CreateObject( CLNK,0,0,giPlrFriend );
	MakeCrewMember( gNPCInuk1, giPlrFriend );
	gNPCInuk1->~SetName("Bardrik");
	gNPCInuk1->SetPosition(3685,45);
	AttachDialogue(gNPCInuk1,"Bardrik");

	// Inuk erstellen
	gNPCInuk2 = CreateObject( CLNK,0,0,giPlrFriend );
	MakeCrewMember( gNPCInuk2, giPlrFriend );
	gNPCInuk2->~SetName("Jallik");
	gNPCInuk2->SetPosition(4465,340);
	AttachDialogue(gNPCInuk2,"Jallik");
	// Er hat 3 Fischfässer
	CreateContents(TIM1,gNPCInuk2); // a dummy such that he does not collect the last barrel after ejecting it
	CreateContents(FBRL,gNPCInuk2);
	CreateContents(FBRL,gNPCInuk2);
	CreateContents(FBRL,gNPCInuk2);

	// Magier erstellen
	gNPCCourtmage = CreateObject( MAGE,0,0,giPlrFriend );
	MakeCrewMember( gNPCCourtmage, giPlrFriend );
	gNPCCourtmage->~SetName("Nestor");
	gNPCCourtmage->SetPosition(200,480);
	AttachDialogue(gNPCCourtmage,"Nestor");


	//////////////////////////////////////////////////////////////

	// Bösen Magier erstellen
	gNPCGrandmaster = CreateObject( MAGE,0,0,giPlrEnemy );
	MakeCrewMember( gNPCGrandmaster, giPlrEnemy );
	gNPCGrandmaster->~SetName("OBW");


	//////////////////////////////////////////////////////////////

	// die Könige der KI-Spieler vernichten
	RemoveAll(KING);

	// erstellen
	//gNPC = CreateObject( CLNK,0,0,giPlrFriend );
	//MakeCrewMember( gNPC, giPlrFriend );
	//gNPC->~SetName("");

	CreateQuest("MainQuest");
	CreateQuest("Bandits");
	CreateQuest("MissingLooters");
	CreateQuest("KingsChalice");
	CreateQuest("DeepTreasure");
	CreateQuest("HuskyHunt");
	CreateQuest("Lumberjack");
	CreateQuest("SomethingFishy");
	CreateQuest("Whipped");
	CreateQuest("FunkyBread");
	//GetStory()->~CreateQuests();


	return;
}

global func StartAllQuests()
{
	ActivateQuest("Bandits",GetHiRank(2));
	ActivateQuest("MissingLooters",GetHiRank(2));
	ActivateQuest("KingsChalice",GetHiRank(2));
	ActivateQuest("DeepTreasure",GetHiRank(2));
	ActivateQuest("HuskyHunt",GetHiRank(2));
	ActivateQuest("Lumberjack",GetHiRank(2));
	ActivateQuest("SomethingFishy",GetHiRank(2));
	ActivateQuest("Whipped",GetHiRank(2));
	ActivateQuest("FunkyBread",GetHiRank(2));
}

global func fafsq()
{
	SetQuestStage("Bandits",-1,GetHiRank(2));
	SetQuestStage("MissingLooters",-1,GetHiRank(2));
	SetQuestStage("KingsChalice",-1,GetHiRank(2));
	SetQuestStage("DeepTreasure",-1,GetHiRank(2));
	SetQuestStage("HuskyHunt",-1,GetHiRank(2));
	SetQuestStage("Lumberjack",-1,GetHiRank(2));
	SetQuestStage("SomethingFishy",-2,GetHiRank(2));
	SetQuestStage("Whipped",-2,GetHiRank(2));
	SetQuestStage("FunkyBread",-2,GetHiRank(2));
}

global func saq()
{
	StartAllQuests();
}

global func pqt()
{
	FindObject(LI_L)->printTree();
}

global func pqe()
{
	FindObject(LI_L)->printEntries();
}

global func qt()
{
	Log("%v",FindObject(LI_L)->LocalN("tree"));
}

global func qd()
{
	return FindObject(LI_L)->LocalN("aDialogue");
}

global func pl()
{
	return FindObject(LI_L);
}

protected func InitializePlayer(int player, int tx, int ty, object pBase, int iTeam)
{
	DoInitPlayer(player);
  return 1;
}


protected func PlayerStart(int player, int tx, int ty, object pBase, int iTeam)
{
	var pClonk = GetCursor(player);
	pClonk->SetPosition(280+RandomX(-30,30), 690);
	pClonk->SetDir(1);
	pClonk->SetPlrViewRange(150);
	if(gPCPlayer) if(!gPCPlayer2) gPCPlayer2 = pClonk;
	if(!gPCPlayer) gPCPlayer = pClonk;
	
	var backpack = CreateObject(PACK,0,0,-1);
	if(backpack)
	{
		pClonk->~AddBackpack("NoMenu",backpack);
	}

	return 1;
}


public func IsFullfilled() { return !FindObject2(Find_ID(CPT3)); }
public func FullfillText() { return "Die Königin ist noch nicht befreit"; }

public func GoalText() { return "Befreie die Königin"; }
