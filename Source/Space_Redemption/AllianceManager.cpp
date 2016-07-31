// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "AllianceManager.h"

// Sets default values
AAllianceManager::AAllianceManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AAllianceManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAllianceManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

TArray<class AAlliance*> AAllianceManager::Get_Alliance()
{
	TArray<class AAlliance*>*			pAarrayActor = NULL;

	int								iCount = 0;

	for (int index = 0; index < m_MapAlliance.Num(); ++index)
	{
		ALLIANCEARRAY::TIterator		iter_begin = m_MapAlliance[m_GroupNameArray[index]];

		for (int iArray = 0; iArray < m_MapAlliance[m_GroupNameArray[index]].Num(); ++iArray)
		{
			if (Alliance_Type::ALLIANCE_Alive == (*iter_begin)->Get_Type())
				++iCount;

			if (iCount >= m_MapAlliance[m_GroupNameArray[index]].Num())
			{
				pAarrayActor = &m_MapAlliance[m_GroupNameArray[index]];
				iCount = 0;
				break;
			}
		}
	}

	return *pAarrayActor;
}

void AAllianceManager::Set_GroupSapce(float fSpace)
{
	m_fSpace = fSpace;
}

void AAllianceManager::Set_Fomation(FString strGroupName, EAlliance_Formation eFormatio)
{
	switch (eFormatio)
	{
	case EAlliance_Formation::FORMATION_TRIANGLE:
		TriangleFormation(strGroupName);
		break;
	case EAlliance_Formation::FORMATION_RECT:
		break;
	case EAlliance_Formation::FORMATION_END:
		break;
	}
}

void AAllianceManager::Inset_Alliacne(FString strGroupName, class AAlliance* pActor)
{
	TArray<class AAlliance*>*			pAarrayActor = Get_Array(strGroupName);

	if (NULL == pAarrayActor)
	{
		TArray<class AAlliance*>		TarrayActor;
		TarrayActor.Add(pActor);
		m_MapAlliance.Emplace(strGroupName, TarrayActor);
		m_GroupNameArray.Add(strGroupName);
	}

	else
		pAarrayActor->Add(pActor);
}

TArray<class AAlliance*>* AAllianceManager::Get_Array(FString strGroupName)
{
	if (NULL == m_MapAlliance.Find(strGroupName))
		return NULL;

	else
		return m_MapAlliance.Find(strGroupName);
}

void AAllianceManager::TriangleFormation(FString strGroupName)
{
	TArray<class AAlliance*>*			TarrayActor = Get_Array(strGroupName);

	if (NULL == TarrayActor)
		return;

	ALLIANCEARRAY::TIterator			iter_begin = TarrayActor[0];

	FVector		VecPosition = (*iter_begin)->GetActorLocation();
	FVector		VecSpacePosition(0, 0, 0);

	int									iIndex(0);
	int									iCount(0);
	int									iAddValue(1);
	float								fSpcaceCal(0.0f);

	++iter_begin;

	for (int index = 0; index != TarrayActor->Num(); ++index)
	{
		if (0 == iIndex)
		{
			++iIndex;
			continue;
		}

		fSpcaceCal = m_fSpace * iAddValue;

		if (iIndex & 1)
		{
			VecSpacePosition = FVector(VecPosition.X - fSpcaceCal, VecPosition.Y - fSpcaceCal, VecPosition.Z);
			++iCount;
		}

		else
		{
			VecSpacePosition = FVector(VecPosition.X - fSpcaceCal, VecPosition.Y + fSpcaceCal, VecPosition.Z);
			++iCount;
		}

		(*iter_begin)->SetActorLocation(VecSpacePosition);

		if (iCount >= 2)
		{
			++iAddValue;
			iCount = 0;
		}

		++iIndex;
		++iter_begin;
	}
}
