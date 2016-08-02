// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"

#include "EnemyGroupManager.h"

AEnemyGroupManager::AEnemyGroupManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AEnemyGroupManager::BeginPlay()
{
	Super::BeginPlay();
}
// Called every frame
void AEnemyGroupManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TArray<class AEnemy*> AEnemyGroupManager::Get_Enemy()
{
	return m_EnemyArray;
}

void AEnemyGroupManager::Inset_Enemey(TArray<class AEnemy*>	EnemyArray)
{
	m_EnemyArray = EnemyArray;
}