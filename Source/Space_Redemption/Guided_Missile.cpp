// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"

#include "Guided_Missile.h"

AGuided_Missile::AGuided_Missile()
	: m_fGravity(0.0f),			m_fPower(0.0f)
	, m_fParabolaTime(0.0f),	m_fTime(0.0f)
	, m_fRotationRoll(0.0f),	m_fForwardTime(0.0f)
	, m_fOriForwardTime(0.0f),	m_fAngle(0.0f)
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

	int		iCount = 0;

	for (int index = 0; index < m_MissileArray.Num(); ++index)
	{
		m_MissileArray[index]->SetActorLocation(m_VecPosition[index]);

		if(index + 1 < m_MissileArray.Num())
			m_MissileArray[index + 1]->SetActorLocation(m_VecPosition[index]);
	}
}

void AGuided_Missile::Set_Distance(float fDistance)
{
	m_fDistance = fDistance;
}

void AGuided_Missile::Set_ParabolaTime(float fTime)
{
	m_fTime = fTime;
}

// 유도 미사일이 Enemy Trace 시작
void AGuided_Missile::Trace_Enemy()
{
	for (int index = 0; index < m_EnemyArray.Num(); ++index)
			Missile_Move(index);

	m_fForwardTime -= GetWorld()->DeltaTimeSeconds;

	if (m_fForwardTime <= 0)
		m_fForwardTime = m_fOriForwardTime;
}

// MMissile Trace Function
void AGuided_Missile::Missile_Move(int iIndex)
{
	if (m_fForwardTime > 0)
	{
		FVector		vPosition = m_MissileArray[iIndex]->GetActorLocation();
		vPosition.X += GetWorld()->DeltaTimeSeconds * m_fDistance;
		m_MissileArray[iIndex]->SetActorLocation(vPosition);
	}

	else
		Parabola(iIndex);
}

void AGuided_Missile::Parabola(int iIndex)
{
	m_fTime += GetWorld()->DeltaTimeSeconds;

	FVector			vTracePosition(0.0f, 0.0f, 0.0f);

	vTracePosition = m_EnemyArray[iIndex]->GetActorLocation() - m_MissileArray[iIndex]->GetActorLocation();
	vTracePosition = vTracePosition.GetSafeNormal();

	vTracePosition += vTracePosition * GetWorld()->DeltaTimeSeconds * m_MissileArray[iIndex]->Get_Speed();

	m_fAngle = FVector::DotProduct(m_EnemyArray[iIndex]->GetActorLocation().GetSafeNormal(), m_MissileArray[iIndex]->GetActorLocation().GetSafeNormal());

	m_fAngle = FMath::Acos(m_fAngle);

	vTracePosition.Z += -FMath::Sin(m_fAngle) * m_fPower + (m_fGravity * m_fTime * m_fTime) * 0.5f;
}