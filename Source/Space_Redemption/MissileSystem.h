// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Enemy.h"
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
public:		// Set Function & Blueprint
	UFUNCTION(BlueprintCallable, Category = "Missile_System")
		void	Initialize_Missile(float fAceel, float fDelay);
	UFUNCTION(BlueprintCallable, Category = "Missile_System")
		void	Insert_Missile(TArray<class AActor*> MisslieArray);
protected:
	TArray<class AActor*>						m_MissileArray;
	typedef TArray<class AActor*>				MISSILEARRAY;
<<<<<<< HEAD
	TArray<class AEnemy*>						m_EnemyArray;
	typedef TArray<class AEnemy*>				ENEMYARRAY;
protected:
	float										m_fAceel;
	float										m_fDelay;
=======
protected:
	Direction_Type								m_eMissile_Type;
	float										m_fSpeed;
>>>>>>> origin/master
};