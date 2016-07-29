// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "TangibleActor.h"
#include "Pilotpawn.h"
#include "InteractionStatus.h"


// Sets default values
ATangibleActor::ATangibleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it..
	PrimaryActorTick.bCanEverTick = true;

}
// Called when the game starts or when spawned
void ATangibleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATangibleActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}


void ATangibleActor::StartBeingApproached(class UHand* handparam, class USceneComponent *RealHandSceneParm, FRotator DeltaRotation) {
	if (Status != Idle)
		return;
	//TargetPilotPawn = param;
	TargetHand = handparam;
	//HandCollision
	TargetRealHandScene = RealHandSceneParm;

	TargetHand->StartApproaching(this);
	Status = InteractionStatus::Approaching;
	DistanceBeforeApproach = (TargetHand->GetComponentLocation()-DesiredHandTransform->GetComponentLocation()).Size();
	RotatorBeforeApproach = TargetHand->GetComponentRotation();
	ApproachingDeltaRotation = DeltaRotation;

	NormalizedApproachingDistance = 1;
}
bool ATangibleActor::GetisPushingSecond() {
	return isPushingSecond;
}
void ATangibleActor::SetIsPushingSecond(bool value) {
	if (!isPushingSecond && value)
		StartSecondaryGrap();
	if (isPushingSecond && !value)
		StopSecondaryGrap();
	isPushingSecond = value;
}
/*
void ATangibleActor::QuitInteraction(class UHand* param) {
	if (Status != Interacting)
		return;
	TargetHand = NULL;
	Status = InteractionStatus::Idle;
}*/