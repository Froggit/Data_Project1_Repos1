/*-- alle Dialoge --*/

#strict 2
#appendto _STY

static const gDialogue_TalkedToBardrik = "Bardrik";
static const gDialogue_AskedJallikAboutNames = "Jallik";
static const gDialogue_AskedJallikAboutBardrik = "JallikBardrik";
static const gDialogue_BardrikName = "Spa�vogel-Axt-Verk�ufer";//"�xte-Verschenker-und-Reisende-T�uscher";
static const gDialogue_JallikProblems = "JallikProblems";
static const gDialogue_HeardOfWitch = "HeardOfWitch";

func MsgDialogueEboreus() { return [
		[0,-1,0,["Guten Tag","Seid gegr��t","Hallo, ich bin Eboreus"],0,MCMC],
		[1,0,"K�nnt Ihr die Zugbr�cke runterlassen?","Sicher doch",0,NONE,[true,0,0,0,true],"ProtectedCall(GlobalN(\"gDrawbridge\"),\"FindDrawbridgeUp\")",["GlobalN(\"gDrawbridge\")->~ContextBridgeDown(pSpeaker)", "AppendCommand(pSpeaker,\"MoveTo\",0,395,690)", "StopDialogue(pTarget)" ]],
		[2,0,"K�nnt Ihr die Zugbr�cke rauflassen?","Aber nat�rlich",0,0,[true,0,0,0,true],"ProtectedCall(GlobalN(\"gDrawbridge\"),\"FindDrawbridgeDown\")",["GlobalN(\"gDrawbridge\")->~ContextBridgeUp(pSpeaker)", "AppendCommand(pSpeaker,\"MoveTo\",0,395,690)", "StopDialogue(pTarget)" ]],
		StdDlgArrayExitAlways()
];}


func MsgDialogueIngalf() { return [
		[0,-1,0,"Ich bin erfreut Eure Bekanntschaft zu machen. Ich bin Ingalf.",0,NONE,0,0,"SetStartDialogue(pSpeaker,1)"],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,NONE],
		[2,[0,1],"Was macht Ihr so?","Ich bin Erfinder. Wenn Ihr euch f�r ausgefallene Ger�te interessiert, dann schaut mal vorbei.",-1,0,0,StdDlgVar("!","A",""),StdDlgVar("Create","A","=1")],
			[3,[1,2],"Was ist Eure ausgefallenste Erfindung?","Sch�n, dass Ihr fragt! Ich nenne sie Luftschiff!",-1,0,0,[StdDlgVar("!","Blimp",""),StdDlgVar("","A","")],StdDlgVar("Create","Blimp","=1")],
				[4,[1,3,5],"Luftschiff?","Ja, ein Boot mit dem man fliegen kann. Ich hab' schonmal eins ausprobiert, aber der Rumpf war zu schwer und die V�gel haben mir die Schwebeblase zerpickt.",-1,0,0,[StdDlgVar("","Blimp",""),StdDlgVar("!","Blimp2","")],StdDlgVar("Create","Blimp2","=1")],
				[5,[1,3,4],"Schwebeblase?","Stellt es Euch vor wie bei einem Fisch. Der hat eine Luftblase im Bauch, mit der er sich im Wasser nach oben und unten bewegen kann. Sowas hat auch das Luftschiff.",-1,0,0,[StdDlgVar("","Blimp2",""),StdDlgVar("!","Blimp3","")],StdDlgVar("Create","Blimp3","=1")],
				[6,[1,2,3,4,5],"F�r was ein Luftschiff?","Ich hab mal von einem guten Zauberer geh�rt, der auf einem Schloss im Himmel wohnt, den m�chte ich besuchen.",-1,0,0,[StdDlgVar("","Blimp",""),StdDlgVar("!","OBWHint",""),"!"],[StdDlgVar("!")]],
		StdDlgArrayExitAlways()
];}

func MsgDialogueNestor() { return [
		[0,-1,0,["Ja?","Ich h�re.","Zu Diensten."],0,MCMC,0,0,StdDlgVar("Create","Cancel","=1")],
			[1,0,"Ich m�chte mich euch vorstellen",["Mein Name ist %s.","Gestatten, %s.","Ich bin %s."],-1,0,0,StdDlgVar("!","Intro",""),[StdDlgVar("Create","Intro","=1"),StdDlgVar("","Cancel","=0")]],
			[5,1,"Ich komme aus...",""],
				[2,1,"einer Baronie.","Von drau�en, vom dem Land. Der Baron verlangt den Kriegsdienst von seinen Untertanen.",-1,MI_A,0,0,StdDlgVar("","Intro","+=2")],
				[3,1,"den Bergen.","Dort ist es sehr ruhig und man kann gut studieren.",-1,MCMQ,0,0,StdDlgVar("","Intro","+=4")],
				[4,1,"einer Grenzstadt.","Wir sehen dort oft Fremde, manchmal auch ziemlich �ble Gestalten.",-1,ARWP,0,0,StdDlgVar("","Intro","+=8")],
				[6,[2,3,4],"Weiter","",0,[LMM2,0,0,2,4,7+1]],
				[7,-1,0,"Gut... mal angenommen, wir finden diesen Magier, was denkt Ihr, wie w�rdet Ihr ihm gegen�bertreten?",0,NONE],
					[8,7,"Gewalt","Ich traue diesem ganzen magischen Zeug nicht. Ein Schwert hat noch immer alles und jeden umgehauen.",-1,MI_A,0,0,StdDlgVar("","Intro","+=16")],
					[9,7,"Magie","Wir haben es scheinbar mit einem m�chtigen Magier zu tun. Wir m�ssen Feuer mit Feuer bek�mpfen.",-1,MCMQ,0,0,StdDlgVar("","Intro","+=32")],
					[10,7,"List","Wir brauchen einen guten Plan und m�ssen das Gel�nde zu unserem Vorteil nutzen.|Fallen und Bomben k�nnen auch nicht schaden.",-1,ARWP,0,0,StdDlgVar("","Intro","+=64")],
						[11,[8,9,10],"Weiter","",-1,[LMM2,0,0,2,4,20+1],0,StdDlgVar("","Intro","== 1+2+16")],
						[12,[8,9,10],"Weiter","",-1,[LMM2,0,0,2,4,21+1],0,StdDlgVar("","Intro","== 1+2+32")],
						[13,[8,9,10],"Weiter","",-1,[LMM2,0,0,2,4,22+1],0,StdDlgVar("","Intro","== 1+2+64")],
						[14,[8,9,10],"Weiter","",-1,[LMM2,0,0,2,4,23+1],0,StdDlgVar("","Intro","== 1+4+16")],
						[15,[8,9,10],"Weiter","",-1,[LMM2,0,0,2,4,24+1],0,StdDlgVar("","Intro","== 1+4+32")],
						[16,[8,9,10],"Weiter","",-1,[LMM2,0,0,2,4,25+1],0,StdDlgVar("","Intro","== 1+4+64")],
						[17,[8,9,10],"Weiter","",-1,[LMM2,0,0,2,4,26+1],0,StdDlgVar("","Intro","== 1+8+16")],
						[18,[8,9,10],"Weiter","",-1,[LMM2,0,0,2,4,27+1],0,StdDlgVar("","Intro","== 1+8+32")],
						[19,[8,9,10],"Weiter","",-1,[LMM2,0,0,2,4,28+1],0,StdDlgVar("","Intro","== 1+8+64")],
				[20,-1,0,"Ich habe Krieger + Krieger gew�hlt!",-1,0,0,0,"pTarget->~SetClass(1,1)"],
				[21,-1,0,"Ich habe Krieger + Magier gew�hlt!",-1,0,0,0,"pTarget->~SetClass(1,2)"],
				[22,-1,0,"Ich habe Krieger + Ninja gew�hlt!",-1,0,0,0,"pTarget->~SetClass(1,3)"],
				[23,-1,0,"Ich habe Magier + Krieger gew�hlt!",-1,0,0,0,"pTarget->~SetClass(2,1)"],
				[24,-1,0,"Ich habe Magier + Magier gew�hlt!",-1,0,0,0,"pTarget->~SetClass(2,2)"],
				[25,-1,0,"Ich habe Magier + Ninja gew�hlt!",-1,0,0,0,"pTarget->~SetClass(2,3)"],
				[26,-1,0,"Ich habe Ninja + Krieger gew�hlt!",-1,0,0,0,"pTarget->~SetClass(3,1)"],
				[27,-1,0,"Ich habe Ninja + Magier gew�hlt!",-1,0,0,0,"pTarget->~SetClass(3,2)"],
				[28,-1,0,"Ich habe Ninja + Ninja gew�hlt!",-1,0,0,0,"pTarget->~SetClass(3,3)"],
					[29,[20,21,22,23,24,25,26,27,28],"Weiter!!","",-1,[LMM2,0,0,2,4],-1,"true",[StdDlgVar("","Intro","=1337"),StdDlgVar("","Cancel","=1"),"StopDialogue(pTarget)","StartDialogue(pTarget)"]],
		[30,0,"Wo k�nnen wir Hinweise finden?","Die Leute in der Stadt haben vielleicht etwas gesehen. H�rt euch dort einmal um!",0,0,0,"GetQuestStage(\"MainQuest\",pTarget) == gQuestMainStageSearch"],

		[998,[30],"Weiter","",0,StdDlgIconContinue(),-1,0,["StopDialogue(pTarget)","StartDialogue(pTarget)"]],
		//[999,-1,"Abbrechen","",0,[MCMX,0,0,0,0,-1],-1,["!LocalN2(Format(\"DlgVar%d\",ObjectNumber(pTarget)),pSpeaker) || LocalN2(Format(\"DlgVar%d\",ObjectNumber(pTarget)),pSpeaker) == 1337"],"StopDialogue(pTarget)"]
		StdDlgArrayExitCancel()
];}


