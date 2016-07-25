// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MissileSystem.generated.h"

UENUM(BlueprintType)
enum class Direction_Type : uint8
{
	DIRECTION_Z		UMETA(DisplayName = "Direction_Z"),
	DIRECTION_ZY	UMETA(DisplayName = "Direction_ZY"),
	DIRECTION_Y		UMETA(DisplayName = "Direction_Y"),
	DIRECTION_NYZ	UMETA(DisplayName = "Direction_NYZ"),
	DIRECTION_NZ	UMETA(DisplayName = "Direction_NZ"),
	DIRECTION_NYNZ	UMETA(DisplayName = "Direction_NYNZ"),
	DIRECTION_NY	UMETA(DisplayName = "Direction_NY"),
	DIRECTION_YNZ	UMETA(DisplayName = "Direction_NYZ"),
	DIRECTION_END	UMETA(DisplayName = "Direction_End"),
};

UCLASS()
class SPACE_REDEMPTION_API AMissileSystem : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AMissileSystem();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
protected:
	TArray<class AActor*>						m_MissileArray;
	typedef TArray<class AActor*>				MISSILEARRAY;
protected:
	Direction_Type								m_eMissile_Type;
	float										m_fSpeed;
};