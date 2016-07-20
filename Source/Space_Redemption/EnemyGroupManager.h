// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <map>
#include <list>

#include "Macro.h"

#include "GameFramework/Actor.h"
#include "EnemyGroupManager.generated.h"

UCLASS()
class SPACE_REDEMPTION_API AEnemyGroupManager : public AActor
{
	GENERATED_BODY()
	DECLARE_SINGLETON(AEnemyGroupManager)
private:
	AEnemyGroupManager();
public:
	~AEnemyGroupManager();
public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
public:
	UFUNCTION(BlueprintCallable, Category = "Test")
	void Test(class UObject* pObject);
public:
	void Inset_Enemey(const TCHAR* pGroupName, class UObject* pUobject);
private:
	std::list<class UObject*>* Get_List(const TCHAR* pGroupName);
private:
	std::map<const TCHAR*, std::list<class UObject*>>			m_MapGroup;
	typedef std::map<const TCHAR*, std::list<class UObject*>>	MAPGROUP;
};