func MsgDialogueOdilbert() { return [
		[0,-1,0,"Seid gegr��t! Ich bin Odilbert.",0,NONE,0,0,"SetStartDialogue(pSpeaker,1)"],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		[2,[0,1],"Wie ist das Leben hier?","In der Stadt ist es ganz angenehm, aber in letzter Zeit haben wir viel weniger Waren zur Auswahl.",0,0,0,"GetQuestStage(\"Bandits\",pTarget)==0"],
			[3,2,"Hattet Ihr eine schlechte Ernte?","Nein, die Ernte war gut. Viele der H�ndler berichten von R�uber�berf�llen!",0,0,[true,0,0,0,false,0,0,"Bandits",true],["LocalN2(\"cLand\",pTarget)==\"Barony\"","!LocalN2(Format(\"DlgVar%da\",ObjectNumber(pTarget)),pSpeaker)"],["CreateLocalN2(Format(\"DlgVar%da\",ObjectNumber(pTarget)),pSpeaker)","LocalN2(Format(\"DlgVar%da\",ObjectNumber(pTarget)),pSpeaker)=1"]],
			[4,2,"Wieso das?","Viele der H�ndler berichten, dass sie von R�ubern �berfallen werden!",0,0,[true,0,0,0,false,0,0,"Bandits",true],["LocalN2(\"cLand\",pTarget)==\"Valley\"","!LocalN2(Format(\"DlgVar%da\",ObjectNumber(pTarget)),pSpeaker)"],["CreateLocalN2(Format(\"DlgVar%da\",ObjectNumber(pTarget)),pSpeaker)","LocalN2(Format(\"DlgVar%da\",ObjectNumber(pTarget)),pSpeaker)=1"]],
			[5,2,"H�rt sich nach Banditen an.","So ist es. Sie halten sich irgendwo hier in der N�he auf und �berfallen die H�ndler.",0,0,[true,0,0,0,false,0,0,"Bandits",false],["LocalN2(\"cLand\",pTarget)==\"Border\"","!LocalN2(Format(\"DlgVar%da\",ObjectNumber(pTarget)),pSpeaker)"],["CreateLocalN2(Format(\"DlgVar%da\",ObjectNumber(pTarget)),pSpeaker)","LocalN2(Format(\"DlgVar%da\",ObjectNumber(pTarget)),pSpeaker)=1"]],
				[6,[0,1,2,3,4,5,7,8],"Wo halten sich die R�uber auf?","Das wei� ich auch nicht. Ich habe geh�rt die �berf�lle waren in der N�he der Berge.",0,0,[true,0,0,0,false,0,0,"Bandits",false],["LocalN2(Format(\"DlgVar%da\",ObjectNumber(pTarget)),pSpeaker)==1","!LocalN2(Format(\"DlgVar%db\",ObjectNumber(pTarget)),pSpeaker)"],["CreateLocalN2(Format(\"DlgVar%db\",ObjectNumber(pTarget)),pSpeaker)","LocalN2(Format(\"DlgVar%db\",ObjectNumber(pTarget)),pSpeaker)=1"]],
				[7,[0,1,2,3,4,5,6,8],"Wie siehts mit einer Belohnung aus?","Ich bin nicht gerade der �rmste in der Stadt.|Ihr werdet eine angemessene Belohnung bekommen.",0,0,[true,0,0,0,false,0,0,"Bandits",false],["LocalN2(Format(\"DlgVar%da\",ObjectNumber(pTarget)),pSpeaker)==1","!LocalN2(Format(\"DlgVar%dc\",ObjectNumber(pTarget)),pSpeaker)"],["CreateLocalN2(Format(\"DlgVar%dc\",ObjectNumber(pTarget)),pSpeaker)","LocalN2(Format(\"DlgVar%dc\",ObjectNumber(pTarget)),pSpeaker)=1"]],
				[8,[0,1,2,3,4,5,6,7],"Ich werde Euer Banditenproblem l�sen.","Habt vielen Dank!",0,0,0,["LocalN2(Format(\"DlgVar%da\",ObjectNumber(pTarget)),pSpeaker)==1","GetQuestStage(\"Bandits\",pTarget)==0"],"ActivateQuest(\"Bandits\",pTarget)"],
		StdDlgArrayExitAlways()
];}

// TODO: Infos zum OBW
func MsgDialogueGernot() { return [
		[0,-1,0,"Hallo, ich bin Gernot.",0,NONE,0,0,"SetStartDialogue(pSpeaker,1)"],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		[3,[0,1,2,4],"Was macht Ihr hier?","Wir sind Antiquit�tensammler, das hei�t wir suchen alte Gegenst�nde und sammeln sie.",0,0,0,StdDlgVar("!","H",""),StdDlgVar("Create","H","=1")],
		// Quest: Verschollen
		[2,[0,1,3],"Euer Lager sieht ganz sch�n leer aus.","Wir waren auch mal mehr. Zwei unserer Kameraden sind verschwunden.",0,0,0,"GetQuestStage(\"MissingLooters\",pTarget)==0"],
			[4,2,"Eure Kameraden sind verschwunden?","Ja, wir wollten nach einem Artefakt hier in den H�hlen suchen. Wir haben schon seit einer Woche nichts von ihnen geh�rt.",0,0,[true,0,0,0,false,0,0,"MissingLooters"],StdDlgVar("!","A",""),StdDlgVar("Create","A","=1")],
				[5,[0,1,2,3,4],"Ich werde sie suchen.","Danke. Sie sind dort in den Schacht abgestiegen.",0,0,[true,0,0,0,false,0,0,"MissingLooters"],[StdDlgVar("","A",""),"GetQuestStage(\"MissingLooters\",pTarget)==0"],"ActivateQuest(\"MissingLooters\",pTarget)"],
		// Quest: Verschollen - Belohnung
		[6,1,"Ich habe Eure Freunde gefunden","Ja? Wie geht es Ihnen?",0,0,[true,0,0,0,false,0,0,"MissingLooters"],["GetQuestStage(\"MissingLooters\",pTarget)==5",StdDlgVar("!","C","")],StdDlgVar("Create","C","=1")],
		    [7,[1,6],"Sie sind eine Klippe hinab gest�rzt. Da war nicht mehr viel �brig.","Was?! Verdammt... naja, jetzt haben wir Gewissheit. Hier, nehmt dies.",0,0,[true,0,0,0,false,0,0,"MissingLooters"],["GetQuestStage(\"MissingLooters\",pTarget)==5",StdDlgVar("","C","")],"SetQuestStage(\"MissingLooters\",99,0,true)"],
		// Quest: Ein goldener Kelch
		[8,1,"Was werdet Ihr jetzt machen?","Naja, wir haben noch immer nicht unser Artefakt...",0,0,[true,0,0,0,false,0,0,"KingsChalice",true],["GetQuestStage(\"MissingLooters\",pTarget)==-1","GetQuestStage(\"KingsChalice\",pTarget)==0",StdDlgVar("!","D","")],StdDlgVar("Create","D","=1")],
			[9,[1,8],"Was f�r ein Artefakt sucht Ihr?","Es handelt sich um einen Kelch, er befindet sich im Grab des K�nigs.",0,0,[true,0,0,0,false,0,0,"KingsChalice"],[StdDlgVar("","D",""),StdDlgVar("!","E","")],StdDlgVar("Create","E","=1")],
			[10,[1,8,9,11,12],"Seid Ihr etwa Grabr�uber?!","Nein, nein, beruhigt Euch! Die Grabr�uber habt Ihr schon gefunden. Wir sind wirklich nur Antiquit�tensammler.",0,0,0,[StdDlgVar("","D",""),StdDlgVar("!","F","")],StdDlgVar("Create","F","=1")],
			[11,[1,8,9,10,12],"Warum holt Ihr den Kelch nicht selbst?","Gr�ber und so... das ist schon sehr gruselig. Deswegen haben wir ja die Grabr�uber vorgeschickt. Und jetzt sind die auch noch abgest�rzt! Ich gehe da bestimmt nicht runter!",0,0,[true,0,0,0,false,0,0,"KingsChalice"],[StdDlgVar("","D",""),StdDlgVar("!","G","")],StdDlgVar("Create","G","=1")],
			[12,[1,8,9,10,11],"Gut, ich hole Euch den Kelch","Sehr gut. Sch�ndet bitte das Grab nicht.",0,0,[true,0,0,0,false,0,0,"KingsChalice"],[StdDlgVar("","D",""),"GetQuestStage(\"KingsChalice\",pTarget)==0"],"ActivateQuest(\"KingsChalice\",pTarget)"],
		// Quest: Ein goldener Kelch - Belohnung
		[13,[1,3],"Ich habe da was gefunden, das Euch interessieren k�nnte.","Hmm, genau danach habe ich gesucht. Vielen Dank!",0,0,[true,0,0,0,false,0,0,"KingsChalice"],[StdDlgVar("","H",""),"GetQuestStage(\"KingsChalice\",pTarget)==0","gObjKingsChalice=(pTarget->~HasItem(EGBL))"],["ActivateQuest(\"KingsChalice\",pTarget)","SetQuestStage(\"KingsChalice\",2,pTarget,true)","!gObjKingsChalice||RemoveObject(gObjKingsChalice)"]],
		[14,[1,3],"Ich habe den Kelch, den Ihr sucht.","Vielen Dank! Ich wusste, dass Ihr mich nicht entt�uschen w�rdet. Hier, nehmt dies.",0,0,[true,0,0,0,false,0,0,"KingsChalice"],["GetQuestStage(\"KingsChalice\",pTarget)==1","gObjKingsChalice=(pTarget->~HasItem(EGBL))"],"SetQuestStage(\"KingsChalice\",2,pTarget,true)","!gObjKingsChalice||RemoveObject(gObjKingsChalice)"],
		// das ist immer dabei
		StdDlgArrayExitAlways()
];}

