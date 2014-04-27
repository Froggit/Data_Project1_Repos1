#strict 2
#include LF_I
#include LF_R

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

public func GetInventoryActivateText(){ return "$TxtRead$"; }
public func CanBeActivated(){ return "true"; }


protected func Hit() { Sound("WoodHit*"); }
