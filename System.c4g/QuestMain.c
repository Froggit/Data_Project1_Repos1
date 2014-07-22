
#strict 2
#appendto _STY

static const gQuestMainStageSearch = 23;

static gQuestMain_Info_Bernika;
static gQuestMain_Info_Alvelin;
static gQuestMain_Info_Armin;

func CreateQuests()
{
	CreateQuest("MainQuest");
	_inherited();
}

static gIntroPlayed;
/*
func DscQuestTestQuest1( bool bPhases )
{
	if( bPhases ) return[[1,"true",	[
	                               	 "pQuest->SetStage(2,0,true)"
	                               	 ],1],
	                     			// Dummy-Stage
	                     [2,0,0]];
	return [ "Des Bäckers neue Hosen", 1 ]; // schläft
}

func DscQuestTestQuest2( bool bPhases )
{
	if( bPhases ) return[[1,"true",	[
	                               	 "pQuest->SetStage(2,0,true)"
	                               	 ],1],
	                     			// Dummy-Stage
	                     [2,0,0]];
	return [ "Kräuterpilze", 1 ]; // schläft
}
*/
func DscQuestMainQuest( bool bPhases )
{
	if( bPhases )
		return [
			// die Quest Startet: Intro abspielen
			// Teil 1: Einfaden
			[1,"true",	[
			          	"SetTime(0,20,0,0)", // es ist 20 Uhr
			          	"CreateObject(_SUL,160,650,-1)",
						"StartFilm()",
						"GetFilm()->PosCam(pActivePlayer,0,true)",
						"GetFilm()->FilmFadeDark()",
						"GetFilm()->SetName(\"\")",
						"GetFilm()->SetColorDw(RGB(200,0,0))",
						"GetFilm()->SetDialogue(\"IntroDlg1\")",
						"GetFilm()->StartDialogue(GetFilm())",
						//"ProtectedCall(FindObject(_CHO),\"Initialize\")",
						"pQuest->SetStage(2,0,true)"
					],1],
			// Dummy-Stage
			[2,0,0],
			[3,"true",[
					"GetFilm()->FilmFadeIn()",
					"Log(\"Zeige das Intro\")",
					"AddPlrViewRange(150,gNPCQueen)",
					"pQuest->SetStage(4,0,true)"
			],1],
			// warten, bis der Bildschirm sichtbar ist
			[4,"GetFilmFade()>=255",[
				"pQuest->SetStage(5,0,true)"
			],1],
			// der Magier erscheint
			[5,"true",[
				"gNPCGrandmaster->SetPosition(160,630)",
				"gNPCGrandmaster->SetClrModulation(RGBa(255,255,255,255))",
				"gNPCGrandmaster->SetDir()",
				"gNPCGrandmaster->SetName(\"???\")",
				"AddPlrViewRange(50,gNPCGrandmaster)",
				"ForceFlyStart(gNPCGrandmaster)",
				"AddLightFlash(300,160,630,RGB(100,255,255))",
				"AddSpawnEffect(gNPCGrandmaster,RGBa(0,100,255,40),[\"PSpark2\",RGBa(100,255,255),7,0])",
				"AddSpawnEffect(gNPCGrandmaster,RGBa(0,100,255,40),[\"NoGravSpark\",RGBa(100,255,255),6,1])",
				"Schedule(\"pQuest->~SetStage(7,0,true)\",70)",
				"Sound(\"Drama\",0,gNPCGrandmaster)",
				"pQuest->SetStage(2,0,true)"
			],1],
			//[6,0,0],
			// der Magier ist sichtbar und schwebt jetzt
			[7,"true",[
			           "ForceFlyStop(gNPCGrandmaster)",
			           "ForceFlyStart(gNPCGrandmaster,10)",
			            "gNPCGrandmaster->SetAction(\"HoverCast\")",
						"Schedule(\"pQuest->~SetStage(9,0,true)\",40)",
						"pQuest->SetStage(2,0,true)"
			           ],1],
			//[8,0,0],
			// kurzer Dialog des Magiers
			[9,"true",[
						"GetFilm()->SetDialogue(\"IntroDlg2\")",
						"GetFilm()->StartDialogue(GetFilm())",
						"pQuest->SetStage(2,0,true)"
			           ],1],
			// kurz warten!!
			[10,"true",[
			            "Schedule(\"pQuest->~SetStage(18,0,true)\",30)",
			            "pQuest->SetStage(2,0,true)"
			            ],1],
			// der Held läuft los
			[18,"true",[
						"SetCommand(pActivePlayer,\"MoveTo\",0,200,690)",
			            "Schedule(\"pQuest->~SetStage(19,0,true)\",15)",
			            "pQuest->SetStage(2,0,true)"
					    ],1],
			// der Magier schiesst
			[19,"true",[
				        "FinishCommand(pActivePlayer,true)",
				        "SetComDir(COMD_Stop,pActivePlayer)",
			            "CreateObject(ABLA,GetX(gNPCGrandmaster),GetY(gNPCGrandmaster),-1)->ActivateAngle(gNPCGrandmaster, Angle(GetX(gNPCGrandmaster),GetY(gNPCGrandmaster),GetX(pActivePlayer),GetY(pActivePlayer)))",
			            "Schedule(\"pQuest->~SetStage(11,0,true)\",25)",
						"Schedule(\"gpIntroCandle1->~SetLightOff()\",10)",
						"Schedule(\"gpIntroTorch->~SetLightOff()\",20)",
			            "pQuest->SetStage(2,0,true)"
					    ],1],
		    // Traktorstrahl! Weee :)
			[11,"true",[
					   "SetCommand(pActivePlayer,\"MoveTo\",0,250,690)",
					   "Sound(\"Magic\",0,gNPCGrandmaster)",
			           "GetStory()->~MainQuestIntroBeamStart()",
			           "Schedule(\"pQuest->~SetStage(12,0,true)\",35)",
			           "pQuest->SetStage(2,0,true)"
			           ],1],
			// Sie fängt an zu fliegen
			[12,"true",[
			            "ForceFlyTo(GetX(gNPCGrandmaster)-10,GetY(gNPCGrandmaster),gNPCQueen,5,7)",
			            "Sound(\"PrincessScream\",0,gNPCQueen)",
						"Schedule(\"CreateObject(MFWV,0,0,-1)->Activate(gNPCGrandmaster,gNPCGrandmaster)\",50)",
						"Schedule(\"gpIntroCandle2->~SetLightOff()\",58)",
						"Schedule(\"gpIntroCandle3->~SetLightOff()\",61)",
						"Schedule(\"gpIntroChandelier->~SetLightOff()\",55)",
						"SetCommand(pActivePlayer,\"MoveTo\",0,200,690)",
			            "pQuest->SetStage(13,0,true)"
			            ],1],
			// Prüfen, ob sie beim Magus ist, dann wegfliegen
			[13,"ObjectDistance(gNPCGrandmaster,gNPCQueen)<=25", "pQuest->SetStage(14,0,true)" ,1],
			[14,"true",[
						"FinishCommand(pActivePlayer,true)",
				        "SetComDir(COMD_Stop,pActivePlayer)",
				        "Schedule(\"pQuest->~SetStage(15,0,true)\",15)",
			            "pQuest->SetStage(2,0,true)"
			            ],1],
			[15,"true",[
			            "SetDir(1,gNPCGrandmaster)",
			            "Sound(\"laughter\",0,gNPCGrandmaster)",
						"Schedule(\"pQuest->~SetStage(16,0,true)\",25)",
						"pQuest->SetStage(2,0,true)"
						],1],
			// er verschwindet wieder
			[16,"true",[
			           "ForceFlyStop(gNPCGrandmaster)",
			           "ForceFlyStart(gNPCGrandmaster)",
			           "gNPCGrandmaster->SetAction(\"JumpMagic\")",
					   "AddLightFlash(300,160,630,RGB(100,255,255))",
					   "AddSpawnEffect(gNPCGrandmaster,RGBa(0,100,255,40),[\"PSpark2\",RGBa(100,255,255),7,0])",
					   "AddSpawnEffect(gNPCGrandmaster,RGBa(0,100,255,40),[\"NoGravSpark\",RGBa(100,255,255),6,0])",
			           "Schedule(\"pQuest->~SetStage(17,0,true)\",35)",
					   "pQuest->SetStage(2,0,true)"
			           ],1],
			// Teleport! Woohoo!
			[17,"true",[
			            "Global(0) || Global(0)->Remove()",
				        "ForceFlyStop(gNPCGrandmaster)",
				        "ForceFlyStop(gNPCQueen)",
				        "SetPosition(1410,70,gNPCQueen)",
				        "SetPosition(1410,70,gNPCGrandmaster)",
				        "Schedule(\"pQuest->~SetStage(20,0,true)\",35)",
				        "pQuest->SetStage(2,0,true)"
			            ],1],
			// kurzer Dialog des/der Helden
			[20,"true",[
						"GetFilm()->SetDialogue(\"IntroDlg3\")",
						"GetFilm()->StartDialogue(GetFilm())",
						"pQuest->SetStage(2,0,true)"
			           ],1],
			// kurzer Dialog des/der Helden
			[21,"true",[
						//"StopFilm()",
						"pQuest->SetStage(22,0,true)"
				         ],1],
			// der Magier soll im Thronsaal stehen
			[22,["Inside(GetX(gNPCCourtmage),210,230)","Inside(GetY(gNPCCourtmage),680,700)","!GetCommand(gNPCCourtmage)"],[
					"GetFilm()->SetDialogue(\"IntroDlg4\")",
					"GetFilm()->StartDialogue(GetFilm())",
					"pQuest->SetStage(23,0,true)"
					],20],
			// neue (Dummy-)Phase: Suche nach dem Magier
			[23,0,0],
			// Intro abbrechen
			[999,"true",[
					"Log(\"Intro abgebrochen\")",
					"pQuest->SetStage(-1,0,true)"
			],1000]
			// Dummy-Stage
			//[5,0,0]
		];

	return [ "Königin in Not", 1 ]; // startet automatisch, ohne Bedingungen
}

