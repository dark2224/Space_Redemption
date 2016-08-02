// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include "Enemy.h"

#include "EnemyGroupManager.generated.h"

UCLASS()
class SPACE_REDEMPTION_API AEnemyGroupManager : public AActor
{
	GENERATED_BODY()	
public:
	AEnemyGroupManager();
public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
public:
	UFUNCTION(BlueprintCallable, Category = "EnemyGroup")
		TArray<class AEnemy*> Get_Enemy();
public: // Inset
	UFUNCTION(BlueprintCallable, Category = "EnemyGroup")
		void Inset_Enemey(TArray<class AEnemy*> EnemyArray);
private:
	TArray<class AEnemy*>							m_EnemyArray;
	typedef TArray<class AEnemy*>					ARRAYACTOR;
};