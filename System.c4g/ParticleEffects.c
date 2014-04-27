/*-- Neues Script --*/

#strict

/* Spawn-Effekt */

global func AddSpawnEffect(object pObj, int rgba, array options)
{
  if(!pObj)
    if(!(pObj = this()))
      return();
  AddEffect("Spawn", pObj, 5, 1, 0, 0, rgba, options);
}

global func FxSpawnStart(object pTarget, int iNo, int iTemp, int rgba, array options)
{
	  if(iTemp) return();
	  EffectVar(0, pTarget, iNo) = rgba;
	  EffectVar(1, pTarget, iNo) = 360;
	  if(GetType(options) != C4V_Array)
	  {
		  	 options=[];
	  }
	  else
	  {
		  if(options[3]==1) pTarget->SetClrModulation(RGBa(255,255,255,255));//SetVisibility(VIS_None,pTarget);
	  }
	  EffectVar(2, pTarget, iNo) = options;
}

global func FxSpawnTimer(object pTarget, int iNo)
{
	  var rgba = EffectVar(0, pTarget, iNo);
	  var a = EffectVar(1, pTarget, iNo);
	  var options = EffectVar(2, pTarget, iNo);
	  var part,rgba2,size,mod;
	  if(!(part=options[0])) part="PSpark";
	  if(!(rgba2=options[1])) rgba2=rgba;
	  if(!(mod=options[2])) mod = 5;

	  if( rgba2 != rgba)
	  {
		  var a0,r0,g0,b0,a360,r360,g360,b360,clr;
		  a0 = GetRGBaValue(rgba2,0);
		  r0 = GetRGBaValue(rgba2,1);
		  g0 = GetRGBaValue(rgba2,2);
		  b0 = GetRGBaValue(rgba2,3);
		  a360 = GetRGBaValue(rgba,0);
		  r360 = GetRGBaValue(rgba,1);
		  g360 = GetRGBaValue(rgba,2);
		  b360 = GetRGBaValue(rgba,3);
		  clr = RGBa( BoundBy(r0 + a*(r360-r0)/360,0,255), BoundBy(g0 + a*(g360-g0)/360,0,255), BoundBy(b0 + a*(b360-b0)/360,0,255), BoundBy(a0 + a*(a360-a0)/360,0,255) );
	  }
	  else clr = rgba;

	  if(EffectVar(1, pTarget, iNo) < 0 )
	  {
		CastParticles(part, 20, 50, GetX(pTarget), GetY(pTarget), 10, 50, rgba, rgba);

		if(options[3]==1) pTarget->SetClrModulation(RGBa(255,255,255,0));//SetVisibility(VIS_All,pTarget);
		if(options[3]==-1) pTarget->SetClrModulation(RGBa(255,255,255,255));//SetVisibility(VIS_None,pTarget);

		return(-1);
	  }
	  for(var i=0, x,y ; i < 5 ; i++)
	  {
		x = Cos(a - 90 * i, a * mod / 100);
		y = Sin(a - 90 * i, a * mod / 100);
		CreateParticle(part, GetX(pTarget) + x, GetY(pTarget) + y, 0,0, BoundBy((mod*(360 - Abs(a))) / 10, 5, 5*mod), clr, pTarget);
	  }

	  EffectVar(1, pTarget, iNo)-=10;
}
