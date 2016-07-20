// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <tchar.h>
#include <map>
#include <list>
#include "GameFramework/Actor.h"
#include "GroupControlManager.generated.h"

UCLASS()
class SPACE_REDEMPTION_API AGroupControlManager : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AGroupControlManager();
public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
public:
	UFUNCTION(BlueprintCallable, Category = "Group")
	void SetGroup_Actor(class AActor* pActor);
private:
	std::list<class AActor*>* Get_ActorList(const TCHAR* pGroupName);
private:
	std::map<const TCHAR*, std::list<class AActor*>>			m_MapGroup;
	typedef std::map<const TCHAR*, std::list<class AActor*>>	MAPGROUP;
private:
	TCHAR*														m_GroupName;
};