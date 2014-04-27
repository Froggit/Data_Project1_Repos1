/*-- Axt --*/

#strict 2
#include LF_R
#include LF_I

public func Initialize()
{
	SetDialogue("MelvinsDiary");
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
