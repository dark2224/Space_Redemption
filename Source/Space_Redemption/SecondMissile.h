// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SecondMissile.generated.h"

UCLASS()
// 2차 유도미사일의 운동은 위로 올라갔다가 떨어지는 운동과 상대 우주선에게 일직선상으로 다가가는 운동, 두가지로 나눌 수 있다.
class SPACE_REDEMPTION_API ASecondMissile : public AActor
{
	GENERATED_BODY()
private:
	// 유도 대상으로 삼는 타겟
	class AEnemy* target;
	// 포물선 운동의 중력에 대응되는 아래방향 가속도
	float droppingAcceleration;
	// 유도타겟을 향해 등속으로 일직선으로 날아가는 운동의 속력
	float RealVelocity;
	// FirstLeftTime은 처음 미사일이 사출됐을때 미사일이 적에게 맞기까지 걸리는 시간
	float FirstLeftTime;
	// LeftTime은 현재 미사일이 적에게 맞을때까지 남은 시간
	float LeftTime;
	// 미사일이 사출되는 시점의 수직방향 속도
	float FirstUpSpeed;
	// 미사일이 사출되는 시점의 타겟과 미사일 간 위치의 변위
	FVector _FirstDisplacement;
	// 한 프레임 전 미사일의 위치, 이를 현재위치랑 엮어서 미사일의 각도를 설정함.
	FVector _LocationBefore;
	
public:	
	// Sets default values for this actor's properties
	ASecondMissile();
	// 반드시 생성직후 호출해줘야함. 타겟으로 삼는 적을 매개변수로 유도미사일 운동에 필요한 초기설정을 해준다.
	// RealVelocity와 DroppingAccel의 값의 기본값은 1000,-1000으로, 블루프린트에서 임의로 수정할 수 있다.
	UFUNCTION(BlueprintCallable,Category = "Init")
	void GoGetEm(class AEnemy* target,float RealVelocity = 1000,float DroppingAccel = -1000);
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaSeconds ) override;

};
