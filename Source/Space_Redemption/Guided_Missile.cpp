// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"

#include "Guided_Missile.h"

AGuided_Missile::AGuided_Missile()
	: m_fGravity(0.0f),			m_fPower(0.0f)
	, m_fParabolaTime(0.0f),	m_fTime(0.0f)
	, m_fRotationRoll(0.0f),	m_fAngle(0.0f)
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
// 유도 미사일이 Enemy Trace 시작
void AGuided_Missile::Trace_Enemy()
{
	if (m_MissileArray.Num() <= 0)
		return;

	for (int index = 0; index < m_MissileArray.Num(); ++index)
	{
		if (Check_Enemy(index))
			Missile_Move(index);
	}
}
// Enemy Array을 갖고 있나 없나 판다
bool AGuided_Missile::Check_Enemy(int iIndex)
{
	if (NULL == m_EnemyArray[iIndex])
		return false;

	if (Enemy_Type::ENEMY_END != m_EnemyArray[iIndex]->Get_Type())
		return true;

	return false;
}
// MMissile Trace Function
void AGuided_Missile::Missile_Move(int iIndex)
{
	m_fTime += GetWorld()->DeltaTimeSeconds;

	m_fParabolaTime += GetWorld()->DeltaTimeSeconds;

	static_cast<class AMissile*>(m_MissileArray[iIndex])->Set_Delay(m_fTime);

	if (static_cast<class AMissile*>(m_MissileArray[iIndex])->Get_Delay() < 0)
	{
		static_cast<class AMissile*>(m_MissileArray[iIndex])->Set_StartCheck(true);

		FRotator			vRotator = m_MissileArray[iIndex]->GetActorRotation();

		FVector				vMissilePosition = m_MissileArray[iIndex]->GetActorLocation();

		FVector				vTrace(0.0f, 0.0f, 0.0f);

		FVector				vCrossProduct(0.0f, 0.0f, 0.0f);

		vCrossProduct = FVector::CrossProduct(vMissilePosition, m_EnemyArray[iIndex]->GetActorLocation());

		vTrace = m_EnemyArray[iIndex]->GetActorLocation() - vMissilePosition;

		vTrace = vTrace.GetSafeNormal();

		m_fAngle = FVector::DotProduct(vMissilePosition, m_EnemyArray[iIndex]->GetActorLocation());

		//m_fAngle = FMath::DegreesToRadians(FMath::Acos(m_fAngle));

		//vMissilePosition = Parabola(iIndex);

		vMissilePosition += vTrace * GetWorld()->DeltaTimeSeconds * static_cast<class AMissile*>(m_MissileArray[iIndex])->Get_Speed();
		
		vRotator.Roll += GetWorld()->DeltaTimeSeconds * m_fRotationRoll;
		vRotator.Yaw += GetWorld()->DeltaTimeSeconds * FMath::Cos(m_fAngle);

		m_MissileArray[iIndex]->SetActorRotation(vRotator);
		m_MissileArray[iIndex]->SetActorLocation(vMissilePosition);
	}
}
// 포물선
FVector AGuided_Missile::Parabola(int iIndex)
{
	FVector			vMissilePosition = m_MissileArray[iIndex]->GetActorLocation();

	m_fParabolaTime += GetWorld()->DeltaTimeSeconds;

	switch (static_cast<AMissile*>(m_MissileArray[iIndex])->Get_Dir())
	{
	case Direction_Type::DIR_Z:
		vMissilePosition.Z += FMath::Sin(m_fAngle) * m_fPower + (m_fGravity * m_fParabolaTime * m_fParabolaTime) * 0.5f;
		break;
	case Direction_Type::DIR_YZ:
		vMissilePosition.Y += FMath::Cos(m_fAngle) * m_fPower + (m_fGravity * m_fParabolaTime * m_fParabolaTime) * 0.5f;
		vMissilePosition.Z += FMath::Sin(m_fAngle) * m_fPower + (m_fGravity * m_fParabolaTime * m_fParabolaTime) * 0.5f;
		break;
	case Direction_Type::DIR_Y:
		vMissilePosition.Y += FMath::Cos(m_fAngle) * m_fPower + (m_fGravity * m_fParabolaTime * m_fParabolaTime) * 0.5f;
		break;
	case Direction_Type::DIR_YNZ:
		vMissilePosition.Y += FMath::Cos(m_fAngle) * m_fPower + (m_fGravity * m_fParabolaTime * m_fParabolaTime) * 0.5f;
		vMissilePosition.Z -= FMath::Sin(m_fAngle) * m_fPower + (m_fGravity * m_fParabolaTime * m_fParabolaTime) * 0.5f;
		break;
	case Direction_Type::DIR_NZ:
		vMissilePosition.Z -= FMath::Sin(m_fAngle) * m_fPower + (m_fGravity * m_fParabolaTime * m_fParabolaTime) * 0.5f;
		break;
	case Direction_Type::DIR_NYNZ:
		vMissilePosition.Y -= FMath::Cos(m_fAngle) * m_fPower + (m_fGravity * m_fParabolaTime * m_fParabolaTime) * 0.5f;
		vMissilePosition.Z -= FMath::Sin(m_fAngle) * m_fPower + (m_fGravity * m_fParabolaTime * m_fParabolaTime) * 0.5f;
		break;
	case Direction_Type::DIR_NY:
		vMissilePosition.Y -= FMath::Cos(m_fAngle) * m_fPower + (m_fGravity * m_fParabolaTime * m_fParabolaTime) * 0.5f;
		break;
	case Direction_Type::DIR_NYZ:
		vMissilePosition.Y -= FMath::Cos(m_fAngle) * m_fPower + (m_fGravity * m_fParabolaTime * m_fParabolaTime) * 0.5f;
		vMissilePosition.Z += FMath::Sin(m_fAngle) * m_fPower + (m_fGravity * m_fParabolaTime * m_fParabolaTime) * 0.5f;
		break;
	default:
		break;
	}

	return vMissilePosition;
}