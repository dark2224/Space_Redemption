// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "MissileSystem.h"

// Sets default values
AMissileSystem::AMissileSystem()
	: m_fAceel(0.f), m_fDelay(0.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMissileSystem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMissileSystem::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AMissileSystem::Initialize_Missile(float fAceel, float fDelay)
{
	m_fAceel = fAceel;
	fDelay = m_fDelay;
}

void AMissileSystem::Insert_Missile(class AActor* pMissile)
{
	m_MissileArray.Emplace(pMissile);
}