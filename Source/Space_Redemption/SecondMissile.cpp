// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "Enemy.h"
#include "SecondMissile.h"


// Sets default values
ASecondMissile::ASecondMissile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASecondMissile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASecondMissile::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);
	LeftTime -= DeltaTime;
	SetActorLocation(target->GetActorLocation() + (_FirstDisplacement*LeftTime / FirstLeftTime));
	AddActorWorldOffset(FVector(0,0,FirstUpSpeed*LeftTime+0.5*droppingAcceleration*LeftTime*LeftTime));
	SetActorRotation(FRotationMatrix::MakeFromX(GetActorLocation() - _LocationBefore).Rotator());
	_LocationBefore = GetActorLocation();
}

void ASecondMissile::GoGetEm(AEnemy* target, float RealVelocity /* = 1000 */, float DroppingAccel /* = -1000 */) {
	this->target = target;
	this->RealVelocity = RealVelocity;
	_FirstDisplacement = GetActorLocation() - target->GetActorLocation();
	LeftTime = FirstLeftTime = _FirstDisplacement.Size() / RealVelocity;
	this->droppingAcceleration = DroppingAccel;
	FirstUpSpeed = -0.5*DroppingAccel*FirstLeftTime;
	_LocationBefore = GetActorLocation();
}