// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "Alliance.h"

// Sets default values
AAlliance::AAlliance()
	: m_fDelay(0.0f),						m_fBoosterTime(0.0f)
	, m_fOriBoosterTime(0.0f),				m_fShootDelay(0.0f)
	, m_fOriShootDelay(0.0f),				m_iHp(0)
	, m_iDamage(0),							m_eAlliance_Type(State_Type::STATE_END)
	, m_fTime(0.0f),						m_bShoot(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AAlliance::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAlliance::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

State_Type AAlliance::Get_Type()
{
	return m_eAlliance_Type;
}

bool AAlliance::Get_Delay()
{
	m_fTime += GetWorld()->DeltaTimeSeconds;

	if (m_fDelay <= m_fTime)
	{
		m_fTime = 0.0f;
		return true;
	}

	return false;
}

int AAlliance::Get_Hp()
{
	return m_iHp;
}

int AAlliance::Get_Dagame()
{
	return m_iDamage;
}

bool AAlliance::Get_Shoot()
{
	return m_bShoot;
}

void AAlliance::Set_Hp(int iHp)
{
	m_iHp = iHp;
}

void AAlliance::Set_Damage(int iDamage)
{
	m_iHp -= iDamage;
}

void AAlliance::Set_AllianceType(State_Type eAllianceType)
{
	m_eAlliance_Type = eAllianceType;
}

void AAlliance::Set_Shoot(bool bShoot)
{
	m_bShoot = bShoot;
}

bool AAlliance::Booster_Delay()
{
	m_fBoosterTime -= GetWorld()->DeltaTimeSeconds;

	if (m_fBoosterTime <= 0)
	{
		m_fBoosterTime = m_fOriBoosterTime;

		return true;
	}

	return false;
}

bool AAlliance::Shoot_Delay()
{
	m_fShootDelay -= GetWorld()->DeltaTimeSeconds;

	if (m_fShootDelay <= 0)
	{
		m_fShootDelay = m_fOriShootDelay;
		
		return true;
	}

	return false;
}