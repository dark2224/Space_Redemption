// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AIManager.generated.h"

UENUM(BlueprintType)
enum class EUnit_Type : uint8
{
	UNIT_ALLIANCE	UMETA(DisplayName = "Unit_Alliance"),
	UNIT_ENEMEY	UMETA(DisplayName = "Unit_Enemy"),
	UNIT_END	UMETA(DisplayName = "Unit_End")
};

UCLASS()
class SPACE_REDEMPTION_API AAIManager : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AAIManager();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
public:
	UFUNCTION(BlueprintCallable, Category = "AI")
	bool								Get_Shoot();
	UFUNCTION(BlueprintCallable, Category = "AI")
	TArray<class AAlliance*>			Get_Alliance();
	UFUNCTION(BlueprintCallable, Category = "AI")
	TArray<class AEnemy*>				Get_Enemy();
public:		// Set
	UFUNCTION(BlueprintCallable, Category = "AI")
	void	Set_Alliance(TArray<class AAlliance*> pAllianceArray);
	UFUNCTION(BlueprintCallable, Category = "AI")
	void	Set_Enemy(TArray<class AEnemy*> pEnamyArray);
public:		// Get
public:		// Battle
	UFUNCTION(BlueprintCallable, Category = "AI")
	void	AI_Battle();
	void	AI_Shoot(EUnit_Type eUnitType, int index);
public:		// AI
	UFUNCTION(BlueprintCallable, Category = "AI")
	void	Trace(EUnit_Type eUnitType, float fSpeed);
public:		// Formation
	void	Triangle(EUnit_Type eUnit_Type);
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float									m_fDistance;
private:
	TArray<class AAlliance*>				m_AlliacneArray;
	TArray<class AEnemy*>					m_EnemyArray;
	typedef TArray<class AAlliance*>		AALIANCEARRAY;
	typedef TArray<class AEnemy*>			ENEMYARRAY;
private:
	float									m_fGroupSpace;
	bool									m_bShootCheck;
};