// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "HandleStick.h"




void AHandleStick::SetNormalizedFacingVector(FVector2D value) {
	_NormalizedFacingVector = value;
}
FVector2D AHandleStick::GetNormalizedFacingVector() {
	return _NormalizedFacingVector;
}