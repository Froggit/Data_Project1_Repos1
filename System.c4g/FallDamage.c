/*-- Neues Script --*/

#strict 2
#appendto _CLN

func Hit2(int xDir, int yDir)
{
	var speed = Distance(xDir,yDir);

	var fall = Max(0,(7*speed)/55 - 90);

	Log("FALLDAMAGE %d", fall);
	if(speed > 1500)
	{
		Log("SPLAT!!!");
		CastObjects(FLNT,30,30);
	}
}