// TODO: Infos zum OBW
// TODO: In blauen Tiefen Belohnung
func MsgDialogueLinnert() { return [
		[0,-1,0,"Ich bin Linnert, und wer seid Ihr?",0,NONE,0,0,"SetStartDialogue(pSpeaker,1)"],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		// Quest: Verschollen
		[2,[0,1],"Was macht Ihr hier?","Ich begleite meinen Kumpel, er will hier einen Schatz finden.",0,0,0,StdDlgVar("!","A",""),StdDlgVar("Create","A","=1")],
			[3,[0,1,2],"Wenn Ihr hier rumsitzt, dann findet Ihr den Schatz sicher nicht","Naja, wir suchen den Schatz auch nicht selbst. Wir haben zwei Abenteurer bezahlt, die ihn f�r uns holen.",0,0,0,[StdDlgVar("","A",""),StdDlgVar("!","B","")],StdDlgVar("Create","B","")],
			[4,3,"Weiter","Vor einer Woche sind sie den Schacht runter...|Seitdem haben wir nichts mehr von Ihnen geh�rt.",0,StdDlgIconContinue()],
			[5,4,"Weiter","Ich glaube ja, dass sie sich nachts einfach mit dem Schatz aus dem Staub gemacht haben.",0,StdDlgIconContinue()],
				[6,5,"Weiter","Wenn Ihr sie findet, und sie den Schatz gestohlen haben, dann w�rde ich den Gewinn mit Euch teilen.",0,StdDlgIconContinue(),0,0,StdDlgVar("","B","=2")],
				[7,[1,6],"Ich werde nach den Abenteurern suchen.","Danke.",0,0,0,[StdDlgVar("","A",""),"GetQuestStage(\"MissingLooters\",pTarget,pSpeaker)==0"],"ActivateQuest(\"MissingLooters\",pTarget)"],
		// Quest: Verschollen - Belohnung
		[8,1,"Ich habe die Abenteurer gefunden","Ja? Und was ist mit dem Schatz?",0,0,[true,0,0,0,false,0,0,"MissingLooters"],["GetQuestStage(\"MissingLooters\",pTarget)==5",StdDlgVar("!","C","")],StdDlgVar("Create","C","=1")],
			[9,[1,8],"Sie sind eine Klippe hinab gest�rzt, da war nicht mehr viel �brig. Den Schatz hatten sie wohl auch nicht.","Was?! Verdammt... naja, jetzt haben wir Gewissheit. Hier, nehmt dies.",0,0,[true,0,0,0,false,0,0,"MissingLooters"],["GetQuestStage(\"MissingLooters\",pTarget)==5",StdDlgVar("","C","")],"SetQuestStage(\"MissingLooters\",99,0,true)"],
		// Quest: In blauen Tiefen
		[10,[0,1,2],"Was f�r einen Schatz sucht Ihr denn?","Einer Legende nach soll er direkt unter dem Meeresboden liegen.",0,0,[true,0,0,0,false,0,0,"DeepTreasure",true],["GetQuestStage(\"DeepTreasure\",pTarget)==0",StdDlgVar("","A",""),StdDlgVar("!","D","")],[StdDlgVar("Create","D","=1"),"ActivateQuest(\"DeepTreasure\",pTarget)"]],
			[11,[0,1,2,10,12],"Ist das nicht gef�hrlich?","Die Legende besagt auch, dass der Schatz von einem m�chtigen W�chter bewacht wird!",0,0,[true,0,0,0,false,0,0,"DeepTreasure"],[StdDlgVar("","D",""),StdDlgVar("!","E","")],StdDlgVar("Create","E","=1")],
			[12,[0,1,2,10,11],"Und ich soll die ganze Arbeit machen?","",0,0,[true,0,0,0,false,0,0,"DeepTreasure",true],[StdDlgVar("","D",""),StdDlgVar("!","F","")],StdDlgVar("Create","E","=1")],
		//	[13,[0,1,2,10,11,12],"Ich mache mich auf die Suche"]
		[999,-1,"Abbrechen","",0,[MCMX,0,0,0,0,-1],-1,StdDlgVar("","B","!=1"),"StopDialogue(pTarget)"]
];}

func MsgDialogueAncientScroll() { return [
		[0,-1,0,"Ich bin Linnert, und wer seid Ihr?",0,NONE,0,0,"SetStartDialogue(pSpeaker,1)"],
		StdDlgArrayExitAlways()
];}


func MsgDialogueAlvelin() { return [
		[0,-1,0,"Hallo, ich bin Alvelin, und wer seid Ihr?.",0,NONE,0,0,["SetStartDialogue(pSpeaker,1)", "pSpeaker->~SetName(\"Alvelin\")", StdDlgVar("Create","Cancel","=1")]],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		[2, [0,1],"Was macht ihr hier drau�en?","Ich suche Kr�uter. Hier im Wald w�chst so einiges N�tzliches.",0,0,															0,											[StdDlgVar("!","AskedOutside","")],																[StdDlgVar("Create", "AskedOutside", "=1")]],
		 [3, [2,1],"Achso, dann st�re ich nicht weiter.", "", 0, 0, 																											-1,											["IsDay()",StdDlgVar("","AskedOutside", "==1")], 												[StdDlgVar("","AskedOutside","=2"),"StopDialogue(pTarget)"]],
		 [4, [2,1],"Ihr seid immernoch hier?","Na klar, Kr�uter und so.", 0, 0, 																								-1,											["IsNight()",StdDlgVar("Inside(","AskedOutside",", 1, 2)")],									[StdDlgVar("","AskedOutside","=3"),"StopDialogue(pTarget)"]],
		 [5, [2,1],"Hier stimmt doch was nicht. Wieso seid Ihr nachts hier unterwegs?","Naja, es ist so: Ich wurde aus der Stadt verbannt. Hexerei und so.",0,0,				[true,0,0,0,false,0,0,"HomeForWitches"],	[StdDlgVar("","AskedOutside","==3"),StdDlgQuestStage("Get","HomeForWitches","==0")],			[StdDlgVar("","AskedOutside","=4"),"ActivateQuest(\"HomeForWitches\",pTarget)"]],
            [6,[5,7,8,9,1],"Hexerei?","Ja. Man beschuldigte mich, jemanden verflucht zu haben, da warf Odilbert mich raus.",0,0,												0,											[StdDlgVar("!","AskedWitchcraft",""),StdDlgVar("","AskedOutside", "==4"),
                                                                                                                                												  											 !DlgObjVar("",gDialogue_HeardOfWitch,"")],														[StdDlgVar("Create","AskedWitchcraft","=1")]],
            [7,[5,6,8,9,1,15,16,17,21,22,23,24],"Ganz sch�n mutig, das einem Fremden zu sagen.","Was habe ich schon zu verlieren? Ich laufe in Lumpen im Wald herum!",0,0,					0,											[StdDlgVar("!","AskedBrave",""),StdDlgVar("","AskedOutside", "==4")],							[StdDlgVar("Create","AskedBrave","=1")]],
            [8,[5,6,7,9,1,15,16,17,21,22,23,24],"Wollt Ihr weiter im Wald wohnen?","Auf keinen Fall. Ich will zur�ck in mein Haus in der Stadt!",0,0,										[true,0,0,0,false,0,0,"HomeForWitches"],	[StdDlgQuestStage("Get","HomeForWitches","==1")],												["SetQuestStage(\"HomeForWitches\",gQuestHomeForWitchesStageFindEntry,pTarget,true)"]],
            [9,[5,6,7,8,1,15,16,17,21,22,23,24],"Ich k�nnte Euch helfen, zur�ck in die Stadt zu kommen", "Ich w�re Euch zu gro�em Dank verpflichtet.",0,0,									[true,0,0,0,false,0,0,"HomeForWitches"],	[StdDlgQuestStage("Get","HomeForWitches","==1")],												["SetQuestStage(\"HomeForWitches\",gQuestHomeForWitchesStageFindEntry,pTarget,true)"]],
         [15,[0,1],"Seid Ihr die Hexe, die im Wald wohnt?", "Ja, die bin ich *seufz*. Mir ist es lieber, wenn Ihr mich Alvelin nennt.",0,0,										0,											[StdDlgVar("","AskedOutside", "<4"),DlgObjVar("",gDialogue_HeardOfWitch,"")],					[StdDlgVar("Create","AskedOutside","=4")]],
          [16,[15,17,1],"Was ist passiert?","Man beschuldigte mich, jemanden verflucht zu haben, da wurde ich von Odilbert aus der Stadt geworfen.",0,0,						0,											[StdDlgVar("!","AskedWitchcraft",""),StdDlgVar("","AskedOutside", "==4"),
                                                                                                                                                        						  											 DlgObjVar("",gDialogue_HeardOfWitch,""),StdDlgQuestStage("Get","HomeForWitches","==0")],		[StdDlgVar("Create","AskedWitchcraft","=1"),"ActivateQuest(\"HomeForWitches\",pTarget)",StdDlgVar("Create","AskedOutside","=4")]],
          [17,[15,16,1,0],"Habt Ihr Answin verflucht?","Nein, ganz sicher nicht! Aber der Trottel h�tte mich fast mit einem Baum erschlagen. Da werde ich schonmal leicht ausgelassen.",0,0,0,								[StdDlgVar("!","AskedAnswin",""),DlgObjVar("",gDialogue_HeardOfWitch,"")],						[StdDlgVar("Create","AskedAnswin","=1"),StdDlgVar("Create","AskedOutside","=4")]],
         [21,[0,1],"Habt Ihr zuf�llig eine Axt gefunden?","Hehe, ja, das habe ich. Aber ich habe dem Holzf�ller noch nichts davon gesagt.",0,0,									[true,0,0,0,false,0,0,"Lumberjack"],		[StdDlgVar("!","AskedAxe",""),StdDlgQuestStage("Get","Lumberjack",">0")],						[StdDlgVar("Create","AskedAxe","=1")]],
          [22,[5,6,7,8,9,1,15,16,17,21,23,24],"Wieso habt Ihr die Axt nicht zur�ckgegeben?", "Damit ich wieder fallenden B�umen ausweichen darf? Nicht mit mir!",0,0,									[true,0,0,0,false,0,0,"Lumberjack"],		[StdDlgVar("","AskedAxe","==1"),StdDlgQuestStage("Get","Lumberjack",">0")],						[StdDlgVar("","AskedAxe","=2")]],
          [23,[5,6,7,8,9,1,15,16,17,21,22,24],"Gebt Ihr mir die Axt?", "Gerne, aber erst wenn ich wieder in der Stadt wohne. Dann brauche ich mich auch nicht mehr vor fallenden B�umen vorsehen.",0,0,	[true,0,0,0,false,0,0,"Lumberjack"],		[StdDlgVar("","AskedAxe",""),StdDlgQuestStage("Get","HomeForWitches","==0"),
                                                                                                                                                                              	                                    		 StdDlgQuestStage("Get","Lumberjack",">0")],													[StdDlgVar("Create","AskedOutside","=4"), "ActivateQuest(\"HomeForWitches\",pTarget)","SetQuestStage(\"HomeForWitches\",gQuestHomeForWitchesStageFindEntry,pTarget,true)"]],
          [24,[5,6,7,8,9,1,15,16,17,21,22,23],"Gebt Ihr mir die Axt?", "Gerne, Ihr kriegt sie als Belohnung, wenn Ihr mir mein altes Haus in der Stadt zur�ckbeschafft.",0,0,							[true,0,0,0,false,0,0,"HomeForWitches"],	[StdDlgVar("","AskedAxe",""),StdDlgQuestStage("Get","HomeForWitches","==1"),
                                                                                                                                                    							                                        	 StdDlgQuestStage("Get","Lumberjack",">0")],													["SetQuestStage(\"HomeForWitches\",gQuestHomeForWitchesStageFindEntry,pTarget,true)"]],
         [30,[0,1],"Bringt Ihr mir das Zaubern bei?","TODO",0,0,0],
         [31,[0,1],"Was habt Ihr zu verkaufen?","TODO",0,0,0],
 		// OBW-Info
 		[40,[0,1], "Gibt es irgendwelche Neuigkeiten?", "Ich habe geh�rt, dass sich auf dem Land die Toten erheben. Es sollen ganz frische Leichen sein, und sie wandern auf den Feldern umher.", 0, 0, [true,0,0,0,false,0,0,"MainQuest"], [StdDlgQuestStage("Get","MainQuest","==gQuestMainStageSearch"), StdDlgVar("!","InfoOBW","")], StdDlgVar("Create","InfoOBW","=1", StdDlgVar("", "Cancel", "=0"), "gQuestMain_Info_Alvelin++")],
 		[41,40,"H�rt sich gef�hrlich an...", "Kann sein. Manchmal erz�hlen die Bauern aber auch nur Unsinn.", 0, LMM2, 0, 0, StdDlgVar("","Cancel","=1")],

		StdDlgArrayExitCancel()
];}



