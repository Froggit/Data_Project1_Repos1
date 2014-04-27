#strict 2

#include LF_I // ist ein Item

// Eigenschaften des Gegenstandes

public func ItemVolume(){ return 5; } // falls man einen Rucksack in den Rucksack stecken will oO

// Anordnung am Clonk

public func PackVolume(){ return 250; }	// Ist ein Rucksack? Gibt Volumen an
public func IsBackpack(){ return 8; }	// Gibt an, wie viele Reihen (5 Items) es halten kann
public func IsContainer(){ return true; } // Kann als Container durchsucht und geplündert werden
