// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SecondMissile.generated.h"

UCLASS()
class SPACE_REDEMPTION_API ASecondMissile : public AActor
{
	GENERATED_BODY()
private:
	class AEnemy* target;
	float droppingAcceleration;
	float RealVelocity;
	float FirstLeftTime;
	float LeftTime;
	float FirstUpSpeed;
	FVector _FirstDisplacement;
	FVector _LocationBefore;
	
public:	
	// Sets default values for this actor's properties
	ASecondMissile();
	// 반드시 생성직후 호출해줘야함.
	UFUNCTION(BlueprintCallable,Category = "Init")
	void GoGetEm(class AEnemy* target,float RealVelocity = 1000,float DroppingAccel = -1000);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

};
