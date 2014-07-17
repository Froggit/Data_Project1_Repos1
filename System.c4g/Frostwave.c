#strict 2
#appendto MFWV

func FxFrostwaveNSpellTimer(object pTarget, int iNumber, int iTime) {

  var iRaduis = EffectVar(1,pTarget,iNumber);
  // löschen falls schon zu weit
  if(iRaduis >= EffectCall(pTarget,iNumber,"MaxRange")) return(-1);

  // Position
  var iX = EffectVar(2,pTarget,iNumber);
  var iY = EffectVar(3,pTarget,iNumber);
  
  // Kombo?
  var dwSearchOCF = OCF_Alive;
  if (EffectVar(5,pTarget,iNumber)) dwSearchOCF += OCF_Collectible;
  
  var clr = RGB(0,238,255);
  if(GetFilm()) clr = RGB(255,255,255);
  // Effekt!
  CreateParticle("FrostWave",iX,iY, RandomX(-1,1),RandomX(-1,1), 400+10*iRaduis,clr);
var obj;

  var angle;
  // Alle Gegner wegschleudern
  while(obj = FindObject(0, -iRaduis-5+iX,-iRaduis-5+iY,iRaduis*2+10,iRaduis*2+10, dwSearchOCF, 0,0, NoContainer(), obj))
  {
    if(obj == Contained()) continue;
    if(Inside(Distance(GetX(obj), GetY(obj), iX, iY), iRaduis-5, iRaduis+5))
    {   
    angle=Angle(iX, iY, GetX(obj), GetY(obj) );     
    if(GetAlive(obj)) 
    { 
        Fling(obj, Sin(angle, 80)/9, -Cos(angle, 80)/9);
        if(!GetFilm()) if(!Frozen(obj)) Freeze(obj, EffectVar(4,pTarget,iNumber)); 
    }
    else 
     { 
        SetXDir(Sin(angle, 50), obj); SetYDir(-Cos(angle, 50), obj);
        SetController(GetController(EffectVar(4,pTarget,iNumber)),obj);
     }
    }
  } 
    
  EffectVar(1,pTarget,iNumber)+=8;
}

func FxFrostwaveNSpellMaxRange() { if(GetFilm()) return 90; return(150); }
