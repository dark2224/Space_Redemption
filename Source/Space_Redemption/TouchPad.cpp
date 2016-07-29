// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "MiniGun.h"
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
void ATouchPad::StartSecondaryGrap() {
	Minigun->StartRotation();
	MinigunSoundLoop->Play();
}
void ATouchPad::StopSecondaryGrap() {
	Minigun->StopRotation();
	MinigunSoundEnd->Play();
	MinigunSoundLoop->FadeOut(0.5f,0.0f);
}
void ATouchPad::SetSound(UAudioComponent* GunfiringSound, UAudioComponent* EndSound) {
	this->MinigunSoundLoop = GunfiringSound;
	this->MinigunSoundEnd = EndSound;
}