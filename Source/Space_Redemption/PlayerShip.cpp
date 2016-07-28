// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "TangibleActor.h"
#include "PilotPawn.h"
#include "PlayerShip.h"
#include "HandleStick.h"
#include <cmath>


// Sets default values
APlayerShip::APlayerShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Cockpit = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cockpit"));
	Cockpit->SetRelativeLocation(FVector(0, 0, 0));
	Cockpit->SetRelativeRotation(FRotator(0, 0, 90));
}

// Called when the game starts or when spawned
void APlayerShip::BeginPlay()
{
	Super::BeginPlay();
	//GWorld->SpawnActor<
}

// Called every frame

void APlayerShip::DefaultSet(class ATangibleActor* EmergencyLever_p, class ATangibleActor* GunPad_p, AHandleStick* HandleStick_p, class ATangibleActor* MissileButton_p, class APilotPawn* Pilot_p)
{
	this->EmergencyLever = EmergencyLever_p;
	this->GunPad = GunPad_p;
	this->HandleStick = HandleStick_p;
	this->MissileButton = MissileButton_p;
	this->Pilot = Pilot_p;
	EmergencyLever_p->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	GunPad_p->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	HandleStick_p->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	MissileButton_p->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	Pilot_p->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void APlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (HandleStick->GetNormalizedFacingVector().IsZero())
	{
		CurrentRotationSpeed -= RotationDeccelration /
			(sqrtf(CurrentRotationSpeed.Pitch*CurrentRotationSpeed.Pitch+
				CurrentRotationSpeed.Yaw*CurrentRotationSpeed.Yaw+
				CurrentRotationSpeed.Roll*CurrentRotationSpeed.Roll))
			*CurrentRotationSpeed;
	}
	else
	{
		CurrentRotationSpeed += RotationAcceleration*FRotator(HandleStick->GetNormalizedFacingVector().X, HandleStick->GetNormalizedFacingVector().Y,0);
	}
	AddActorLocalRotation((DeltaTime*CurrentRotationSpeed).Quaternion());
}