// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "Missile.h"

// Sets default values
AMissile::AMissile()
	: m_eDir(Direction_Type::DIR_Z)
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

void AMissile::Set_Dir(Direction_Type eType)
{
	m_eDir = eType;
}

Direction_Type AMissile::Get_Dir()
{
	return m_eDir;
}