// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "EventDoor.h"

// Sets default values
AEventDoor::AEventDoor()
	: m_fDistance(0.0f),	m_fSpeed(0.0f)
	, m_fTime(0.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AEventDoor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEventDoor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

bool AEventDoor::Distance(FVector vStartPosition, FVector vEndPosition)
{
	float		fDistance(0.0f);

	fDistance = FMath::Abs(vEndPosition.X - vStartPosition.X);

	if (m_fDistance >= fDistance)
		return true;

	return false;
}

void AEventDoor::Set_Position(FVector vPosition)
{
	m_VecOriPoistion = vPosition;
}

void AEventDoor::OnOff_Door(Door_Type eType, FVector vPosition, float fUPValue)
{
	switch (eType)
	{
	case Door_Type::DOOR_On:
		vPosition.Z += fUPValue;
		break;

	case Door_Type::DOOR_Off:
		vPosition.Z -= fUPValue;

		if (m_VecOriPoistion.Z > vPosition.Z)
			vPosition = m_VecOriPoistion;
		break;
	case Door_Type::DOOR_END:
		break;
	default:
		break;
	}

	SetActorLocation(vPosition);
}

bool AEventDoor::Delay()
{
	m_fTime -= GetWorld()->DeltaTimeSeconds * 100.0f;

	if (m_fTime <= 0)
		return true;

	return false;
}