func MsgDialogueArmin() { return [
		[0,-1,0,"Hee, I bin da Armin!",0,NONE,0,0,["SetStartDialogue(pSpeaker,1)",StdDlgVar("Create","Cancel","=1"), StdDlgVar("Create","DayLastReward","=0")]],
		[1,-1,0,["Servus!","Servus oide Wurschthaut!","Schee di zum seng","Sigd ma di a amoi wida!"],0,MCMC],
		// Husky-Quest
		[2,[0,1],"Hallo.","Hee du! Da bei de Baam is a greisligs Viech, stich des ab!",0,0,[true,0,0,0,false,0,0,"HuskyHunt",true],"GetQuestStage(\"HuskyHunt\",pTarget)==0","ActivateQuest(\"HuskyHunt\",pTarget)"],
			[3,[0,1,2],"Ein armes Tier abstechen? Nein!","Hee, des is a riesn Wulf, der frisst as ganze Korn auf.",0,0,[true,0,0,0,false,0,0,"HuskyHunt"],["GetQuestStage(\"HuskyHunt\",pTarget)",StdDlgVar("!","A","")],[StdDlgVar("Create","A","=1"),StdDlgVar("","Cancel","=0")]],
			  [4,3,"W�lfe fressen kein Korn!","Des is a koa Wulf, des is a Husky!!",0,0,[true,0,0,0,false,0,0,"HuskyHunt"]],
				[5,4,"Huskys fressen auch kein Korn.","Is ma Wurscht! Der hats gfressn, I habs gseng! Jetzt stich'n ab!",0,0,[true,0,0,0,false,0,0,"HuskyHunt"]],
				  [6,5,"Ich �berlegs mir nochmal","",0,0,-1,0,[StdDlgVar("","Cancel","=1"),"StopDialogue(pTarget)"]],
		    [7,[0,1,2,5],"Ich werde es bezwingen!","",0,0,-1,["GetQuestStage(\"HuskyHunt\",pTarget)",StdDlgVar("!","B","")],[StdDlgVar("Create","B","=1"),StdDlgVar("","Cancel","=1"),"StopDialogue(pTarget)"]],
		// Belohnung f�r die Husky-Quest
		//"Da hast was zum Essn, des war sicha a mords Abeit."
		[17,[0,1],"Das Tier ist tot!","Sauba! Do hast was zum Essen, des war sicha a mords Abeit. Konnst no �fta wos ham...",0,0,0,[StdDlgQuestStage("Get","HuskyHunt","==gQuestStageFinished"),StdDlgVar("!","UnlockReward","")],[StdDlgVar("Create","UnlockReward","=1"), StdDlgVar("","DayLastReward","=time_days"), "gNPCFarmer->~Exit(CreateContents(RMET,gNPCFarmer),0,5)"]],
		[18,[0,1],"Kriege ich noch was zu essen?","Ja, i hob grad wos da.",0,0,0,["time_days%2 == 0",StdDlgVar("","UnlockReward","==1"),StdDlgVar("","DayLastReward","!=time_days")],[StdDlgVar("","DayLastReward","=time_days"), "Exit(CreateContents(RMET,gNPCFarmer),0,5)"]],
		[18,[0,1],"Kriege ich noch was zu essen?","Na, heid net. Moagn wieda.",0,0,0,["time_days%2 == 1",StdDlgVar("","UnlockReward","==1")],["StopDialogue(pTarget)","StartDialogue(pTarget)"]],
		[19,[0,1],"Kriege ich noch was zu essen?","Na, du host heid scho was kriagt!",0,0,0,["time_days%2 == 0", StdDlgVar("","UnlockReward","==1"),StdDlgVar("","DayLastReward","==time_days")],["StopDialogue(pTarget)","StartDialogue(pTarget)"]],
		// OBW-Info
		[21,[0,1], "Ist sonst etwas besonderes passiert?", "Scho... D'Vegl fliang zur a Inse' im Himme'. Des host no ned gseng, oda?", 0, 0, [true,0,0,0,false,0,0,"MainQuest"], [StdDlgQuestStage("Get","MainQuest","==gQuestMainStageSearch"),StdDlgQuestStage("Get","HuskyHunt","<0"), StdDlgVar("!","InfoOBW","")], [StdDlgVar("Create","InfoOBW","=1", StdDlgVar("", "Cancel", "=0"), "gQuestMain_Info_Armin++")]],
		[22,21,"Insel im Himmel?", "Interessant...", -1, 0, [true,0,0,0,false,0,0,"MainQuest"], 0, StdDlgVar("","Cancel","=1")],
		StdDlgArrayExitCancel()
];}

func MsgDialogueBernika() { return [
		[0,-1,0,"Hallo, ich bin die Wirtin Bernika",0,NONE,0,0,["SetStartDialogue(pSpeaker,1)",StdDlgVar("Create","FishBarrel","=0"),StdDlgVar("Create","Cancel","=1")]],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		[2,[0,1],"Was habt Ihr denn auf der Speisekarte?","Heute haben wir Spanferkel oder Rinderbraten. Dazu k�nnt Ihr euch so viel Sauerkraut, Brot, Schmalz und Suppe nehmen, wie Ihr wollt.",0,0,0,["time_days%3 == 0"]],
		[3,[0,1],"Was habt Ihr denn auf der Speisekarte?","Ich kann euch Schweinerippchen empfehlen, au�erdem haben wir heute Rindereintopf. Nehmt euch so viel Brot, Gr�tze oder Kohl dazu, wie Euch beliebt.",0,0,0,["time_days%3 == 1"]],
		[4,[0,1],"Was habt Ihr denn auf der Speisekarte?","Wie w�re es mit Schweinegeschnetzeltem oder einer saftigen Rinderkeule? Als Beilage gibt es so viel Suppe, Brei und gekochte M�hren, wie Ihr essen k�nnt.",0,0,0,["time_days%3 == 2"]],
		[5,[0,1],"Was habt Ihr denn auf der Speisekarte?","Bei uns gibt es heute Schweineschulter und Rinderhackbraten. Au�erdem haben wir Brot, Schmalz und einen Bierschinken.",0,0,0,["time_days%3 == 3"]],
		[6,[2,3,4,5],"Dann nehme ich das Schweinegericht.",""],
		[7,[2,3,4,5],"Das Rind h�rt sich gut an.",""],
		// Fisch-Quest
		[10,[2,3,4,5],"Hmm, ein Fisch w�rde mir jetzt schmecken.","Fisch?! Ich kann's nicht mehr h�ren, alles ausverkauft!",0,0,[true,0,0,0,false,0,0,"SomethingFishy",true],"GetQuestStage(\"SomethingFishy\",pTarget)==0","ActivateQuest(\"SomethingFishy\",pTarget)"],
			[11,[10,1,16,17],"Woher holt Ihr den Fisch?","Normalerweise kriegen wir ihn von einem H�ndler, der hat ihn von der Ostk�ste.",0,0,[true,0,0,0,false,0,0,"SomethingFishy"],["GetQuestStage(\"SomethingFishy\",pTarget)",StdDlgVar("!","A","")],StdDlgVar("Create","A","=1")],
			  [12,[11,13,1,16,17],"Verdirbt der Fisch nicht, bis er bei Euch ankommt?","Nein, die niedrigen Temperaturen in den Bergen halten ihn frisch. Wir m�ssen ihn nicht einmal salzen, das macht ihn so beliebt und g�nstig!",0,0,[true,0,0,0,false,0,0,"SomethingFishy"],["GetQuestStage(\"SomethingFishy\",pTarget)",StdDlgVar("!","B","")],StdDlgVar("Create","B","=1")],
			  [13,[11,12,1,16,17],"Wann bekommt Ihr die n�chste Lieferung?","Das wei� ich nicht. Unser H�ndler wurde schon ein paar mal in den Bergen �berfallen. Fragt mal bei Odilbert nach, der wei� mehr dar�ber.",0,0,[true,0,0,0,false,0,0,"Bandits"],["GetQuestStage(\"SomethingFishy\",pTarget)","GetQuestStage(\"Bandits\",pTarget)==0",StdDlgVar("!","C","")],StdDlgVar("Create","C","=1")],
		    [14,[11,12,13,10,1,16,17],"Dann muss ich wohl selbst welchen auftreiben.","Das w�rdet Ihr tun? Vielen Dank!",0,0,0,["GetQuestStage(\"SomethingFishy\",pTarget)",StdDlgVar("!","B",""),"gDeliveredFishBarrels<2"],[StdDlgVar("Create","B","=1")]],
		    [15,[11,12,13,10,1,14,16,17],"Wie viel Fisch braucht Ihr denn?","Am besten ein ganzes Fass! Die anderen G�ste erwarten meine Fischgerichte schon dringend.",0,0,0,["GetQuestStage(\"SomethingFishy\",pTarget)",StdDlgVar("!","B",""),"gDeliveredFishBarrels<2"],[StdDlgVar("Create","B","=1")]],
		// Belohnung zur Fisch-Quest
		[16,[0,1,10],"Ihr k�nnt sicher Fisch gebrauchen.","Ja, tats�chlich! Der Fisch ist hier seit langer Zeit ausverkauft.",0,0,[true,0,0,0,false,0,0,"SomethingFishy"],["GetQuestStage(\"SomethingFishy\",pTarget)==0",StdDlgVar("","FishBarrel","=(pTarget->~HasItem(FBRL))")],["ActivateQuest(\"SomethingFishy\",pTarget)"]],
		[17,[1,10,16,17],"Hier, ich habe Euch etwas Fisch besorgt.",["Sehr gut! Hier habt Ihr eine kleine Belohnung.","Danke. Hier, f�r Euch.","Danke. Habt Ihr noch mehr?"],0,0,[true,0,0,0,false,0,0,"SomethingFishy"],["GetQuestStage(\"SomethingFishy\",pTarget)==1",StdDlgVar("","FishBarrel","=(pTarget->~HasItem(FBRL))"),"gDeliveredFishBarrels<2"],["SetQuestStage(\"SomethingFishy\",2,pTarget,true)",StdDlgVarSafeRemoveObject("FishBarrel"),"gDeliveredFishBarrels++"]],
		[18,[1,10,16,17],"Hier, ich habe Euch etwas Fisch besorgt.","Habt vielen Dank! Jetzt reicht der Fisch f�r eine Weile!",0,0,[true,0,0,0,false,0,0,"SomethingFishy"],["GetQuestStage(\"SomethingFishy\",pTarget)==1",StdDlgVar("","FishBarrel","=(pTarget->~HasItem(FBRL))"),"gDeliveredFishBarrels>=2"],["SetQuestStage(\"SomethingFishy\",3,pTarget,true)",StdDlgVarSafeRemoveObject("FishBarrel"),"gDeliveredFishBarrels++"]],
		[19,[1,10,18],"Ich habe wieder Fisch, braucht Ihr noch was?","Ein kleiner Vorrat kann nicht schaden, ich kann euch aber nicht mehr so viel Geld daf�r geben.",0,0,0,["gDeliveredFishBarrels>=2","GetQuestStage(\"SomethingFishy\",pTarget)<0",StdDlgVar("","FishBarrel","=(pTarget->~HasItem(FBRL))"),StdDlgVar("!","UnlockSellFish","")], [StdDlgVar("Create","UnlockSellFish","=1")]],
		[20,[1,10,18,19,20], Format("{{FBRL}} Fische verkaufen %d{{GOLD}}",gFishBarrel_PriceFactor_Sell*GetValue(0,FBRL)/100), ["Danke.", "Gerne wieder!", "Habt Ihr noch mehr?"], 0, 0, 0, [StdDlgVar("","UnlockSellFish","==1"),"pTarget->~HasItem(FBRL)",StdDlgVar("","FishBarrel","=(pTarget->~HasItem(FBRL))")], [StdDlgVarSafeRemoveObject("FishBarrel"),Format("pTarget->~DoMoney(%d)",gFishBarrel_PriceFactor_Sell*GetValue(0,FBRL)/100)]],
		// OBW-Info
		[21,[0,1], "Ist in den letzten Tagen etwas merkw�rdiges vorgefallen?", "Hmm, ja, tats�chlich. Ich habe geh�rt, dass von einem Tag auf den anderen die Bettler aus dem Nachbarort verschwunden sind.", 0, 0, [true,0,0,0,false,0,0,"MainQuest"], [StdDlgQuestStage("Get","MainQuest","==gQuestMainStageSearch"), StdDlgVar("!","InfoOBW","")], StdDlgVar("Create","InfoOBW","=1", StdDlgVar("", "Cancel", "=0"), "gQuestMain_Info_Bernika++")],
		[22,21,"Weiter", "Erst waren sie da, dann waren sie weg... sogar der Lahme!", 0, StdDlgIconContinue(), 0, 0, StdDlgVar("","Cancel","=1")],
		// Ende
		//StdDlgArrayExitAlways()
		StdDlgArrayExitCancel()
];}


