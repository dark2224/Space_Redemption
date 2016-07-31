// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AllianceManager.h"
#include "EnemyGroupManager.h"

/**
 * 
 */
class SPACE_REDEMPTION_API AIManager
{
public:
	enum Unit_Type { Unit_Alliance, Unit_Enemy, Unit_End};
public:
	AIManager();
	~AIManager();
public:		// Get
	TArray<class AAlliance*>*			Get_Alliance(void);
	TArray<class AEnemy*>*				Get_Enemy(void);
public:		// Set
	void Set_Alliance(TArray<class AAlliance*>* pAllianceArray);
	void Set_Enemy(TArray<class AEnemy*>* pEnamyArray);
public:		// AI
	void	ForwardMove_Array(Unit_Type eUnitType, float& DeltaTimeSeconds, float& fSpeed);
	void	Trace_Array(Unit_Type eUnitType, FVector* pTracePosition, float& DeltaTimeSeconds, float& fSpeed, int& iIndex);
private:
	TArray<class AAlliance*>				m_AlliacneArray;
	TArray<class AEnemy*>					m_EnemyArray;
	typedef TArray<class AAlliance*>		AALIANCEARRAY;
	typedef TArray<class AEnemy*>			ENEMYARRAY;
};