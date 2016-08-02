// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"

#include "Guided_Missile.h"

AGuided_Missile::AGuided_Missile()
	: m_fGravity(0.0f),			m_fPower(0.0f)
	, m_fParabolaTime(0.0f),	m_fTime(0.0f)
	, m_fRotationRoll(0.0f),	m_fAngle(0.0f)
	, m_fDistance(0.0f)
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AGuided_Missile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGuided_Missile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGuided_Missile::Set_Enemy(TArray<class AEnemy*> EnemyArray)
{
	m_EnemyArray = EnemyArray;
}

void AGuided_Missile::Set_Position(TArray<FVector> Position)
{
	m_VecPosition = Position;
}

void AGuided_Missile::Set_Distance(float fDistance)
{
	m_fDistance = fDistance;
}

// 유도 미사일이 Enemy Trace 시작
void AGuided_Missile::Trace_Enemy()
{
	for (int index = 0; index < m_EnemyArray.Num() * 2; ++index)
			Missile_Move(index);
}

// MMissile Trace Function
void AGuided_Missile::Missile_Move(int iIndex)
{
	
}

void AGuided_Missile::Second_Move()
{

}

void AGuided_Missile::Parabola(FVector* pOut, FVector StartPoistion, FVector EndPoisiton)
{
	FVector		vTrace(0.0f, 0.0f, 0.0f);

	vTrace = EndPoisiton - StartPoistion;

	vTrace = vTrace.GetSafeNormal();

	m_fAngle = FVector::DotProduct(StartPoistion.GetSafeNormal(), EndPoisiton.GetSafeNormal());
}