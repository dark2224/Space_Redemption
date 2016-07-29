// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "MissileSystem.h"

// Sets default values
AMissileSystem::AMissileSystem()
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

void AMissileSystem::Insert_Missile(class AActor* pMissile)
{
	m_MissileArray.Add(pMissile);
}

bool AMissileSystem::Get_EnemyArray()
{
	if (m_EnemyArray.Num() > 0)
		return true;

	return false;
}

TArray<class AActor*> AMissileSystem::Get_MissileArray()
{
	return m_MissileArray;
}