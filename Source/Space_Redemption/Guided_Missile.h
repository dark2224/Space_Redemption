// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MissileSystem.h"

#include "Missile.h"

#include "Guided_Missile.generated.h"

UCLASS()
class SPACE_REDEMPTION_API AGuided_Missile : public AMissileSystem
{
	GENERATED_BODY()
public:
	AGuided_Missile();
	~AGuided_Missile();
public:
	// Called when the game starts or when spawned
	virtual void BeginPlay();
	// Called every frame
	virtual void Tick(float DeltaSeconds);
public:
	UFUNCTION(BlueprintCallable, Category = "Guided_Missile")
	void Set_Enemy(TArray<class AEnemy*> EnemyArray);
	UFUNCTION(BlueprintCallable, Category = "Guided_Missile")
	void Set_MaxTime(float fMaxTime);
public:
	UFUNCTION(BlueprintCallable, Category = "Guided_Missile")
	void Missile_Move(int iIndex);
	UFUNCTION(BlueprintCallable, Category = "Guided_Missile")
	void Trace_Enemy();
private:		// Get
	bool Check_Enemy(int iIndex);
private:
	FVector Parabola(int iIndex);
private:
	float							m_fTime;
	float							m_fMaxTime;
	float							m_fGravity;
	float							m_fPower;
};