// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "HandleStick.h"



//AHandleStick::AHandleStick() {
//	Super::ATangibleActor();
//}
void AHandleStick::SetNormalizedFacingVector(FVector2D value) {
	_NormalizedFacingVector = value;
}
FVector2D AHandleStick::GetNormalizedFacingVector() {
	return _NormalizedFacingVector;
}
void AHandleStick::StartSecondaryGrap() {
	MovingLoopSound->FadeIn(0.7f);
	//MovingLoopSound->Play();
}
void AHandleStick::StopSecondaryGrap() {
	MovingLoopSound->FadeOut(0.7f,0.0f);
	//MovingLoopSound->Stop();
}
void AHandleStick::SetSound(UAudioComponent* reference){
	MovingLoopSound = reference;
}