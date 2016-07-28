// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "TouchPad.h"
#include "MiniGun.h"


// Sets default values
AMiniGun::AMiniGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LaserPointer = CreateDefaultSubobject<UStaticMeshComponent>("LaserPointer");
	RealGunMesh = CreateDefaultSubobject<UStaticMeshComponent>("RealGun");
}

// Called when the game starts or when spawned
void AMiniGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMiniGun::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (targetPad) {
		LaserPointer->SetRelativeRotation(FRotator(Clamper.Pitch*(targetPad->GetMappingCoordinate().X+1),Clamper.Yaw*targetPad->GetMappingCoordinate().Y , 0));
	}
	else {
		
	}
}
void AMiniGun::LinkPad(ATouchPad* target) {
	targetPad = target;
}