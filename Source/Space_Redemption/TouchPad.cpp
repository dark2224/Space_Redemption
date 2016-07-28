// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "TouchPad.h"


void ATouchPad::SetMappingCoordinate(FVector2D value) {
	MappingCoordinate = value;
}
FVector2D ATouchPad::GetMappingCoordinate() {
	return MappingCoordinate;
}
void ATouchPad::LinkMinigun(AMiniGun* target) {
	Minigun = target;
}