func MsgDialogueBernikasFishBarrel() { return [
        [0,-1,0,["Ein Fass voller gesalzener Fische. Sieht nach Makrelen aus.","Eingelegte Fische. Durch das Salz sind sie lange genug haltbar, um den Transport von der K�ste bis in die Stadt zu �berstehen.","So eine gro�e Menge Fisch ist f�r den Verkauf auf dem Markt bestimmt oder es ist eine Lieferung an ein Gasthaus."],-1,MCMC,0,0],
		StdDlgArrayExitAlways()
];}


// TODO: Infos zum OBW
func MsgDialogueRovena() { return [
		[0,-1,0,"Ich bin Rovena, wie kann ich euch dienen?",0,NONE,0,0,["SetStartDialogue(pSpeaker,1)",StdDlgVar("Create","Cancel","=1")]],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		  [2,[0,1],"Was macht Ihr hier?","Na Ihr fragt aber dumm... bei mir kann man sich entspannen. Wollt Ihr nicht reinkommen?",0,0,0,StdDlgVar("!","A",""),StdDlgVar("Create","A","=1")],
			[3,[2,1],"Ich habs noch nicht kapiert.","Ich k�nnte mich ein wenig um Euch k�mmern *zwinker*",0,0,0,StdDlgVar("","A","==1"),StdDlgVar("","A","=2")],
			  [4,[3,1],"Nein, ich wei� nicht, was Ihr meint.","Wollt Ihr bei mir aufsatteln?",0,0,0,StdDlgVar("","A","==2"),StdDlgVar("","A","=3")],
			    [5,[4,1],"Von was redet Ihr?","*genervt* Ich k�nnte Euch die Lanze polieren!",0,0,0,StdDlgVar("","A","==3"),StdDlgVar("","A","=4")],
			[6,[2,3,4,5],"Verstehe. Wieso nicht.","Sch�n, tretet ein!",0,0,0,StdDlgVar("","A","")],
			[15,[1,8],"Hmm, ich w�re an Euren Diensten interessiert","Sch�n, tretet ein!",0,0,0,StdDlgVar("","A",">3")],
			[7,[1,2,3,4,5],"Ihr seid eine Dirne?","Ganz genau. Mit Zertifikat!",0,0,[true,0,0,0,false,0,0,"Whipped"],StdDlgVar("","A","<5"),[StdDlgVar("","A","=5"),StdDlgVar("","Cancel","=0")]],
			  [8,7,"Zertifikat?","K�nigliche Siechenkontrolle. Ich halte die Vorschriften ein, daf�r zahle ich weniger Steuer.",0,0,0,0,StdDlgVar("","Cancel","=1")],
			[9,[1,8],"Kann ich etwas f�r Euch tun?","Ihr f�r mich? Das ist ungew�hnlich. Kommt am besten morgen wieder, bis dahin habe ich mir etwas �berlegt.",0,0,0,[StdDlgVar("","B","==0"),StdDlgVar("","A",">=4")],[StdDlgVar("Create","B","=1"),StdDlgVar("Create","Days","=time_days+1")]], // DlgVar = dsys, time_days+1 usw;
			  [10,[1,9],"Nun, wie kann ich helfen?","Ich �berlege noch. Kommt morgen wieder.",0,0,0,["time_days < DlgVar(\"Days\",pTarget,pSpeaker)",StdDlgVar("","B",""),StdDlgVar("","C","==0")] ],
			  [11,1,"Nun, wie kann ich helfen?","Es gibt da tats�chlich etwas, das Ihr f�r mich tun k�nnt!",0,0,[true,0,0,0,false,0,0,"Whipped"],["time_days >= DlgVar(\"Days\",pTarget,pSpeaker)",StdDlgVar("","B",""),StdDlgVar("","C","==0")],[StdDlgVar("Create","C","=1"),StdDlgVar("","Cancel","=0")]],
			    [12,11,"Ja?","K�nnt Ihr mir eine Peitsche bringen?",0,0,[true,0,0,0,false,0,0,"Whipped"],StdDlgVar("","C","")],
			  	  [13,12,"Eine Peitsche?! Wof�r braucht Ihr die denn?","Manche meiner Kunden haben einfach ausgefallene W�nsche.",0,0,[true,0,0,0,false,0,0,"Whipped"],[StdDlgVar("","C",""),StdDlgVar("","D","==0")],[StdDlgVar("","Cancel","=1"),StdDlgVar("Create","D","=1")]],
			        [14,[1,13],"Alles klar, ich suche Euch eine Peitsche.","Na dann! *zwinker*",0,0,[true,0,0,0,false,0,0,"Whipped"],["GetQuestStage(\"Whipped\",pTarget)==0",StdDlgVar("","D","")],"ActivateQuest(\"Whipped\",pTarget)"],
		// Belohnung zur Quest
		[18,1,"Hier ist die Peitsche, die Ihr wolltet.","Juhu, die sieht richtig sch�n aus. Diesmal geht's auf's Haus.",0,0,[true,0,0,0,false,0,0,"Whipped"],["GetQuestStage(\"Whipped\",pTarget)==1","gObjWhip=(pTarget->~HasItem(WHIP))"],"SetQuestStage(\"Whipped\",2,pTarget,true)","!gObjWhip||RemoveObject(gObjWhip)"],
		  [16,[1,18],"Ich nehme Euer Angebot an.","Gerne, kommt rein!",0,0,0,"GetQuestStage(\"Whipped\",pTarget)==2","SetQuestStage(\"Whipped\",3,pTarget,true)"],
		  // TODO: Materielle Belohnung, evtl. f�r eine andere Quest
		  [17,[1,18],"Ich nehme Euer Angebot an.","Gerne, kommt rein!",0,0,0,"GetQuestStage(\"Whipped\",pTarget)==2","SetQuestStage(\"Whipped\",4,pTarget,true)"],
			StdDlgArrayExitCancel()
];}

func MsgDialogueRovenasWhip() { return [
        [0,-1,0,["Eine schwere Peitsche, wird h�ufig zum Antreiben von Vieh eingesetzt.","Au�er in der viehzucht werden Peitschen auch zur Bestrafung von Gefangenen eingesetzt."],-1,MCMC,0,0],
		StdDlgArrayExitAlways()
];}

/*--- W�chter am Stadttor ---*/

