// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"

#include "AllianceManager.h"

// Sets default values
AAllianceManager::AAllianceManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AAllianceManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAllianceManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

TArray<class AAlliance*> AAllianceManager::Get_Alliance()
{
	return m_AllianceArray;
}

void AAllianceManager::Inset_Alliacne(TArray<class AAlliance*> AAlliance)
{
	m_AllianceArray = AAlliance;
}