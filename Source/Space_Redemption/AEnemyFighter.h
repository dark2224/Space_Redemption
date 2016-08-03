// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Enemy.h"
#include "AEnemyFighter.generated.h"

/**
 *
 */
UCLASS()
class SPACE_REDEMPTION_API AAEnemyFighter : public AEnemy
{
	GENERATED_BODY()
private:
	enum Status {
		Approaching, Firing, Evading, RunningAway
	};
	Status _Status = Approaching;
	bool _Evading = false;
	float _Speed;
	FRotator _EvasionDeltaRotator;
	FRotator _FirstRotation;
	AActor* _target;
	float _EncounterRange;
	float _ElapsedTime = 0;
	float _EvasionTime;
	float _EvasionRange;
	float _LifeTimeAfterEvasion;
public:
	AAEnemyFighter();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	// 공격패턴 : 생성지점에서 공격대상을 향해 일직선으로 날아오다가 포착거리내가 되면 공격을 시작, 회피기동거리내가 되면 회피기동을 시작함.
	// 공격대상, 기체의 속도, 포착과 공격을 시작할 거리,회피기동을 시작할 거리, 회피기동할때 바뀔 각도변위, 회피기동에 쓰일 시간을 매개변수로 받는다.
	UFUNCTION(BlueprintCallable, category = "Initialization")
		void SetStategy(AActor* target, float Speed = 1000, FRotator LastEvasionDeltaRotator = FRotator(0.0f,0.0f,0.0f), float EncounterRange = 2000.0f, float EvasionRange = 1000.0f, float EvasionTime = 1.0f, float LifeTimeAfterEvasion = 5.0f);
};