func MsgDialogueIntroDlg1() { return [
	[0,-1,0,"Intro-Text hier einfügen :)",0,MCMC,[false,0,0,0,false,-1,"Armalion II"]],
		[1,0,"Weiter","",0,[LMM2,0,0,2,4],-1,0,["FindQuest(\"MainQuest\")->SetStage(3,0,true)", "StopDialogue(pTarget)" ]],
		[2,0,"Überspringen","",0,[LMM2,0,0,2,6],-1,0,["GetStory()->~MainQuestSkipIntro()", "StopDialogue(pTarget)" ]]
];}

func MainQuestSkipIntro()
{
	GetFilm()->FilmFadeIn();
	GetFilm()->CloseMenu();
    SetPosition(1410,70,gNPCQueen);
    SetPosition(1410,70,gNPCGrandmaster);
	/*
	FindQuest("MainQuest")->SetStage(17,0,true);

	gpIntroCandle1->~SetLightOff();
	gpIntroCandle2->~SetLightOff();
	gpIntroCandle3->~SetLightOff();
	gpIntroTorch->~SetLightOff();
	gpIntroChandelier->~SetLightOff();
	*/

	FindQuest("MainQuest")->SetStage(23,0,true);

	gpIntroChandelier->~SetLightOff();
	SetPosition(210,690,gPCPlayer);
	SetPosition(96,680,gNPCCourtmage);
	SetDir(1,gNPCCourtmage);
	AddLightPos(200,160,640,RGB(100,255,255))->SetFlicker(1);
	StopFilm();

	var szQuestToLog="MainQuest";

	var pSpeaker = gPCPlayer;
	var szText = "Verdammt, dieser Magier hat die Königin entführt...";
	AddQuestLog(szQuestToLog,[Format("<c %x>%s:</c>", GetColorDlg(pSpeaker), GetName(pSpeaker)),szText],pSpeaker,true);

	szText = "Jetzt heißt es erst mal rausfinden wer das war und wohin er verschwunden ist!";
	if(gPCPlayer2) pSpeaker=gPCPlayer2;
	AddQuestLog(szQuestToLog,[Format("<c %x>%s:</c>", GetColorDlg(pSpeaker), GetName(pSpeaker)),szText],pSpeaker,true);

	pSpeaker = gNPCCourtmage;
	szText ="Ihr könnt mir helfen. Jetzt muss ich erst Nachforschungen betreiben, aber ich kann nicht alles alleine schaffen, vor allem nicht in kurzer Zeit.";
	AddQuestLog(szQuestToLog,[Format("<c %x>%s:</c>", GetColorDlg(pSpeaker), GetName(pSpeaker)),szText],pSpeaker,true);


/*
	AddQuestLog("MainQuest",["Notiz","1 Hallo wwwwwwwwwwwwwww aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb cccccccccccccccccccccccccccccccccccccc dddddddddddddddddddddddddddddd eeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwi"],0,true);
	AddQuestLog("MainQuest",["Notiz","2 Hallo wwwwwwwwwwwwwww aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb cccccccccccccccccccccccccccccccccccccc dddddddddddddddddddddddddddddd eeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwi"],0,true);
	AddQuestLog("MainQuest",["Notiz","3 Hallo wwwwwwwwwwwwwww aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb cccccccccccccccccccccccccccccccccccccc dddddddddddddddddddddddddddddd eeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwi"],0,true);
	AddQuestLog("MainQuest",["Notiz","4 ||||| auch"],0,true);
	AddQuestLog("MainQuest",["Notiz","5 Hallo wwwwwwwwwwwwwww aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb cccccccccccccccccccccccccccccccccccccc dddddddddddddddddddddddddddddd eeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwi"],0,true);
	//AddQuestLog("MainQuest",["Notiz","6 Hallo wwwwwwwwwwwwwww aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb cccccccccccccccccccccccccccccccccccccc dddddddddddddddddddddddddddddd eeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwi"],0,true);

	AddQuestLog("TestQuest1",["Bäcker","Ich will neue Hosen!"],0,true);
	AddQuestLog("TestQuest1",["Held","Die gebe ich Dir||||||||||vielleicht!"],0,true);
	AddQuestLog("TestQuest1",["Bäcker","Ja tu das!"],0,true);
	AddQuestLog("TestQuest1",["Held","Hier hast Du sie"],0,true);
	AddQuestLog("TestQuest1",["Bäcker","Woohoo!"],0,true);
	AddQuestLog("TestQuest1",["Belohnung","30 {{GOLD}}"],0,true);

	AddQuestLog("TestQuest2",["Held","Hey, ich hab da diese Pilze gefunden!"],0,true);
	AddQuestLog("TestQuest2",["{{MUSH}}","Ich bin ziemlich lecker, aber probier mich zusammen mit Insekten aus"],0,true);
	AddQuestLog("TestQuest2",["Held","Sprechende Pilze? w00t"],0,true);
*/
}

