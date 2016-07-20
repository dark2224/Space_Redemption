// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "GroupControlManager.h"

#include <algorithm>

// Sets default values
AGroupControlManager::AGroupControlManager()
	: m_GroupName(NULL)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGroupControlManager::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AGroupControlManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AGroupControlManager::SetGroup_Actor(class AActor* pActor)
{
}

std::list<class AActor*>* AGroupControlManager::Get_ActorList(const TCHAR* pGroupName)
{
	return NULL;
}