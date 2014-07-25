
#strict 2
#appendto _STY

func DayNightCycleArmin()
{
//	return [[-1,"IsDay()","Message(\"Schon wieder ne Stunde rum\",pTarget)"],
//	        [-1,"IsNight()","Message(\"Schnarch!\",pTarget)"],
//	        [-1,"IsDay()","pTarget->~CastObjects(FLNT,2,60)"]];

	return [[6,0,"AddBehaviour(pTarget, gBehaviour_Wander, 20, [1745,1833,15,60])"],
	        [18,0,"RemoveBehaviour(pTarget, gBehaviour_Wander)"]];

}