func MainQuestIntroBeamStart()
{
	var projectile = CreateObject(MBLB,GetX(gNPCQueen),GetY(gNPCQueen),-1);
	var line = CreateObject(S_10,GetX(gNPCQueen),GetY(gNPCQueen),-1);
	Global(0) = line; // ein kleiner Hack, sollte nicht so schlimm sein
	Local(9,line)=1;
	PrivateCall(projectile,"DrawVertexLine",line, GetX(gNPCGrandmaster), GetY(gNPCGrandmaster), GetX(gNPCQueen), GetY(gNPCQueen), 10);
	ObjectSetAction(line, "Connect2", gNPCQueen, gNPCGrandmaster);
	RemoveObject(projectile);
}

func MsgDialogueIntroDlg2() { return [
    [0,-1,0,"Jetzt habe ich euch!","gNPCGrandmaster",MCMC],
	//[1,0,"Weiter","Niemals!","gPCPlayer",[LMM2,0,0,2,4],0,0,["FindQuest(\"MainQuest\")->SetStage(10,0,true)", "StopDialogue(pTarget)" ]]
	//[1,0,"Weiter","Niemals!","gPCPlayer",[LMM2,0,0,2,4],[true,0,0,0,true],0,["FindQuest(\"MainQuest\")->SetStage(10,0,true)", "StopDialogue(pTarget)" ]]
	[1,0,"Weiter","Niemals!","gPCPlayer",[LMM2,0,0,2,4],0,0,0],
	[2,1,"Weiter","",0,[LMM2,0,0,2,4],-1,0,["FindQuest(\"MainQuest\")->SetStage(10,0,true)", "StopDialogue(pTarget)" ]]

];}

