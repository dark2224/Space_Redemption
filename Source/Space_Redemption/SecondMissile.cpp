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
	// 먼저 미사일의 위치를 설정한다. 
	// 미사일의 위치 = 타겟한 적의 위치 + 적으로부터의 초기변위*남은시간%
	SetActorLocation(target->GetActorLocation() + (_FirstDisplacement*LeftTime / FirstLeftTime));
	// 미사일의 수직방향 위치를 더해준다. 
	// 미사일의 높이 = 초기 미사일의 수직방향 속도 * 시간 + 0.5*수직방향 가속도*시간^2
	AddActorWorldOffset(FVector(0,0,FirstUpSpeed*LeftTime+0.5*droppingAcceleration*LeftTime*LeftTime));
	// 미사일이 바라보는 방향 = 이전위치가 현재 위치를 바라보는 방향
	SetActorRotation(FRotationMatrix::MakeFromX(GetActorLocation() - _LocationBefore).Rotator());
	_LocationBefore = GetActorLocation();
}

void ASecondMissile::GoGetEm(AEnemy* target, float RealVelocity /* = 1000 */, float DroppingAccel /* = -1000 */) {
	//DroppingAccelearation~_LocationBefore까지 모든 필드를 대상 적의 상태에 맞게 초기화한다.
	this->target = target;
	this->RealVelocity = RealVelocity;
	_FirstDisplacement = GetActorLocation() - target->GetActorLocation();
	LeftTime = FirstLeftTime = _FirstDisplacement.Size() / RealVelocity;
	this->droppingAcceleration = DroppingAccel;
	FirstUpSpeed = -0.5*DroppingAccel*FirstLeftTime;
	_LocationBefore = GetActorLocation();
}