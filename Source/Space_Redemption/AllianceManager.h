// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include "Alliance.h"

#include "AllianceManager.generated.h"

UENUM(BlueprintType)
enum class EAlliance_Formation : uint8
{
	FORMATION_TRIANGLE	UMETA(DisplayName = "Formation_Triangle"),
	FORMATION_RECT	UMETA(DisplayName = "Formation_Rect"),
	FORMATION_END	UMETA(DisplayName = "Formation_End")
};

UCLASS()
class SPACE_REDEMPTION_API AAllianceManager : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AAllianceManager();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
public:
	UFUNCTION(BlueprintCallable, Category = "EnemyGroup")
		TArray<class AAlliance*> Get_Alliance();
public:
	UFUNCTION(BlueprintCallable, Category = "EnemyGroup")
		void Set_GroupSapce(float fSpace);
	UFUNCTION(BlueprintCallable, Category = "EnemyGroup")
		void Set_Fomation(FString strGroupName, EAlliance_Formation eFormatio);
public: // Initialize and Group Formation
	UFUNCTION(BlueprintCallable, Category = "EnemyGroup")
		void Inset_Alliacne(FString strGroupName, class AAlliance* pActor);
private:
	TArray<class AAlliance*>*							Get_Array(FString strGroupName);
private: // Group
	void												TriangleFormation(FString strGroupName);
private:
	TMap<FString, TArray<class AAlliance*>>				m_MapAlliance;
	typedef TMap<FString, TArray<class AAlliance*>>		MAPALLIANCE;
	typedef TArray<class AAlliance*>					ALLIANCEARRAY;
private:
	TArray<FString>										m_GroupNameArray;
	typedef TArray<FString>								ARRAYGROUPNAME;
private:
	EAlliance_Formation									m_eFormation;
private:
	float												m_fSpace;
};