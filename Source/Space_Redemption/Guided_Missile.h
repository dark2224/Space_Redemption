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
public:
	UFUNCTION(BlueprintCallable, Category = "Guided_Missile")
	void Missile_Move(int iIndex);
	UFUNCTION(BlueprintCallable, Category = "Guided_Missile")
	void Trace_Enemy();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Guided_Missile")
	float							m_fGravity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Guided_Missile")
	float							m_fPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Guided_Missile")
	float							m_fParabolaTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Guided_Missile")
	float							m_fRotationRoll;
private:		// Get
	bool Check_Enemy(int iIndex);
private:
	FVector Parabola(int iIndex);
private:
	float							m_fTime;
	float							m_fAngle;
};