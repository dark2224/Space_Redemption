// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Missile.generated.h"

UCLASS()
class SPACE_REDEMPTION_API AMissile : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AMissile();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
public:
	UFUNCTION(BlueprintCallable, Category = "Missile")
	FVector					Get_Position();
	UFUNCTION(BlueprintCallable, Category = "Missile")
	bool					Get_StartCheck();
	UFUNCTION(BlueprintCallable, Category = "Missile")
	bool					BoosterDelay();
public:
	UFUNCTION(BlueprintCallable, Category = "Missile")
	void					Set_Postion(FVector vPosition);
	UFUNCTION(BlueprintCallable, Category = "Missile")
	void					Set_MaxTime(float fMaxTime);
	UFUNCTION(BlueprintCallable, Category = "Missile")
	void					Set_StartCheck(bool bStartCheck);
public:
	UFUNCTION(BlueprintCallable, Category = "Missile")
	void					Initialize_Missile(float fSpeed, float fMaxTime, float fDelay);
	UFUNCTION(BlueprintCallable, Category = "Missile")
	void					Reset_Missile();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Missile")
	float					m_fOriBooster;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Missile")
	float					m_fBooster;
public:			// Get
	float					Get_Speed();
	float					Get_MaxTime();
	float					Get_Delay();
public:			// Set
	void					Set_Delay(float fDelay);
private:
	FVector					m_vOriPosition;
private:
	float					m_fMissileSpeed;
	float					m_fMaxTime;
	float					m_fOriDelay;
	float					m_fDelay;
	bool					m_bStartCheck;
};