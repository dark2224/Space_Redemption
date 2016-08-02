// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"

#include "Alliance.h"
#include "Enemy.h"

#include "AIManager.h"

// Sets default values
AAIManager::AAIManager()
	: m_fDistance(0.0f),		m_fGroupSpace(0.0f)
	, m_bShootCheck(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AAIManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAIManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

bool AAIManager::Get_Shoot()
{
	return m_bShootCheck;
}

TArray<class AAlliance*> AAIManager::Get_Alliance(void)
{
	return m_AlliacneArray;
}

TArray<class AEnemy*> AAIManager::Get_Enemy(void)
{
	return m_EnemyArray;
}

void AAIManager::Set_Alliance(TArray<class AAlliance*> pAllianceArray)
{
	m_AlliacneArray = pAllianceArray;
}

void AAIManager::Set_Enemy(TArray<class AEnemy*> pEnamyArray)
{
	m_EnemyArray = pEnamyArray;
}

void AAIManager::AI_Battle()
{
	/*if (m_EnemyArray.Num() <= 0)
		return;

	if (m_AlliacneArray.Num() <= 0)
		return;

	for (int index = 0; index < m_AlliacneArray.Num(); ++index)
	{
		if(m_EnemyArray.Num() < index)
			break;

		AI_Shoot(index);
	}*/
}

void AAIManager::AI_Shoot(EUnit_Type eUnitType, int index)
{

}

void AAIManager::Trace(EUnit_Type eUnitType, float fSpeed)
{
	if (m_EnemyArray.Num() <= 0)
		return;

	if (m_AlliacneArray.Num() <= 0)
		return;

	FVector				vZero(0.0f, 0.0f, 0.0f);
	FVector				vPosition(0.0f, 0.0f, 0.0f);
	FVector				vTracePosition(0.0f, 0.0f, 0.0f);

	float				fDistance(0.0f);

	/*if (EUnit_Type::UNIT_ALLIANCE == eUnitType)
	{
		for (int index = 0; index < m_AlliacneArray.Num(); ++index)
		{
			if(m_EnemyArray.Num() < index)
				break;

			fDistance = FMath::Abs(FVector::Dist(m_EnemyArray[index]->GetActorLocation(), m_AlliacneArray[index]->GetActorLocation()));

			if (fDistance >= m_fDistance)
				break;

			vPosition = m_AlliacneArray[index]->GetActorLocation();

			vTracePosition = m_EnemyArray[index]->GetActorLocation() - m_AlliacneArray[index]->GetActorLocation();
			vTracePosition.GetSafeNormal();
			vPosition += vTracePosition * GetWorld()->DeltaTimeSeconds * fSpeed;
			m_AlliacneArray[index]->SetActorLocation(vPosition);
		}
	}*/

	/*else */if (EUnit_Type::UNIT_ENEMEY == eUnitType)
	{
		for (int index = 0; index < m_EnemyArray.Num(); ++index)
		{
			if(m_AlliacneArray.Num() < index)
				break;

			fDistance =  FMath::Abs(FVector::Dist(m_EnemyArray[index]->GetActorLocation(), m_AlliacneArray[index]->GetActorLocation()));
			
			if (fDistance >= m_fDistance)
			{
				vPosition = m_EnemyArray[index]->GetActorLocation();

				vTracePosition = m_AlliacneArray[index]->GetActorLocation() - m_EnemyArray[index]->GetActorLocation();
				vTracePosition.GetSafeNormal();
				vPosition += vTracePosition * GetWorld()->DeltaTimeSeconds * fSpeed;
				vPosition.Z = m_AlliacneArray[index]->GetActorLocation().Z;
				m_EnemyArray[index]->SetActorLocation(vPosition);

				m_AlliacneArray[index]->Set_Shoot(false);
				m_EnemyArray[index]->Set_Shoot(false);
			}

			else if( fDistance < m_fDistance)
			{
				m_AlliacneArray[index]->Set_Shoot(true);
				m_EnemyArray[index]->Set_Shoot(true);
			}
		}
	}
}

void AAIManager::Triangle(EUnit_Type eUnit_Type)
{
	/*
	ARRAYACTOR::TIterator			iter_begin = TarrayActor[0];

	FVector		VecPosition = (*iter_begin)->GetActorLocation();
	FVector		VecSpacePosition(0, 0, 0);

	int								iIndex(0);
	int								iCount(0);
	int								iAddValue(1);
	float							fSpcaceCal(0.0f);

	++iter_begin;

	for (int index = 0; index != TarrayActor->Num(); ++index)
	{
		if (0 == iIndex)
	{
		++iIndex;
		continue;
	}

	fSpcaceCal = m_fSpace * iAddValue;

	if (iIndex & 1)
	{
		VecSpacePosition = FVector(VecPosition.X - fSpcaceCal, VecPosition.Y - fSpcaceCal, VecPosition.Z);
		++iCount;
	}

	else
	{
		VecSpacePosition = FVector(VecPosition.X - fSpcaceCal, VecPosition.Y + fSpcaceCal, VecPosition.Z);
		++iCount;
	}

	(*iter_begin)->SetActorLocation(VecSpacePosition);

	if (iCount >= 2)
	{
		++iAddValue;
		iCount = 0;
	}

	++iIndex;
	++iter_begin;*/
}