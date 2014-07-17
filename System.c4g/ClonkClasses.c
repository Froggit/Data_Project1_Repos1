/*-- Klassenauswahl --*/

#strict 2
#appendto _CLN

public func SetClass( int iLand, int iProf )
{
	RPGSetAttribute( "Strength", 1, this );
	RPGSetAttribute( "Dexterity", 1, this );
	RPGSetAttribute( "Magic", 1, this );

	CreateLocalN2("cLand",this);
	CreateLocalN2("cProf",this);

	if( iLand == 1 )
	{
		LocalN2("cLand",this)="Barony";
		RPGAddAttribute( "Strength", 2, this );
	}
	if( iLand == 2 )
	{
		LocalN2("cLand",this)="Valley";
		RPGAddAttribute( "Magic", 2, this );
	}
	if( iLand == 3 )
	{
		LocalN2("cLand",this)="Border";
		RPGAddAttribute( "Dexterity", 2, this );
	}

	if( iProf == 1 )
	{
		LocalN2("cProf",this)="Warrior";
		RPGAddAttribute( "Strength", 4, this );
	}
	if( iProf == 2 )
	{
		LocalN2("cProf",this)="Mage";
		RPGAddAttribute( "Magic", 4, this );
	}
	if( iProf == 3 )
	{
		LocalN2("cProf",this)="Rogue";
		RPGAddAttribute( "Dexterity", 4, this );
	}
}