// Na dann mal viel Spa� bei debuggen....
func MsgDialogueHelmar() { return [
		[0,-1,0,"Haltet mich nicht zu lange auf, ich bin im Dienst! Ach ja, ich bin Helmar der W�chter.",0,NONE,0,0,"SetStartDialogue(pSpeaker,1)"],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		 [2,[0,1],"Und, wie gehts?", "Ach gut, wie immer. Ich habe heute wieder einen Haufen Papiere kontrolliert, besser gehts nicht.",0,0,0],
		  [3,2,"Weiter","So viele Leute gehen hier aus und ein, da bleibt mir manchmal nichts anders �brig, als die Papiere nur zu �berfliegen",0,StdDlgIconContinue(),0],
		   [4,3,"Weiter","Aber heute l�uft es gut. Keine Messerstecherei am Tor, keine Diebe. Alles sch�n ruhig.",0,StdDlgIconContinue(),0],
		    [5,4,"Weiter","Sowas kann aber auch t�uschen... meinen Kumpel Bertram hat's erwischt, einen Tag vor dem Ruhestand! K�nnt Ihr Euch das vorstellen?!",0,StdDlgIconContinue(),0],
		     [6,5,"Weiter","Da kommt so ein Rabauke mit einem Einlassschein f�r eine Woche. Und der wollte nur einen Tag bleiben!",0,StdDlgIconContinue(),0],
		      [7,6,"Weiter","Nur einen Tag! K�nnt Ihr das glauben? Und der Schein gilt eine ganze Woche!",0,StdDlgIconContinue(),0],
		       [8,7,"Weiter","Der gute Bertram konnte den nat�rlich nicht so einfach reinlassen. Wer nur einen Tag rein will, der braucht halt 'nen Tagesschein, so hat er gesagt.",0,StdDlgIconContinue(),0],
		        [9,8,"Weiter","Also gut, meinte der Andere, dann bleib' ich halt 'ne Woche. So hat ihn der Bertram reingelassen. H�tt' er besser nicht gemacht...",0,StdDlgIconContinue(),0],
		         [10,9,"Weiter","Es trug sich n�mlich so zu, dass Unhold am Abend zur�ck kam und wieder aus der Stadt rauswollte!",0,StdDlgIconContinue(),0],
		          [11,10,"Weiter","Dabei hat er doch gesagt, er bleibt die ganze Woche! Das konnte Bertram nicht so auf sich sitzen lassen.",0,StdDlgIconContinue(),0],
		           [12,11,"Weiter","Also hat er gesagt: Wer 'ne Woche bleiben will, der bleibt auch! Und in dem Moment haben die Kollegen den Bertram zur Seite genommen, das war ein Gl�ck.",0,StdDlgIconContinue()],
		            [13,12,"Weiter","Ja zum Gl�ck sag ich, denn sonst w�re es noch schlimmer gekommen. Sie nehmen den Bertram also zur Seite, und dann haben sie zu ihm gesagt...",0,StdDlgIconContinue()],
		        	 [14,13,"Weiter","... Bertram du alter Suffkopp, lass den Mann raus! Haben sie gesagt. Dann haben sie ihm 'ne ordentliche Abreibung verpasst und rausgeschmissen aus der Wachmannschaft.",0,StdDlgIconContinue()],
		        	  [15,14,"Weiter","Ja und so kam es, dass es den Bertram einen Tag vor seinem Ruhestand erwischt hat. Zehn Jahre Dienst h�tt' er noch gehabt! Zehn Jahre!",0,StdDlgIconContinue()],
		        	   [16,15,"Weiter","Aber die schmei�en ihn einfach raus...",0,StdDlgIconContinue(),0],
		        	    [17,16,"�h...","Unfasslich, nicht wahr? Meine Rede! Aber die Jungs habens gut gemacht."],
		        	    [18,16,"Moment mal...", "... wenn er noch 10 Jahre zu dienen gehabt h�tte, dann ist das nicht einen Tag vor dem Ruhestand."],
		        	     [19,18,"Weiter","Ja aber sie haben ihn doch rausgeworfen! Vorzeitiger Ruhestand hei�t das, gibts nur hier in der Wache.",0,StdDlgIconContinue()],
		        	     [20,19,"Weiter","Wenn einer aufh�rt, rausgeschmissen wird, oder ins Gras bei�t, dann ist das der Ruhestand.",0,StdDlgIconContinue()],
		        	      [21,20,"Alles klar. Ich lass Euch mal in Ruhe hier stehen...","Ja vielen Dank, war ein nettes Gespr�ch."],
                        [22,16,"Und was macht Bertram jetzt?","Verschwunden ist er, abgehauen. Schade drum, aber es scheint ihm ganz gut zu gehen."],
                         [23,22,"Weiter","Hab mal geh�rt, dass er ein eigenes Haus hat! Jeden Tag ein ordentliches Bes�ufnis, und bei den Dirnen im Nachbardorf hat er auch einen Ruf, der alte Hund.",0,StdDlgIconContinue()],
		StdDlgArrayExitAlways()
];}

/*--- W�chter am Katapult ---*/

func MsgDialogueRadulf() { return [
        // Brot �ber globale Quest-Variable machen!!
		[0,-1,0,"Radulf gr��t!",0,NONE,0,0,["SetStartDialogue(pSpeaker,1)",StdDlgVar("Create","Cancel","=1")]],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		  [2,1,"Ihr seht aus, als k�nntet Ihr ein Brot vertragen.","Brot!? Nein danke!",0,0,0,StdDlgVar("","A","==0"),[StdDlgVar("Create","A","=1"),StdDlgVar("","Cancel","=0")]],
		    [3,2,"Wirklich nicht? Ich hole Euch sogar frisches aus der Stadt.","Hmm... so ein kleines St�ck... wieso nicht. Nein, Radulf, reiss dich zusammen!"],
		      [4,3,"Ist alles in Ordnung mit Euch?","Ich bin auf Entzug m�sst Ihr wissen. Ich war s�chtig nach Brot!"],
		        [5,4,"S�chtig nach Brot?!","Ja, ich hab jeden Tag mindestens eine Scheibe gegessen. Das ist echt Teufelszeug!",0,0,0,0,StdDlgVar("","Cancel","=1")],
		          [6,5,"???","Jetzt haben sie mich hier beim Katapult zum Wachdienst eingeteilt. Weit und breit keine Spur von Brot, das ist eine Wohltat f�r meine Seele."],
		            [7,[1,6],"Na, dann lasse ich das mit dem Brot mal.","Danke, so ist es zum Besten.",0,0,0,[StdDlgVar("","A",""),StdDlgVar("","B","==0")],StdDlgVar("Create","B","=1")],
		            [8,[1,6],"Also Ihr habt sie doch nicht alle!","Ihr werdet schon sehen, wenn Ihr mal ein Brot esst!",0,0,0,[StdDlgVar("","A",""),StdDlgVar("","B","==0")],StdDlgVar("","B","=2")],
		            [9,[1,6],"So ein kleiner Bissen kann doch nicht schaden.","Nein, danke.",0,0,0,[StdDlgVar("","A",""),StdDlgVar("","B","==0")],StdDlgVar("","B","=3")],
		              [11,[1,9],"Na kommt, ich bringe auch ein ganz leichtes Brot.","Das ist am schlimmsten! Das will ich nicht.",0,0,0,[StdDlgVar("","A",""),StdDlgVar("","B","==3")],StdDlgVar("","B","=4")],
		              [12,[1,11],"Nun habt Euch nicht so.","Ich will kein Brot, habe ich gesagt!",0,0,0,[StdDlgVar("","A",""),StdDlgVar("","B","==4")],StdDlgVar("","B","=5")],
		              [13,[1,12],"Ihr wollt also wirklich nichts.","Ganz genau, und jetzt lasst mich in Ruhe.",0,0,0,[StdDlgVar("","A",""),StdDlgVar("","B","==5")],StdDlgVar("","B","=6")],
		              [14,[1,13],"So ein Vollkornbrot ist aber auch lecker.","Lasst mich in Frieden.",0,0,0,[StdDlgVar("","A",""),StdDlgVar("","B","==6")],StdDlgVar("","B","=7")],
		              [15,[1,14],"Dann muss ich das gute Brot wohl ganz alleine essen.","Haha, Ihr habt doch noch nicht mal ein Brot.",0,0,0,[StdDlgVar("","A",""),StdDlgVar("","B","==7")],StdDlgVar("","B","=8")],
		              [16,[1,15],"Und wenn ich welches h�tte?","Dann gebt es mir blo� nicht!",0,0,0,[StdDlgVar("","A",""),StdDlgVar("","B","==8")],StdDlgVar("","B","=9")],
		              [17,[1,16],"Wie Ihr wollt, kein Brot f�r Euch.","Halt halt, nicht so schnell!",0,0,0,[StdDlgVar("","A",""),StdDlgVar("","B","==9")],[StdDlgVar("","B","=10"),StdDlgVar("","Cancel","=0")]],
		                [18,17,"Ja?","So ein kleines St�ckchen kann ja nicht schaden.",0,0,0,[StdDlgVar("","A",""),StdDlgVar("","B","==3")],StdDlgVar("","Cancel","=1")],
		            [10,[1,6],"","",0,0,0,StdDlgVar("","A","")],
		// TODO
		// Brot anbieten, wenn man welches dabei hat
		// vllt war sein s�chtig machendes Brot eigtl. f�r den K�nig bestimmt und vergiftet?
		// oder es war von einem Drogenh�ndler, der die Drogen in Brotlaiben schmuggelt.
		// nach der Quest sprechen einen auch Bettler auf ein Brot an (oder sie tun es immer, aber danach kann man sie beobachten und sie sehen eigtl. wie Junkies aus)
		// der Dealer k�nnte der Typ in der Vorratskammer des Schlosses sein.
		[18,[1,17],"Hier habt Ihr ein Brot","Brot? Zeigt Her!!",0,0,0,"pTarget->HasItem(BRED,1)",StdDlgVar("","Cancel","=0")],
		  [19,18,"Und? Lecker?","Jaaa, Brot!! *mampf*",0,0,0],
		    [20,19,"Weiter","Komisch... das ist �berhaupt nicht so wie ich es mir vorgestellt habe.",0,StdDlgIconContinue(),0,0],
		    [22,19,"Weiter","Komisch... das ist �berhaupt nicht so wie ich es mir vorgestellt habe.",0,StdDlgIconContinue(),0,0], // hier eine Unterscheidung, ob pTarget klug genug ist, um Drogen zu vermuten
		      [21,[20,1],"Was meint Ihr?","Normalerweise f�hle ich mich ganz gut und ohne Sorgen, wenn ich Brot gegessen habe.",0,0,0],
		        [22,[21,22,1],"Es ist halt Brot.","Also in meinem Brot war irgendwas anders.",0,0,0], // jetzt sollten alle Chars die M�glichkeit haben, nach Drogen zu fragen
		        [23,[21,22,1],"Komisch...","Das sollte ich mir mal ansehen.",0,0,0,0,"ActivateQuest(\"FunkyBread\",pTarget)"], // diesen Satz soll pTarget sagen!! Quest aktivieren
		StdDlgArrayExitCancel()
];}

/*--- Holzf�ller ---*/

