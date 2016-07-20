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

<<<<<<< HEAD
void ATangibleActor::StartInteraction(class UHand* param)
{

}

<<<<<<< HEAD
void ATangibleActor::StartInteraction(class UHand* param)
{

}

=======
>>>>>>> origin/master
void ATangibleActor::QuitInteraction(class UHand* param)
{

}
<<<<<<< HEAD
=======
=======
void ATangibleActor::Beingapproached(class UHand* param) {
	if (Status != Idle)
		return;
	TargetHand = param;
	Status = InteractionStatus::Approaching;
}
void ATangibleActor::QuitInteraction(class UHand* param) {
	if (Status != Interacting)
		return;
	TargetHand = NULL;
	Status = InteractionStatus::Idle;
}
>>>>>>> origin/master
>>>>>>> origin/master
