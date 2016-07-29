// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "Missile.h"

// Sets default values
AMissile::AMissile()
	: m_eDir(Direction_Type::DIR_Z),	m_fMissileSpeed(0.0f)
	, m_fMaxTime(0.0f),					m_vOriPosition(0.0f, 0.0f, 0.0f)
	, m_bStartCheck(false),				m_fOriDelay(0.0f)
	, m_fDelay(0.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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

void AMissile::Set_Postion(FVector vPosition)
{
	m_vOriPosition = vPosition;

	SetActorLocation(vPosition);
}

void AMissile::Set_Dir(Direction_Type eType)
{
	m_eDir = eType;
}

void AMissile::Set_MaxTime(float fMaxTime)
{
	m_fMaxTime = fMaxTime;
}

void AMissile::Set_StartCheck(bool bStartCheck)
{
	m_bStartCheck = bStartCheck;
}

void AMissile::Initialize_Missile(FVector vPosition, Direction_Type eDirType, float fSpeed, float fMaxTime, float fDelay)
{
	m_vOriPosition = vPosition;
	m_eDir = eDirType;
	m_fMissileSpeed = fSpeed;
	m_fMaxTime = fMaxTime;
	m_fOriDelay = fDelay;
	m_fDelay = fDelay;

	SetActorLocation(vPosition);
}

Direction_Type AMissile::Get_Dir()
{
	return m_eDir;
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
}