// TODO: Questlog funzt nicht??
// Nicht direkt erscheint erneut
// Antworten des Spielers loggen
func MsgDialogueAnswin() { return [
		[0,-1,0,"Seid gegr��t! Ich bin Answin, der Holzf�ller.",0,NONE,0,0,["SetStartDialogue(pSpeaker,1)",StdDlgVar("Create","Cancel","=1"),StdDlgVar("Create","AnswinsAxe","")]],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		// Axt holen DEBUGGED
		[2,[0,1],"Was steht Ihr hier so rum?","Ich bin Holzf�ller, aber ich habe meine Axt im Wald verloren. Jetzt kann ich nichts arbeiten.",0,0,[true,0,0,0,false,0,0,"Lumberjack"],StdDlgVar("!","A",""),[StdDlgVar("Create","A","=1"),StdDlgVar("","Cancel","=0")]],
		  [3,[2,1],"Ihr habt Eure Axt verloren?!","Hmm, ja, nicht direkt verloren. Lasst mich erkl�ren.",0,0,[true,0,0,0,false,0,0,"Lumberjack",true],StdDlgVar("","A","==1"),StdDlgVar("","A","=2")],
		  [4,[2,1],"Besonders helle seid Ihr ja nicht...","Haha Ihr haltet Euch wohl f�r besonders schlau. Ich hab sie nicht direkt verloren.",0,0,[true,0,0,0,false,0,0,"Lumberjack"],StdDlgVar("","A","==1"),StdDlgVar("","A","=2")],
		    [5,[3,4,19],"Nicht direkt verloren?","Ja. Um genau zu sein, habe ich sie weggeworfen!",0,0,[true,0,0,0,false,0,0,"Lumberjack"],StdDlgVar("","Z","==0"),[StdDlgVar("","Cancel","=1"),StdDlgVar("Create","Z","=1")]],
		      [6,[5,1,19],"Was? Weggeworfen?!","Ja, kennt ihr nicht die Legende?",0,0,[true,0,0,0,false,0,0,"Lumberjack"],[StdDlgVar("","B","==0"),StdDlgVar("","A",""),StdDlgVar("","Z","")],[StdDlgVar("Create","B","=1"),StdDlgVar("","Cancel","=0")]],
		        [7,6,"Welche Legende?","Es gab da mal einen Holzf�ller, dessen Axt wurde von einer Hexe verflucht.",0,0,[true,0,0,0,false,0,0,"Lumberjack",true]],
				[8,7,"Weiter","Fortan traf die Axt keine B�ume mehr, sondern nur noch den Holzf�ller.",0,StdDlgIconContinue(),[true,0,0,0,false,0,0,"Lumberjack",true]],
				[9,8,"Weiter","Erst schlug er sich die Beine ab, grausig, und dann auch noch die Arme!",0,StdDlgIconContinue(),[true,0,0,0,false,0,0,"Lumberjack",true]],
				[10,9,"Weiter","So kam es, dass alle seine Glieder durch Holz ersetzt wurden. So wurde der Holzf�ller selbst zum Baum.",0,StdDlgIconContinue(),[true,0,0,0,false,0,0,"Lumberjack",true]],
			      [11,10,"Was hat das mit Euch zu tun?","Kennt ihr die Hexe, die im Wald wohnt?",0,0,[true,0,0,0,false,0,0,"Lumberjack"],StdDlgVar("","A",""),[DlgObjVar("Create",gDialogue_HeardOfWitch, "=1")]],
					[12,11,"Weiter","Letztens h�tte sie fast ein Baum erschlagen. Sie hat Kr�uter gesucht und ist gerade noch weggesprungen.",0,StdDlgIconContinue(),[true,0,0,0,false,0,0,"Lumberjack"]],
					[13,12,"Weiter","Da hat sie mich ganz b�se angeschaut und irgendwas gemurmelt...",0,StdDlgIconContinue(),[true,0,0,0,false,0,0,"Lumberjack"]],
					  [14,13,"Weiter","Erst habe ich mir nichts dabei gedacht, aber dann fiel mir die Legende wieder ein. Also habe ich die Axt in den Wald gepfeffert.",0,StdDlgIconContinue(),[true,0,0,0,false,0,0,"Lumberjack"],0,[StdDlgVar("","Cancel","=1"),StdDlgVar("Create","C","=1")]],
					  	  [15,[1,14,16,17,19],"Und jetzt?","Jetzt will ich meine Axt wieder haben. Sie war wohl doch nicht verflucht.",0,0,[true,0,0,0,false,0,0,"Lumberjack",true],[StdDlgVar("","C",""),StdDlgVar("","C2","==0")],StdDlgVar("Create","C2","=1")],
					 	    [16,[1,14,15,17,19],"Nicht verflucht?","Die olle Hexe hat mich letztens gefragt wieso ich hier so rumstehe. Ich habe ihr alles erz�hlt, da hat sie mich ganz doll ausgelacht.",0,0,[true,0,0,0,false,0,0,"Lumberjack",true],[StdDlgVar("","D","==0"),StdDlgVar("","C2","")],StdDlgVar("Create","D","=1")],
					 	  [17,[1,14,15,16,19],"Wieso kauft Ihr nicht eine neue Axt?","Sie ist mir halt so ans Herz gewachsen. Mit einer neuen Axt w�re die Arbeit nicht dieselbe.",0,0,[true,0,0,0,false,0,0,"Lumberjack"],[StdDlgVar("","E","==0"),StdDlgVar("","C","")],StdDlgVar("Create","E","=1")],
					 	  [18,[1,14,15,16,17,19],"Ich schaue mal, ob ich Eure Axt finden kann.","Das w�re sch�n.",0,0,[true,0,0,0,false,0,0,"Lumberjack"],[StdDlgVar("","F","==0"),StdDlgVar("","C","")],[StdDlgVar("Create","F","=1"),"ActivateQuest(\"Lumberjack\",pTarget)"]],
		      [19,[5,1,14,15,16,17,18],"Wohin habt Ihr die Axt geworfen?","Das wei� ich auch nicht mehr so genau. Ich bin einfach in den Wald gegangen und habe sie so weit geworfen, wie ich konnte.",0,0,[true,0,0,0,false,0,0,"Lumberjack"],[StdDlgVar("","A",""),StdDlgVar("","G","==0")],StdDlgVar("Create","G","=1")],
		      [20,[5,1,14,15,16,17,18],"Dann seid Ihr wohl der d�mmste Holzf�ller der Welt!","Pah, ich kann mir ja eine neue Axt kaufen. Lasst mich in Ruhe.",0,0,[true,0,0,0,false,0,0,"Lumberjack"],["GetQuestStage(\"Lumberjack\",pTarget)>-2",StdDlgVar("","A",""),StdDlgVar("","F","==0")],["ActivateQuest(\"Lumberjack\",pTarget)","SetQuestStage(\"Lumberjack\",-2,pTarget)","StopDialogue(pTarget)"]],
		// Axt Belohnung
		//[21,[0,1,2],"Ist das Eure Axt? {{LAXE}}","Ja, tats�chlich, das ist sie!",0,0,[true,0,0,0,false,0,0,"Lumberjack"],[StdDlgVar("","A","",""),StdDlgVar("!","G",""),StdDlgVar("","AnswinsAxe","=(pTarget->~HasItem(LAXE))")],[StdDlgVar("","Cancel","=0"),StdDlgVar("Create","G","=1")]],
		//  [22,21,"Weiter","Vielen Dank! Hier, f�r Eure M�he.",0,[LMM2,0,0,2,4],[true,0,0,0,false,0,0,"Lumberjack",true],0,[StdDlgVar("","Cancel","=1"),StdDlgVar("RemoveObject(","AnswinsAxe",")"),"FinishQuest( \"Lumberjack\", pTarget, true)"]],
		[21,[0,1,2],"Ist das Eure Axt? {{LAXE}}","Ja, tats�chlich, das ist sie!",0,0,[true,0,0,0,false,0,0,"Lumberjack"],[StdDlgVar("","A","",""),StdDlgVar("!","G",""),"gObjAnswinsAxe=(pTarget->~HasItem(LAXE))"],[StdDlgVar("","Cancel","=0"),StdDlgVar("Create","G","=1")]],
		  [22,21,"Weiter","Vielen Dank! Hier, f�r Eure M�he.",0,StdDlgIconContinue(),[true,0,0,0,false,0,0,"Lumberjack",true],0,[StdDlgVar("","Cancel","=1"),"SetQuestStage(\"Lumberjack\",2,pTarget,true)","!gObjAnswinsAxe||RemoveObject(gObjAnswinsAxe)"]],

		StdDlgArrayExitCancel()
];}


func MsgDialogueAnswinsAxe() { return [
//		[0,-1,0,"Das ist eine Axt. Sie hat ein paar Scharten.",-1,MCMC,[true,0,0,0,true],0,["SetStartDialogueEx(2)","StopDialogue(pTarget)"]],
//		[1,-1,0,"Eine schartige Axt...",-1,MCMC,[true,0,0,0,true],0,["SetStartDialogueEx(2)","StopDialogue(pTarget)"]],
//		[2,-1,0,"Damit kann man sicher gut B�ume f�llen.",-1,MCMC,[true,0,0,0,true],0,["SetStartDialogueEx(3)","StopDialogue(pTarget)"]],
        [0,-1,0,"Das ist eine Axt. Sie hat ein paar Scharten.",-1,MCMC,0,0,["SetStartDialogueEx(2)","StopDialogue(pTarget)"]],
        [1,-1,0,"Eine schartige Axt...",-1,MCMC,0,0,["SetStartDialogueEx(2)","StopDialogue(pTarget)"]],
        [2,-1,0,"Damit kann man sicher gut B�ume f�llen.",-1,MCMC,0,0,["SetStartDialogueEx(3)","StopDialogue(pTarget)"]],
		[3,-1,0,"Hmm... auf dem Schaft ist etwas eingeritzt...",-1,MCMC],
		  [4,3,"Weiter","Answin",0,StdDlgIconContinue(),0,0,[]],

		//[9,-1,"Abbrechen","",0,[MCMX,0,0,0,0,-1],-1,0,"StopDialogue(pTarget)"]
		StdDlgArrayExitAlways()
];}

/*--- Inuk am Iglu ---*/

