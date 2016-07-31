// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "AIManager.h"

AIManager::AIManager()
{
}

AIManager::~AIManager()
{
}

TArray<class AAlliance*>* AIManager::Get_Alliance(void)
{
	return &m_AlliacneArray;
}

TArray<class AEnemy*>* AIManager::Get_Enemy(void)
{
	return &m_EnemyArray;
}

void AIManager::Set_Alliance(TArray<class AAlliance*>* pAllianceArray)
{
	m_AlliacneArray = *pAllianceArray;
}

void AIManager::Set_Enemy(TArray<class AEnemy*>* pEnamyArray)
{
	m_EnemyArray = *pEnamyArray;
}

void AIManager::ForwardMove_Array(Unit_Type eUnitType, float& DeltaTimeSeconds, float& fSpeed)
{
	FVector				vPosition(0.0f, 0.0f, 0.0f);

	if (Unit_Type::Unit_Alliance == eUnitType)
	{
		for (int index = 0; index < m_AlliacneArray.Num(); ++index)
		{
			vPosition.X = m_AlliacneArray[index]->GetActorLocation().X + fSpeed * DeltaTimeSeconds;
			m_AlliacneArray[index]->SetActorLocation(vPosition);
		}
	}

	else if (Unit_Type::Unit_Enemy == eUnitType)
	{
		for (int index = 0; index < m_EnemyArray.Num(); ++index)
		{
			vPosition.X = m_EnemyArray[index]->GetActorLocation().X + fSpeed * DeltaTimeSeconds;
			m_EnemyArray[index]->SetActorLocation(vPosition);
		}
	}
}

void AIManager::Trace_Array(Unit_Type eUnitType, FVector* pTracePosition, float& DeltaTimeSeconds, float& fSpeed, int& iIndex)
{
	FVector				vPosition(0.0f, 0.0f, 0.0f);
	FVector				vTracePosition(0.0f, 0.0f, 0.0f);

	if (Unit_Type::Unit_Alliance == eUnitType)
	{
		vTracePosition = *pTracePosition - m_AlliacneArray[iIndex]->GetActorLocation();
		vTracePosition.GetSafeNormal();
		vPosition += vTracePosition * DeltaTimeSeconds * fSpeed;
		m_AlliacneArray[iIndex]->SetActorLocation(vPosition);
	}

	else if (Unit_Type::Unit_Enemy == eUnitType)
	{
		vTracePosition = *pTracePosition - m_EnemyArray[iIndex]->GetActorLocation();
		vTracePosition.GetSafeNormal();
		vPosition += vTracePosition * DeltaTimeSeconds * fSpeed;
		m_EnemyArray[iIndex]->SetActorLocation(vPosition);
	}
}