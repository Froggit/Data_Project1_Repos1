/*-- Holzwasserfass --*/

#strict
#include WDBR
#include LF_I
#include LF_R

// Fassdaten
public func BarrelMaterial() { return(Material("Water")); }
public func BarrelMaterialName() { return("Fish"); }

/* Aufschlag */ // Da soll es nix machen

public func BarrelEject()
{
}


public func Initialize()
{
	SetDialogue("BernikasFishBarrel");
	_inherited();
}

public func Activate(object pObj)
{
	StartDialogue(pObj);
	return true;
}

//public func IsInteractiveItem(){ return true; }
public func MenuQueryCancel(){ return true; }

public func GetInventoryActivateText(){ return "Untersuchen"; }
public func CanBeActivated(){ return "true"; }
