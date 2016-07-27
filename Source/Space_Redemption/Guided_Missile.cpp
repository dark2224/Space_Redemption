// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"

#include "Guided_Missile.h"

AGuided_Missile::AGuided_Missile()
	: m_fTime(0.0f),		m_fMaxTime(0.0f)
	, m_fGravity(0.0f),		m_fPower(0.0f)
{
	PrimaryActorTick.bCanEverTick = true;
}

AGuided_Missile::~AGuided_Missile()
{
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

void AGuided_Missile::Set_MaxTime(float fMaxTime)
{
	m_fMaxTime = fMaxTime;
}

void AGuided_Missile::Trace_Enemy()
{
	if (m_MissileArray.Num() <= 0)
		return;

	for (int index = 0; index < m_MissileArray.Max(); ++index)
	{
		if (Check_Enemy(index))
			Missile_Move(index);
	}
}

bool AGuided_Missile::Check_Enemy(int iIndex)
{
	if (Enemy_Type::ENEMY_END != m_EnemyArray[iIndex]->Get_Type())
		return true;

	return false;
}

void AGuided_Missile::Missile_Move(int iIndex)
{
	m_fTime += GetWorld()->DeltaTimeSeconds;

	if (m_fTime > m_fMaxTime)
		m_fTime = 0;

	FVector			vMissilePosition = m_MissileArray[iIndex]->GetActorLocation();
	FVector			vTrace(0.0f, 0.0f, 0.0f);

	vTrace = vMissilePosition - m_EnemyArray[iIndex]->GetActorLocation();
	vTrace = vTrace.GetSafeNormal();

	vMissilePosition = Parabola(iIndex);

	vMissilePosition += vTrace * GetWorld()->DeltaTimeSeconds;
}

FVector AGuided_Missile::Parabola(int iIndex)
{
	FVector			vMissilePosition = m_MissileArray[iIndex]->GetActorLocation();

	switch (static_cast<AMissile*>(m_MissileArray[iIndex])->Get_Dir())
	{
	case Direction_Type::DIR_Z:
		vMissilePosition.Z += FMath::Sin(90 * 3.14f / 180) * m_fPower + (m_fGravity * m_fTime * m_fTime) * 0.5f;
		break;
	case Direction_Type::DIR_YZ:
		vMissilePosition.Y += FMath::Cos(90 * 3.14f / 180) * m_fPower + (m_fGravity * m_fTime * m_fTime) * 0.5f;
		vMissilePosition.Z += FMath::Sin(90 * 3.14f / 180) * m_fPower + (m_fGravity * m_fTime * m_fTime) * 0.5f;
		break;
	case Direction_Type::DIR_Y:
		vMissilePosition.Y += FMath::Cos(90 * 3.14f / 180) * m_fPower + (m_fGravity * m_fTime * m_fTime) * 0.5f;
		break;
	case Direction_Type::DIR_YNZ:
		vMissilePosition.Y += FMath::Cos(90 * 3.14f / 180) * m_fPower + (m_fGravity * m_fTime * m_fTime) * 0.5f;
		vMissilePosition.Z -= FMath::Sin(90 * 3.14f / 180) * m_fPower + (m_fGravity * m_fTime * m_fTime) * 0.5f;
		break;
	case Direction_Type::DIR_NZ:
		vMissilePosition.Z -= FMath::Sin(90 * 3.14f / 180) * m_fPower + (m_fGravity * m_fTime * m_fTime) * 0.5f;
		break;
	case Direction_Type::DIR_NYNZ:
		vMissilePosition.Y -= FMath::Cos(90 * 3.14f / 180) * m_fPower + (m_fGravity * m_fTime * m_fTime) * 0.5f;
		vMissilePosition.Z -= FMath::Sin(90 * 3.14f / 180) * m_fPower + (m_fGravity * m_fTime * m_fTime) * 0.5f;
		break;
	case Direction_Type::DIR_NY:
		vMissilePosition.Y -= FMath::Cos(90 * 3.14f / 180) * m_fPower + (m_fGravity * m_fTime * m_fTime) * 0.5f;
		break;
	case Direction_Type::DIR_NYZ:
		vMissilePosition.Y -= FMath::Cos(90 * 3.14f / 180) * m_fPower + (m_fGravity * m_fTime * m_fTime) * 0.5f;
		vMissilePosition.Z += FMath::Sin(90 * 3.14f / 180) * m_fPower + (m_fGravity * m_fTime * m_fTime) * 0.5f;
		break;
	default:
		break;
	}

	return vMissilePosition;
}