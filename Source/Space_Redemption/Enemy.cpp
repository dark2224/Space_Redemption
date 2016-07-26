// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
	: m_eEnemy_Type(Enemy_Type::ENEMY_END),		m_iHp(0)
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

Enemy_Type AEnemy::Get_Type()
{
	return m_eEnemy_Type;
}

int AEnemy::Get_Hp()
{
	return m_iHp;
}

void AEnemy::Set_Hp(int iHp)
{
	m_iHp = iHp;
}

void AEnemy::Set_Damage(int iDamage)
{
	m_iHp -= iDamage;
}

void AEnemy::Set_EnemyType(Enemy_Type eEnemyType)
{
	m_eEnemy_Type = eEnemyType;
}