// in A2 hatte er die Axt
func MsgDialogueBardrik() { return [
		[0,-1,0,"Gr��e! Ich bin Bardrik",0,NONE,0,0,["SetStartDialogue(pSpeaker,1)",StdDlgVar("Create","Cancel","=1")]],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		  [2,[0,1,7,8,9],"Was macht Ihr hier?","Ich wohne hier. Das da hinten ist mein Haus.",0,0,0,StdDlgVar("!","A",""),StdDlgVar("Create","A","=1")],
		    [3,[2,1,7,8,9],"Ah, ein Iglu. Davon habe ich schon geh�rt.","Ganz genau!",0,0,0,[StdDlgVar("","A","==1"),"LocalN2(\"cProf\",pTarget)==\"Mage\""],StdDlgVar("","A","=2")], // Magier
		    [4,[2,1,7,8,9],"Ein Haus aus Eis?","Ja, wir nennen es ein Iglu",0,0,0,[StdDlgVar("","A","==1"),"LocalN2(\"cProf\",pTarget)!=\"Mage\""],StdDlgVar("","A","=2")], // sonst
              [5,[1,3,4,7,8,9],"Zu welchem Volk geh�rt Ihr?","Ich bin ein Inuk. Wir sind eine alte Hochkultur.",0,0,0,StdDlgVar("","A","==2"),StdDlgVar("","A","=3")],
                [6,[1,5,7,8,9],"Hochkultur?","Ja, weil wir so hoch oben in den Bergen leben.",0,0,0,StdDlgVar("","A","==3"),StdDlgVar("","A","=4")],
          // Anspielung auf A2
          [7,[0,1,2,3,4,5,6,9],"Ist Euch nicht langweilig?","Nein, manchmal schenke ich den Leuten �xte und tue so, als ob ich nicht wei�, was eine Axt ist.",0,0,0,StdDlgVar("","B","==0"),[StdDlgVar("Create","B","=1"),StdDlgVar("","Cancel","=0")]],
            [8,7,"Ihr k�nntet die �xte auch verkaufen.","Die kann hier oben niemand gebrauchen, es gibt ja weit und breit keine B�ume.",0,0,0,StdDlgVar("","C","==0"),[StdDlgVar("Create","D","=1"),StdDlgVar("","Cancel","=1")]],
               [9,[0,1,7],"K�nnt ihr mir eine Axt schenken?", "Nein, jetzt wo ich meinen Trick verraten habe, w�re es nicht mehr witzig f�r mich.",0,0,0,[StdDlgVar("","D","==1"),StdDlgVar("","E" == 0)], StdDlgVar("Create","E","=1")],
          [10,[0,1,7,9],"Was bedeutet Euer Name?",["Das geht Euch nichts an.","Das sage ich nicht."],0,0,0,[DlgObjVar("",gDialogue_TalkedToBardrik,"==0"),DlgObjVar("",gDialogue_AskedJallikAboutNames,"==1")],DlgObjVar("Create",gDialogue_TalkedToBardrik,"=1")],
          [11,[0,1,7,9],Format("Ihr hei�t %s",gDialogue_BardrikName),"Tja, jetzt wisst Ihr es. Na gut, was wollt ihr kaufen?",0,0,0,[DlgObjVar("",gDialogue_AskedJallikAboutBardrik,"==1",StdDlgVar("","CanBuy","==0"))],StdDlgVar("Create","CanBuy","=1")],
          // Quest?
          [99,[0,1,2,3,4,5,6,7,8,9],"Habt Ihr sonst irgendwelche Probleme?","Nein, eigentlich nicht. Fragt mal meinen Freund Jallik, der fischt unten an der K�ste im Osten.",0,0,0,StdDlgVar("","C","==0"),[StdDlgVar("Create","C","=1"),DlgObjVar("",gDialogue_JallikProblems,"=1")]],
  		StdDlgArrayExitAlways()
];}


/*--- Fischender Inuk ---*/

func MsgDialogueJallik() { return [
		[0,-1,0,"Jallik mein Name, wer seid Ihr?.",0,NONE,0,0,"SetStartDialogue(pSpeaker,1)"],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		// Quest
		  [2,[0,1],"Ihr seid Fischer?", "Jap, so siehts aus. Sagt doch bereits mein Name.",0,0,0,StdDlgVar("", "A", "==0"),StdDlgVar("Create","A","=1")],
		   [3,[2,1,12,13],"�h...", "Na Jallik...",0,0,0,[StdDlgVar("", "A", "==1"),StdDlgVar("","B","==0")],StdDlgVar("Create","B","=1")],
		    [4,[3,1,12,13],"Ja?", "Ah, ich sehe schon, ihr kommt nicht von hier. Jallik hei�t: Fisch-aus-dem-Wasser-Zieher.",0,0,0,[StdDlgVar("","B","==1"),StdDlgVar("","Yes","==0")],StdDlgVar("Create","Yes","=1")],
		     [5,[4,0,1,12,13],"Haben alle Eure Namen eine Bedeutung?", "Na klar, Eure vielleicht nicht?",0,0,0,[StdDlgVar("","Yes","==1"), StdDlgVar("","C","==0")], [StdDlgVar("Create","C","=1"),DlgObjVar("Create",gDialogue_AskedJallikAboutNames,"=1")]],
		      [6,[5,0,1,12,13],"Was bedeutet der Name Bardrik?", Format("Ah, ein Klassiker. Bardrik hei�t: %s.",gDialogue_BardrikName),0,0,0,[StdDlgVar("","C","==1"),DlgObjVar("",gDialogue_TalkedToBardrik,"==1"),DlgObjVar("",gDialogue_AskedJallikAboutBardrik,"==0")],DlgObjVar("Create",gDialogue_AskedJallikAboutBardrik,"=1")],
              [7,[5,6,0,1,12,13], "Ganz sch�n spezieller Name...", "Ja, darauf sind wir stolz. Unser Name ist unser Schicksal.",0,0,0,[StdDlgVar("","C","==1"),StdDlgVar("","Special","==0")],StdDlgVar("Create","Special","=1")],
              [8,[5,6,0,1,12,13], "Wie bekommt ihr eure Namen?", "Ach, das ist 'ne lange Geschichte, die wollt ihr nicht h�ren.",0,0,0,[StdDlgVar("","C","==1"),StdDlgVar("","Story","==0")],StdDlgVar("Create","Story","=1")],
               [9,[8,5,6,0,1,12,13], "Und die Kurzfassung?", "I am error.",0,0,0,StdDlgVar("","Story","==1"),StdDlgVar("","Story","=2")], // TODO? ^^'
            [10,[1,2],"Gebt Ihr mir einen Fisch ab?","Tut mir leid, ich verkaufe nur ganze F�sser.",0,0,0,[StdDlgVar("","E","==0"),StdDlgVar("", "A", "==1"),"GetQuestStage(\"SomethingFishy\",pTarget)==0"],StdDlgVar("Create","E","=1")],
            [11,[1,2],"Kann ich bei Euch Fische kaufen?", "Klar, ich habe noch ein paar F�sser.",0,0,0,[StdDlgVar("","E","==0"),StdDlgVar("", "A", "==1"),"GetQuestStage(\"SomethingFishy\",pTarget)>=1"],StdDlgVar("Create","E","=1")],
            //[12,[10,11,0,1,12,13],"{{FBRL}} Fische kaufen: 20{{GOLD}}",["Hier, bittesch�n","Gerne wieder!","Viel Spa� damit."],0,[0, 0, 0, 0, 0, 0, 1],0,[StdDlgVar("","E","==1"),"(pTarget->~GetMoney())>=20","pSpeaker->~FindContents(FBRL)"],["pTarget->DoMoney(-20)","Exit(pSpeaker->~FindContents(FBRL),0,5)"]],
            //[13,[10,11,0,1,12,13],"{{FBRL}} Fische kaufen: 20{{GOLD}}","",0,[0, RGB(255,0,0), 0, 0, 0, 0, 1],0,[StdDlgVar("","E","==1"),"(pTarget->~GetMoney())<20","pSpeaker->~FindContents(FBRL)"],0],
            [12,[10,11,0,1,12],Format("{{FBRL}} Fische kaufen: %d{{GOLD}}",GetValue(0,FBRL)),["Hier, bittesch�n","Gerne wieder!","Viel Spa� damit."],0,[0, 0, 1, 0, 0, 0, 1],0,[StdDlgVar("","E","==1"),Format("(pTarget->~GetMoney())>=%d",GetValue(0,FBRL)),"pSpeaker->~FindContents(FBRL)"],["pTarget->DoMoney(-20)","Exit(pSpeaker->~FindContents(FBRL),0,5)"]],
            [13,-1,"Bardrik meinte Ihr habt vielleicht Probleme","Wirklich? Ich kann mich nicht beschweren.",0,0,0,[StdDlgVar("",gDialogue_JallikProblems,"==1"),StdDlgVar("!","Problems","")],[StdDlgVar("Create","Problems","=1")]],
	    // TODO: nach der H�hle hinter ihm fragen k�nnen
  		StdDlgArrayExitAlways()
];}

/*--- Amazone ---*/

func MsgDialogueAmuri() { return [
		[0,-1,0,"Sied gegr��t! Ich bin Amuri.",0,NONE,0,0,"SetStartDialogue(pSpeaker,1)"],
		// "Sied" verarschen!!
		[1,-1,0,["Sch�n Euch wiederzusehen.","Sied gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		StdDlgArrayExitAlways()
];}

/*--- Amazone ---*/

func MsgDialogueFerturi() { return [
		[0,-1,0,"Hallo! Ferturi mein Name.",0,NONE,0,0,"SetStartDialogue(pSpeaker,1)"],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		StdDlgArrayExitAlways()
];}


/*--- Amazone ---*/

func MsgDialogueNakila() { return [
		[0,-1,0,"Gr��e! Ich bin Nakila.",0,NONE,0,0,"SetStartDialogue(pSpeaker,1)"],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		StdDlgArrayExitAlways()
];}


/*--- Amazone ---*/

func MsgDialogueJalani() { return [
		[0,-1,0,"Ich bin Jalani, wer seid Ihr?",0,NONE,0,0,"SetStartDialogue(pSpeaker,1)"],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		StdDlgArrayExitAlways()
];}


/*--- Amazone ---*/

// Sie sagt "Seid" richtig. Man kann beide darauf ansprechen
// es stellt sich heraus, dass die andere immer die Fremden
// verarscht
func MsgDialogueNirka() { return [
		[0,-1,0,"Seid gegr��t! Ich bin Nirka.",0,NONE,0,0,"SetStartDialogue(pSpeaker,1)"],
		[1,-1,0,["Sch�n Euch wiederzusehen.","Seid gegr��t!","Sch�n Euch zu sehen!"],0,MCMC],
		StdDlgArrayExitAlways()
];}