func MsgDialogueIntroDlg3() { return [
    [0,-1,0,"Verdammt, dieser Magier hat die Königin entführt...","gPCPlayer",MCMC,[true,0,0,0,false,0,0,"MainQuest",true]],
	[1,0,"Weiter","Jetzt heißt es erst mal rausfinden wer das war und wohin er verschwunden ist!","gPCPlayer2",[LMM2,0,0,2,4],[true,0,0,0,false,0,0,"MainQuest",true],"!!gPCPlayer2",0],
	[2,0,"Weiter","Jetzt heißt es erst mal rausfinden wer das war und wohin er verschwunden ist!","gPCPlayer" ,[LMM2,0,0,2,4],[true,0,0,0,false,0,0,"MainQuest",true],"!gPCPlayer2",0],
	[3,[1,2],"Weiter","",0,[LMM2,0,0,2,4],-1,0,["FindQuest(\"MainQuest\")->SetStage(21,0,true)", "StopDialogue(pTarget)","GetStory()->MainQuestIntroCallNestor()" ]]
];}

func MainQuestIntroCallNestor()
{
	// der Magier soll die Treppe runterlaufen
	SetName("Magier",gNPCCourtmage);
	SetCommand(gNPCCourtmage,"MoveTo",0, 220, 690);
	//SetQuestVar("MainQuest","bTalkToNestor",true);
	//SetStartDialogue( gNPCCourtmage, 1 );
}

