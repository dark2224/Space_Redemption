// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "EnemyGroupManager.h"

#include "Functor.h"

#include <algorithm>

IMPLEMENT_SINGLETON(AEnemyGroupManager)

AEnemyGroupManager::AEnemyGroupManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

AEnemyGroupManager::~AEnemyGroupManager()
{
}

// Called when the game starts or when spawned
void AEnemyGroupManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemyGroupManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyGroupManager::Test(class UObject* pObject)
{

}

void AEnemyGroupManager::Inset_Enemey(const TCHAR* pGroupName, class UObject* pUobject)
{
	std::list<class UObject*>*		ListActor = Get_List(pGroupName);

	if (NULL == ListActor->empty())
	{
		std::list<class UObject*>			listActor;

		listActor.push_back(pUobject);

		m_MapGroup.insert(MAPGROUP::value_type(pGroupName, listActor));
	}

	else
		ListActor->push_back(pUobject);
}

std::list<class UObject*>* AEnemyGroupManager::Get_List(const TCHAR* pGroupName)
{
	MAPGROUP::iterator		iter = find_if(m_MapGroup.begin(), m_MapGroup.end(), CTag_Finder(pGroupName));

	if (NULL == iter->second.empty())
		return NULL;

	else
		return &iter->second;
}