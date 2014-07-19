/*-- Husky --*/

#strict 2
#include ANIM

/* Initialisierung */
local Bait;
local homeX, homeY;

protected func Initialize() { return(Birth()); }

/* TimerCall mit KI-Steuerung */

protected func Activity()
{
	if (!homeX && !homeY)
	{
		homeX = GetX();
		homeY = GetY();
	}

  // Geräusche machen
  if (!Random(8))
  {
	  Sound("Bark*");
  }
  else if (!Random(8))
  {
	  Sound("Knurr");
  }

  // Köder fressen
  if(Bait)
    if(ObjectDistance(Bait, this) <= 15)
      if(GetAction() == "Walk")
        {
        SetAction("Eat");
        SetXDir();
        }

  var pBait;
  // Nur wenn der Wipf ausgewachsen ist
  if (GetCon()==100)
   // Soll nicht zu einfach sein...
   if (!Random(5))
     // Ein Köder in der Nähe?
     while (pBait = FindObject( 0, -250,-250,500,500, 0,0,0,NoContainer(), pBait))
      // Köder?
      if(WildcardMatch(GetAction(pBait), "*MeatBait*"))
       // Je nach Köderqualität...
       if (Random(100) < pBait->~IsBait())
        {
         // ...hinrennen
         SetCommand(this, "Follow", pBait);
         // Und Köder merken
         Bait = pBait;
        }


  // Die folgenden Aktionen nur im Freien
  if (Contained()) return;

  // Die folgenden Aktionen nur im Gehen oder Schwimmen
  if (GetAction() != "Walk" && GetAction() != "Swim") return;

  // Auftauchen, wenn der Atem ausgeht
  if (InLiquid() && GetBreath() <= 25 && GetComDir() != COMD_Up)
   SetComDir(COMD_Up);

  // Brennenden Objekten ausweichen
  var pBurning;
  if(pBurning = FindObject(0, -!GetDir()*80,-30,80,35, OCF_OnFire))
  {
   if(!Random(5) || !SpaceToFlee(pBurning))
   {
    if(GetDir()) SetComDir(COMD_Right);
    else SetComDir(COMD_Left);
    Jump();
   }
   else
   {
    if(GetComDir()==COMD_Left) SetComDir(COMD_Right);
    else SetComDir(COMD_Left);
   }
  }

  // Nichts machen
  if (Random(2)) return;

  if (Distance(GetX(),GetY(),homeX,homeY) > 200)
  {
	  SetCommand(this,"MoveTo",0,homeX,homeY);
	  return;
  }

  // Springen
  if (GetAction() == "Walk")
   if (!Random(3)) return(Jump());

  // Hinsetzen
  if (GetAction() == "Walk")
    if (!Random(3)) return(SetAction("Sit"));

  // Umdrehen
  if (Random(2)) return TurnRight();
  return TurnLeft();
}

private func SpaceToFlee(pFromObj)
{
 var x=-100;
 if (GetX() > GetX(pFromObj)) x=100;

 // Am Rand der Landschaft eingesperrt
 if (!Inside(x+GetX(), 0, LandscapeWidth())) return false;

 // Am Rand einer Höhle eingesperrt
 if (!PathFree(GetX(),GetY(),GetX()+x,GetY())) return false;

 return true;
}

private func Sitting()
{
  // Weiterlaufen
  if (!Random(10)) SetAction("Walk");
}

/* Kontakt */

protected func ContactLeft()
{
	TurnRight();
}

protected func ContactRight()
{
	TurnLeft();
}

/* Aktionen */

public func TurnRight()
{
  if (Stuck() || (GetAction() != "Walk" && GetAction() != "Swim" && GetAction() != "Sit")) return;
  if (GetXDir() < 0) SetXDir(0);
  SetDir(DIR_Right);
  SetComDir(COMD_Right);
  if (GetAction() == "Sit") SetAction("Walk");
}

public func TurnLeft()
{
  if (Stuck() || (GetAction() != "Walk" && GetAction() != "Swim" && GetAction() != "Sit")) return;
  if (GetXDir() > 0) SetXDir(0);
  SetDir(DIR_Left);
  SetComDir(COMD_Left);
  if (GetAction() == "Sit") SetAction("Walk");
}

/* Einwirkungen */

protected func CatchBlow()
{
  if (GetAction() == "Dead") return;
  if (!Random(3)) Sound("hsk-pain1");
}

protected func Death() 
{
  Sound("hsk-die1");
  SetDir(0);
  ChangeDef(DHSK);
  SetAction("Dead");
}

/* Köder fressen */

protected func Eating()
{
  // Köder weg
  if(!Bait) return;
  // Köder fressen
  RemoveObject(Bait);
  // Schmeckt gut
  Sound("Snuff*");
}