func MsgDialogueIntroDlg4() { return [
		// Anfangsdialog, wenn man er nach der Königin fragt
		[0,-1,0,"He, was ist da los? Wo ist die Königin?","gNPCCourtmage"],
			// Verzweigung: sind die Helden Trottel oder nicht? :P
			[2,0,"Das würde ich selbst gerne wissen!","Was?! Ihr wart doch hier, oder nicht? Jetzt erzählt nochmal ganz langsam, was passiert ist","gNPCCourtmage"],
				[3,[2,4],"Die Königin wurde entführt","Gut, das erklärt schonmal, wieso sie nicht anwesend ist. Weiter?","gNPCCourtmage",0,0,"!LocalN2(\"bTellQueen1\",pSpeaker)",["CreateLocalN2(\"bTellQueen1\",pSpeaker)","LocalN2(\"bTellQueen1\",pSpeaker)=1"]],
				[4,[2,3],"Ein Magier hat sich herteleportiert","Ah, das ist ungewöhnlich. Weiter?","gNPCCourtmage",0,0,"!LocalN2(\"bTellQueen2\",pSpeaker)",["CreateLocalN2(\"bTellQueen2\",pSpeaker)","LocalN2(\"bTellQueen2\",pSpeaker)=1"]],
				[5,[3,4],"Das war alles","Na gut, da Ihr es nicht zusammenhängend erläutern könnt:|Der Magier hat die Königin entführt?","gNPCCourtmage",0,0,"LocalN2(\"bTellQueen2\",pSpeaker) && LocalN2(\"bTellQueen1\",pSpeaker)"],
					[6,5,"Ja, genau so war es!","",0, [ 0, 0, 0, 0, 0, 8+1]  ],
			[7,0,"Ein Magier hat sich in den Thronsaal teleportiert und die Königin entführt","",0, [ 0, 0, 0, 0, 0, 8+1]  ],
			// so hier hört die erste Verzweigung auf
			[8,-1,0,"Das ist eine ernste Sache. Ich werde sehen, was ich machen kann, um die Königin zu befreien.","gNPCCourtmage"],
			    // hier kann man einige Fragen stellen, danach gehts zur Belohnung
				[12,[8,13,15,9,10,11],"Wo wart Ihr eigentlich zum Zeitpunkt der Entführung?","Ich war in meinem Labor im zweiten Stock. Die Sternkonstellation heute Nacht ist sehr interessant, deshalb habe ich nicht am Ball teilgenommen. Wird das ein Verhör?","gNPCCourtmage",0,0,
							// if
							"!LocalN2(\"bAskQueen2\",pSpeaker)",
							// then
								["CreateLocalN2(\"bAskQueen2\",pSpeaker)",
								 "LocalN2(\"bAskQueen2\",pSpeaker)=1"]],
				[13,[8,12,15,9,10,11],"Könnt Ihr herausfinden, wohin der Magier die Königin gebracht hat?","Ihr sagtet, dass er sich teleportiert hat. Soetwas hinterlässt immer eine magische Spur,|die kann ich zu seinem ungefähren Aufenthaltsort zurückverfolgen.","gNPCCourtmage",0,0,
							// if
							"!LocalN2(\"bAskQueen3\",pSpeaker)",
										// then
											["CreateLocalN2(\"bAskQueen3\",pSpeaker)",
											 "LocalN2(\"bAskQueen3\",pSpeaker)=1"]],
				[14,[8,13,12,15,9,10,11],"Habt Ihr eine Ahnung, wer der Magier sein könnte?","Nein, leider nicht, ich war ja nicht dabei. Könnt Ihr ihn beschreiben?","gNPCCourtmage",0,0,
							// if
							"!LocalN2(\"bAskQueen4\",pSpeaker)",
										// then
											["CreateLocalN2(\"bAskQueen4\",pSpeaker)",
											 "LocalN2(\"bAskQueen4\",pSpeaker)=1"]],
					[15,14,"BESCHREIBUNG","Sehr ungewöhnlich. Ich habe noch nie von solch einem Magier gehört.","gNPCCourtmage",0,0,
								// if
								"LocalN2(\"bAskQueen4\",pSpeaker) && !LocalN2(\"bAskQueen5\",pSpeaker)",
											// then
												["CreateLocalN2(\"bAskQueen5\",pSpeaker)",
												 "LocalN2(\"bAskQueen5\",pSpeaker)=1"]],
				// das ist der Hilfe-Dialog, überspringt die Fragen
				[   9,[8,13,15,12],"Was kann ich tun?","",0,[ 0, 0, 0, 0, 0, 11+1],0,
							// if
							["!LocalN2(\"bAskQueen1\",pSpeaker)","!gPCPlayer2"],
							// then
									["CreateLocalN2(\"bAskQueen1\",pSpeaker)",
									 "LocalN2(\"bAskQueen1\",pSpeaker)=1"]],
				[10,[8,13,15,12],"Was können wir tun?","",0,[ 0, 0, 0, 0, 0, 11+1],0,
							// if
							["!LocalN2(\"bAskQueen1\",pSpeaker)","!!gPCPlayer2"],
							// then
									["CreateLocalN2(\"bAskQueen1\",pSpeaker)",
									 "LocalN2(\"bAskQueen1\",pSpeaker)=1"]],
					[11,-1,0,"Ihr könnt mir helfen. Jetzt muss ich erst Nachforschungen betreiben, aber ich kann nicht alles alleine schaffen, vor allem nicht in kurzer Zeit.","gNPCCourtmage",0,[true,0,0,0,false,0,0,"MainQuest",true],0,
									// then
									["CreateLocalN2(\"bAskQueen6\",pSpeaker)",
									 "LocalN2(\"bAskQueen6\",pSpeaker)=1"]],
					[16,[13,14,15,9,10,12,11],"Ich werde Euch helfen!","Danke! Männer wie Euch braucht das Land!|Übrigens, ich bin Nestor, der Hofmagier.","gNPCCourtmage",0,0,"LocalN2(\"bAskQueen6\",pSpeaker)"],
					[17,16,"Sehr erfreut!","Bevor Ihr euch vorstellt, lasst es mich etwas gemütlicher machen.","gNPCCourtmage",0,[true,0,0,0,true],0,["SetName(\"Nestor\",gNPCCourtmage)","StopDialogue(pTarget)","GetStory()->MainQuestIntroNestorLights()"/*,"StopFilm()"*/]]

		//[998,-1,"Abbrechen","",0,[MCMX,0,0,0,0,-1],-1,0,"StopDialogue(pTarget)"]
];}

func MainQuestIntroNestorLights()
{
	gNPCCourtmage->SetComDir(COMD_Left);
	//Schedule("gNPCCourtmage->SetAction(\"Magic\")",14);
	Schedule("gpIntroCandle1->~SetLightOn()",25);
	Schedule("gpIntroCandle2->~SetLightOn()",45);
	Schedule("gpIntroCandle3->~SetLightOn()",65);
	Schedule("gNPCCourtmage->SetComDir(COMD_Stop)",75);
	Schedule("gNPCCourtmage->SetDir(1)",77);
	Schedule("gNPCCourtmage->SetAction(\"Magic\")",90);
	Schedule("gpIntroTorch->~SetLightOn()",106);
	Schedule("AddLightPos(200,160,640,RGB(0,100,255))->SetFlicker(1)",106);
	Schedule("StopFilm()",110);
}
