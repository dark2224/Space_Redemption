// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "TangibleActor.h"
#include "InteractionStatus.h"


// Sets default values
ATangibleActor::ATangibleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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

void ATangibleActor::Beingapproached(class UHand* param) {
	if (Status != Idle)
		return;
	TargetHand = param;
	Status = InteractionStatus::Approaching;
}

void ATangibleActor::StartInteraction(class UHand* param)
{

}

void ATangibleActor::QuitInteraction(class UHand* param) {
	if (Status != Interacting)
		return;
	TargetHand = NULL;
	Status = InteractionStatus::Idle;
}
