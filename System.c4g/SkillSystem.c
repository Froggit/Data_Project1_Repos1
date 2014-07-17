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

Kämpfer:

Kämpfer - Kämpfer
kann schwere Rüstungen tragen
kann alle Waffen benutzen

Magier - Kämpfer
kann schwerter nutzen
kann buff-tränke brauen
kann leichte zauber sprechen
kann keine schweren rüstungen tragen

ninja - kämpfer
kann wurfwaffen benutzen
kann schwerter benutzen
kann keine schweren rüstungen tragen

magier:

Magier - Magier: Vollzauberer
kann alle Zauber benutzen
kann Stäbe benutzen
kann keine Fernwaffen nutzen
kann keine Schilde nutzen
kann keine?/nur leichte Rüstungen nutzen

Magier - Kämpfer: Kampfmagier
kann schwerter nutzen
einschränkung der zauber
kann schwerter nutzen aber keine schilde
kann leichte rüstungen tragen

magier - ninja: Alchemist
einschränkung der zauber
kann buff-tränke brauen
kann keine rüstung tragen

Ninja:

Ninja - Ninja
kann fernkampf benutzen
kann wurfwaffen benutzen
kann bomben bauen
kann besondere pfeile bauen
kann sich tarnen?
kann keine rüstung nutzen


kämpfer ninja
kann wurfwaffen benutzen
kann schwerter benutzen
kann bomben bauen
kann sich nicht tarnen
kann leichte rüstung tragen





*/
