/*-- Axt --*/

#strict 2
#include LF_R
#include LF_I

/* Aufschlag */
protected func Hit()
{
  Sound("MetalHit*");
}

public func Initialize()
{
	SetDialogue("AnswinsAxe");
	SetStartDialogueEx(Random(2));
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
