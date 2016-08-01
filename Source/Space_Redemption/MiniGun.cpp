// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "TouchPad.h"
#include <cmath>
#include "MiniGun.h"
#include "Enemy.h"


// Sets default values
AMiniGun::AMiniGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	LaserPointer = CreateDefaultSubobject<UStaticMeshComponent>("LaserPointer");
	RealGunMesh = CreateDefaultSubobject<UStaticMeshComponent>("RealGun");
	LeftFire = CreateDefaultSubobject<UParticleSystemComponent>("LeftMuzzleFire");
	RightFire = CreateDefaultSubobject<UParticleSystemComponent>("RightMuzzleFire");
	BulletHitEffect = CreateDefaultSubobject<UParticleSystemComponent>("BulletHitEffect");
	LaserPointer->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	RealGunMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	LeftFire->AttachToComponent(RealGunMesh, FAttachmentTransformRules::KeepRelativeTransform);
	RightFire->AttachToComponent(RealGunMesh, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AMiniGun::BeginPlay()
{
	Super::BeginPlay();
}

// Minigun.cpp




void AMiniGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (targetPad) {
		LaserPointer->SetRelativeRotation(FRotator(Clamper.Pitch*(targetPad->GetMappingCoordinate().X + 1), Clamper.Yaw*targetPad->GetMappingCoordinate().Y, 0));
	}
	//레이저 포인터와 총구가 향하는 방향이 같지 않은가?
	if (!LaserPointer->RelativeRotation.Equals(RealGunMesh->RelativeRotation))
	{
		//그 방향간의 변위가 졸라 작은가?
		if (SquaredRotatorSize(LaserPointer->RelativeRotation - RealGunMesh->RelativeRotation) < powf(GunRotatingSpeed*DeltaTime, 2))
			RealGunMesh->SetRelativeRotation(LaserPointer->RelativeRotation);
		else
		{
			RealGunMesh->AddLocalRotation(DeltaTime*GunRotatingSpeed / RotatorSize(LaserPointer->RelativeRotation - RealGunMesh->RelativeRotation)*(LaserPointer->RelativeRotation - RealGunMesh->RelativeRotation));
		}
	}
	if (Deccelerating)
	{
		CurrentRotationSpeedFactor -= DeltaTime;
		if (CurrentRotationSpeedFactor < 0)
		{
			Deccelerating = false;
			CurrentRotationSpeedFactor = 0;
		}
	}
	// 발사중인가?
	if (targetPad)
		//targetPad->GetisPushingSecond()
		if (targetPad->GetisPushingSecond()) {
			AccumulatedTimeAfterFire += DeltaTime;
			if (AccumulatedTimeAfterFire >= GapBetweenFire)
			{
				if (isleftturn)
				{
					LeftFire->ActivateSystem();
					RightFire->DeactivateSystem();
				}
				else
				{
					RightFire->ActivateSystem();
					LeftFire->DeactivateSystem();
				}
				if (Guntarget) {
					BulletHitEffect->SetWorldLocationAndRotation(AnticipatedHitLocation, (-LaserPointer->GetForwardVector()).ToOrientationRotator());
					BulletHitEffect->ActivateSystem();
					BulletImpactSound->Play();
					Guntarget->Set_Damage(2000000);
				}
				else {
					BulletHitEffect->DeactivateSystem();
				}
				AccumulatedTimeAfterFire -= GapBetweenFire;
				isleftturn = !isleftturn;
			}
		}
}
void AMiniGun::SetHitTargetAndLocation(AEnemy* target, FVector hitlocation) {
	Guntarget = target;
	AnticipatedHitLocation = hitlocation;
}
void AMiniGun::LinkPad(ATouchPad* target) {
	targetPad = target;
}
float AMiniGun::RotatorSize(FRotator param) {
	return sqrtf(param.Pitch*param.Pitch + param.Roll*param.Roll + param.Yaw*param.Yaw);
}
float AMiniGun::SquaredRotatorSize(FRotator param) {
	return param.Pitch*param.Pitch + param.Roll*param.Roll + param.Yaw*param.Yaw;
}
void AMiniGun::StartRotation() {
	CurrentRotationSpeedFactor = 1;
}
void AMiniGun::StopRotation() {
	Deccelerating = true;
}
float AMiniGun::GetRotationSpeed() {
	return CurrentRotationSpeedFactor*GunRotatingSpeed;
}
void AMiniGun::ResetTarget() {
	Guntarget = nullptr;
}
void AMiniGun::SetBulletImpactSound(UAudioComponent* value) {
	BulletImpactSound = value;
}