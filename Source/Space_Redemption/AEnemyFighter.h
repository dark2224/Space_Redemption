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
	// �������� : ������������ ���ݴ���� ���� ���������� ���ƿ��ٰ� �����Ÿ����� �Ǹ� ������ ����, ȸ�Ǳ⵿�Ÿ����� �Ǹ� ȸ�Ǳ⵿�� ������.
	// ���ݴ��, ��ü�� �ӵ�, ������ ������ ������ �Ÿ�,ȸ�Ǳ⵿�� ������ �Ÿ�, ȸ�Ǳ⵿�Ҷ� �ٲ� ��������, ȸ�Ǳ⵿�� ���� �ð��� �Ű������� �޴´�.
	UFUNCTION(BlueprintCallable, category = "Initialization")
		void SetStategy(AActor* target, float Speed = 1000, FRotator LastEvasionDeltaRotator = FRotator(0.0f,0.0f,0.0f), float EncounterRange = 2000.0f, float EvasionRange = 1000.0f, float EvasionTime = 1.0f, float LifeTimeAfterEvasion = 5.0f);
};