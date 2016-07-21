// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <map>
#include <list>

#include "GameFramework/Actor.h"
#include "EnemyGroupManager.generated.h"

UCLASS()
class SPACE_REDEMPTION_API AEnemyGroupManager : public AActor
{
	GENERATED_BODY()
public:
	AEnemyGroupManager();
	~AEnemyGroupManager();
public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
public:
	UFUNCTION(BlueprintCallable, Category = "EnemyGroup")
		void SetGroupSapce(float fSpace);
public: // Initialize and Group Formation
	UFUNCTION(BlueprintCallable, Category = "EnemyGroup")
		void Inset_Enemey(FString strGroupName, class AActor* pActor);
	UFUNCTION(BlueprintCallable, Category = "EnemyGroup")
		void TriangleFormation(FString strGroupName);
public:	// Group Move
	UFUNCTION(BlueprintCallable, Category = "EnemyGroup")
		void Group_Forward(FString strGroupName, float fSpeed, float fDeltaSeconds);
	UFUNCTION(BlueprintCallable, Category = "EnemyGroup")
		void Group_TargetMove(FString strGroupName, FVector Position, float fSpeed, float fDeltaSeconds);
private:
	TArray<class AActor*>*	Get_Array(FString strGroupName);
	FRotator				Get_AngleToAxis(FVector PositionVector, FVector NormalVector);
private:
	void					ReverseFormation();
private:
	void											Release(void);
private:
	TMap<FString, TArray<class AActor*>>			m_MapGroup;
	typedef TMap<FString, TArray<class AActor*>>	MAPGROUP;
	typedef TArray<class AActor*>					ARRAYACTOR;
private:
	float											m_fSpace;
	float											m_fAngle;
};