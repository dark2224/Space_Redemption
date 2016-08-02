// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "Missile.h"

// Sets default values
AMissile::AMissile()
	: m_vOriPosition(0.0f, 0.0f, 0.0f),		m_bStartCheck(false)
	, m_fMissileSpeed(0.0f),				m_fMaxTime(0.0f)
	, m_fOriDelay(0.0f),					m_fDelay(0.0f)
	, m_fBooster(0.0f),						m_fOriBooster(0.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AMissile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMissile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

FVector AMissile::Get_Position()
{
	return m_vOriPosition;
}

bool AMissile::Get_StartCheck()
{
	return m_bStartCheck;
}

bool AMissile::BoosterDelay()
{
	if (false == m_bStartCheck)
		return false;

	m_fBooster -= GetWorld()->DeltaTimeSeconds;

	if (m_fBooster <= 0)
	{
		m_fBooster = m_fOriBooster;

		return true;
	}

	return false;
}

void AMissile::Set_Postion(FVector vPosition)
{
	m_vOriPosition = vPosition;

	SetActorLocation(vPosition);
}

void AMissile::Set_MaxTime(float fMaxTime)
{
	m_fMaxTime = fMaxTime;
}

void AMissile::Set_StartCheck(bool bStartCheck)
{
	m_bStartCheck = bStartCheck;
}

void AMissile::Initialize_Missile( float fSpeed, float fMaxTime, float fDelay)
{
	m_fMissileSpeed = fSpeed;
	m_fMaxTime = fMaxTime;
	m_fOriDelay = fDelay;
	m_fDelay = fDelay;
}

float AMissile::Get_Speed()
{
	return m_fMissileSpeed;
}

float AMissile::Get_MaxTime()
{
	return m_fMaxTime;
}

float AMissile::Get_Delay()
{
	return m_fDelay;
}

void AMissile::Set_Delay(float fDelay)
{
	m_fDelay -= fDelay;
}

void AMissile::Reset_Missile()
{
	SetActorLocation(m_vOriPosition);
	m_fDelay = m_fOriDelay;
	m_bStartCheck = false;
	m_fBooster = m_fOriBooster;
}