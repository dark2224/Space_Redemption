// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <map>
#include <list>

#include "GameFramework/Actor.h"
#include "EnemyGroupManager.generated.h"

UENUM(BlueprintType)
enum class EFormation_Type : uint8
{
	FORMATION_TRIANGLE	UMETA(DisplayName = "Formation_Triangle"),
	FORMATION_RECT	UMETA(DisplayName = "Formation_Rect"),
	FORMATION_END	UMETA(DisplayName = "Formation_End")
};

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
	UFUNCTION(BlueprintCallable, Category = "EnemyGroup")
		void SetFomation(FString strGroupName, EFormation_Type eFormatio);
public: // Initialize and Group Formation
	UFUNCTION(BlueprintCallable, Category = "EnemyGroup")
		void Inset_Enemey(FString strGroupName, class AActor* pActor);
public:	// Group Move
	UFUNCTION(BlueprintCallable, Category = "EnemyGroup")
		void Group_TargetMove(FString strGroupName, FVector Position, float fSpeed, float fDeltaSeconds);
private:
	TArray<class AActor*>*							Get_Array(FString strGroupName);
	FRotator										Get_AngleToAxis(FVector PositionVector, FVector NormalVector);
private: // Group
	void											TriangleFormation(FString strGroupName);
private:
	void											Release(void);
private:
	TMap<FString, TArray<class AActor*>>			m_MapGroup;
	typedef TMap<FString, TArray<class AActor*>>	MAPGROUP;
	typedef TArray<class AActor*>					ARRAYACTOR;
private:
	EFormation_Type									m_eFormation;
private:
	float											m_fSpace;
	float											m_fAngle;
};