/* Reliquien */

#strict 2
#include LF_I

public func GetMenuInvIcon()
{
	var gfx = GetGraphics();
	var offset = 0;

	if(gfx == "Amulet")
		offset = 1;
	if(gfx == "Crown")
		offset = 2;

	return Format("{{%i:%d}}",GetID(),offset);
}
