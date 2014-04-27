/*-- Skill - System  --*/

#strict 2
#appendto LF_S

/* you can overload this in your own scenario in system.c4g - the rest happens automatically */

global func RPGAttributeList()
{
	return [
		//	name,			string,					lower limit,	upper limit,	cost function,	availability function
		[	"Strength",		"$AttributeStrength$",	0,				20,				"",				""],
		[	"Dexterity",	"$AttributeDexterity$",	0,				20,				"",				""],
		[	"Mana",			"$AttributeMana$",		0,				20,				"",				""],
		[	"Health",		"$AttributeHealth$",	0,				20,				"",				""]
	];
}

global func RPGSkillList()
{
	return [
		//	name,			string,					lower limit,	upper limit,	cost function,	availability function
		[ "Blacksmith",		"$SkillBlacksmith$",	0,				20,				"",				""]
	];
}

global func RPGPerkList()
{
		//	name,					string,						parent,		cost function,	availability function
	return [
		[	"PLightWeapons",		"$PerkLightWeapons$",		"",			"",				""],
		[	"PHeavyWeapons",		"$PerkHeavyWeapons$",		"",			"",				""],
		[	"PLightArmor",			"$PerkLightArmor$",			"",			"",				""],
		[	"PHeavyArmor",			"$PerkHeavyArmor$",			"",			"",				""],
		[	"PRanged",				"$PerkRangedWeapons$",		"",			"",				""],
		[	"PThrown",				"$PerkThrownWeapons$",		"",			"",				""],
		[	"PBombs",				"$PerkBombs$",				"",			"",				""],
		[	"PArrows",				"$PerkArrows$",				"",			"",				""],
		[	"PPotions",				"$PerkPotions$",			"",			"",				""],
		[	"PHide",				"$PerkHide$",				"",			"",				""],

	];
}


/* Klassen

K�mpfer:

K�mpfer - K�mpfer
kann schwere R�stungen tragen
kann alle Waffen benutzen

Magier - K�mpfer
kann schwerter nutzen
kann buff-tr�nke brauen
kann leichte zauber sprechen
kann keine schweren r�stungen tragen

ninja - k�mpfer
kann wurfwaffen benutzen
kann schwerter benutzen
kann keine schweren r�stungen tragen

magier:

Magier - Magier: Vollzauberer
kann alle Zauber benutzen
kann St�be benutzen
kann keine Fernwaffen nutzen
kann keine Schilde nutzen
kann keine?/nur leichte R�stungen nutzen

Magier - K�mpfer: Kampfmagier
kann schwerter nutzen
einschr�nkung der zauber
kann schwerter nutzen aber keine schilde
kann leichte r�stungen tragen

magier - ninja: Alchemist
einschr�nkung der zauber
kann buff-tr�nke brauen
kann keine r�stung tragen

Ninja:

Ninja - Ninja
kann fernkampf benutzen
kann wurfwaffen benutzen
kann bomben bauen
kann besondere pfeile bauen
kann sich tarnen?
kann keine r�stung nutzen


k�mpfer ninja
kann wurfwaffen benutzen
kann schwerter benutzen
kann bomben bauen
kann sich nicht tarnen
kann leichte r�stung tragen





*/
