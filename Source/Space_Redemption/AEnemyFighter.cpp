// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "AEnemyFighter.h"

AAEnemyFighter::AAEnemyFighter() {
	PrimaryActorTick.bCanEverTick = true;
}
void AAEnemyFighter::BeginPlay()
{
	Super::BeginPlay();
}
void AAEnemyFighter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	switch (_Status) {
	case Approaching:
		if ((GetActorLocation() - _target->GetActorLocation()).Size() < _EncounterRange)
			_Status = Firing; // 여기서 정면방향으로 총알 발사시작하면 됨.
		break;
	case Firing:
		if ((GetActorLocation() - _target->GetActorLocation()).Size() < _EvasionRange)
			_Status = Evading; // 여기서 총알발사 멈추면 됨.
		break;
	case Evading:
		_ElapsedTime += DeltaTime;
		if (_ElapsedTime > _EvasionTime) {
			_ElapsedTime = _EvasionTime;
			_Status = RunningAway;
		}
		SetActorRotation(_FirstRotation);
		AddActorLocalRotation(_ElapsedTime / _EvasionTime*_EvasionDeltaRotator);
		if (_Status == RunningAway) {
			_ElapsedTime = 0.0;
		}
		break;
	case RunningAway:
		_ElapsedTime += DeltaTime;
		if (_ElapsedTime > _LifeTimeAfterEvasion)
			Destroy();
		break;
	}
	AddActorWorldOffset(GetActorForwardVector()*_Speed*DeltaTime);
}
void AAEnemyFighter::SetStategy(AActor* target, float Speed, FRotator LastEvasionDeltaRotator, float EncounterRange, float EvasionRange, float EvasionTime, float LifeTimeAfterEvasion)
{
	_FirstRotation = FRotationMatrix::MakeFromX(target->GetActorLocation() - GetActorLocation()).Rotator();
	_target = target;
	_Speed = Speed;
	_EvasionDeltaRotator = LastEvasionDeltaRotator;
	_EncounterRange = EncounterRange;
	_EvasionRange = EvasionRange;
	_EvasionTime = EvasionTime;
	_LifeTimeAfterEvasion = LifeTimeAfterEvasion;
	SetActorRotation(_FirstRotation);
}