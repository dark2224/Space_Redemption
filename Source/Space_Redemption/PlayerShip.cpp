// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "TangibleActor.h"
#include "PilotPawn.h"
#include "PlayerShip.h"
#include "HandleStick.h"
#include "TouchPad.h"
#include "Minigun.h"
#include <cmath>


// Sets default values
APlayerShip::APlayerShip()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Cockpit = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cockpit"));
	//Minigun = GetWorld()->SpawnActor<AMiniGun>(AMiniGun::StaticClass());
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

void APlayerShip::DefaultSet(class ATangibleActor* EmergencyLever_p, ATouchPad* GunPad_p, AHandleStick* HandleStick_p, class ATangibleActor* MissileButton_p, class APilotPawn* Pilot_p, class AMiniGun* minigun_p)
{
	this->EmergencyLever = EmergencyLever_p;
	this->GunPad = GunPad_p;
	this->HandleStick = HandleStick_p;
	this->MissileButton = MissileButton_p;
	this->Pilot = Pilot_p;
	this->Minigun = minigun_p;
	EmergencyLever_p->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	GunPad_p->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	HandleStick_p->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	MissileButton_p->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	Pilot_p->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	GunPad->LinkMinigun(Minigun);
	Minigun->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	Minigun->SetActorRelativeLocation(FVector(0, 0, -170));
	Minigun->LinkPad(GunPad);
}

void APlayerShip::Tick(float DeltaTime)
{
	// 회전
	Super::Tick(DeltaTime);
	if (HandleStick->GetNormalizedFacingVector().IsZero())
	{
		if (RotatorSize(CurrentRotationSpeed) > DeltaTime*RotationDeccelration)
			CurrentRotationSpeed -= DeltaTime*RotationDeccelration / (RotatorSize(CurrentRotationSpeed))*CurrentRotationSpeed;
		else
			CurrentRotationSpeed = FRotator::ZeroRotator;
	}
	else
	{
		TargetRotationSpeed = FRotator(-MaxRotationspeed*HandleStick->GetNormalizedFacingVector().X, MaxRotationspeed*HandleStick->GetNormalizedFacingVector().Y,0.0f);
		CurrentRotationSpeed += DeltaTime*RotationAcceleration / RotatorSize(TargetRotationSpeed - CurrentRotationSpeed)*(TargetRotationSpeed - CurrentRotationSpeed);
		
		//CurrentRotationSpeed += DeltaTime*RotationAcceleration*FRotator(-HandleStick->GetNormalizedFacingVector().X, HandleStick->GetNormalizedFacingVector().Y, 0);
		//if (RotatorSize(CurrentRotationSpeed) > MaxRotationspeed)
		//	CurrentRotationSpeed = MaxRotationspeed / RotatorSize(CurrentRotationSpeed)*CurrentRotationSpeed;
	}

	if (GetActorRotation().Pitch > PitchClamper)
		CurrentRotationSpeed.Pitch = fmin(0, CurrentRotationSpeed.Pitch);
	if (GetActorRotation().Pitch < -PitchClamper)
		CurrentRotationSpeed.Pitch = fmax(0, CurrentRotationSpeed.Pitch);
	SetActorRotation(GetActorRotation() + DeltaTime*FRotator(CurrentRotationSpeed.Pitch, CurrentRotationSpeed.Yaw, 0));
	//전진
	if (IsAccelerating)
		CurrentSpeed += DeltaTime*Acceleration;
	else
		if (CurrentSpeed > DeltaTime*Decceleration)
			CurrentSpeed -= DeltaTime*Decceleration;
		else
			CurrentSpeed = 0;
	// 전방방향 이동
	// 엑셀 밟고 있을때
	if (HandleStick->GetisPushingSecond())
	{
		CurrentSpeed = (CurrentSpeed + DeltaTime*Acceleration > MaxSpeed) ? MaxSpeed : CurrentSpeed + DeltaTime*Acceleration;
	}
	else
	{
		CurrentSpeed = (CurrentSpeed - DeltaTime*Decceleration < 0) ? 0 : CurrentSpeed - DeltaTime*Decceleration;
	}
	AddActorLocalOffset(FVector(CurrentSpeed, 0, 0));
	//AddActorLocalRotation((DeltaTime*CurrentRotationSpeed).Quaternion());
	//AddActorWorldRotation(FRotator(0,0,GetActorRotation().Roll));
	//SetActorRotation(FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw,0.0f));
	//AddActorLocalRotation(FRotator(0,0, GetActorRotation().Roll));
}
float APlayerShip::RotatorSize(FRotator param) {
	return sqrtf(param.Pitch*param.Pitch + param.Roll*param.Roll + param.Yaw*param.Yaw);
}