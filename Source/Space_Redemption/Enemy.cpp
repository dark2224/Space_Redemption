// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
	: m_fDelay(0.0f),			m_fBoosterTime(0.0f)
	, m_fOriBoosterTime(0.0f),	m_fShootDelay(0.0f)
	, m_fOriShootDelay(0.0f),	m_fRespawn(0.0f)
	, m_fOriRespawn(0.0f),		m_iHp(0)
	, m_iDamage(0),				m_eEnemy_Type(State_Type::STATE_END)
	, m_fTime(0.0f),			m_bShoot(false)
	, m_iOriHp(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

State_Type AEnemy::Get_Type()
{
	return m_eEnemy_Type;
}

bool AEnemy::Get_Delay()
{
	m_fTime += GetWorld()->DeltaTimeSeconds;

	if (m_fDelay <= m_fTime)
	{
		m_fTime = 0.0f;
		return true;
	}

	return false;
}

int AEnemy::Get_Hp()
{
	return m_iHp;
}

int AEnemy::Get_Dagame()
{
	return m_iDamage;
}

bool AEnemy::Get_Shoot()
{
	return m_bShoot;
}

void AEnemy::Set_Hp(int iHp)
{
	m_iHp = iHp;
	m_iOriHp = iHp;
}

void AEnemy::Set_Damage(int iDamage)
{
	m_iHp -= iDamage;
}

void AEnemy::Set_EnemyType(State_Type eEnemyType)
{
	m_eEnemy_Type = eEnemyType;
}

void AEnemy::Set_Shoot(bool bShoot)
{
	m_bShoot = bShoot;
}

void AEnemy::Set_Respawn(float fRespawn)
{
	m_fRespawn = fRespawn;
	m_fOriRespawn = fRespawn;
}

bool AEnemy::Booster_Delay()
{
	m_fBoosterTime -= GetWorld()->DeltaTimeSeconds;

	if (m_fBoosterTime <= 0)
	{
		m_fBoosterTime = m_fOriBoosterTime;

		return true;
	}

	return false;
}

bool AEnemy::Shoot_Delay()
{
	m_fShootDelay -= GetWorld()->DeltaTimeSeconds;

	if (m_fShootDelay <= 0)
	{
		m_fShootDelay = m_fOriShootDelay;

		return true;
	}

	return false;
}

bool AEnemy::Respawn(float fDistance)
{
	FVector		vPosition = GetActorLocation();

	m_fRespawn -= GetWorld()->DeltaTimeSeconds;
	vPosition.X += fDistance * GetWorld()->DeltaTimeSeconds;
	SetActorLocation(vPosition);

	if (m_fRespawn <= 0)
	{
		m_iHp = m_iOriHp;
		m_fRespawn = m_fOriRespawn;

		return true;
	}

	return false;
}