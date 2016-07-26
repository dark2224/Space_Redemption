// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "EnemyGroupManager.h"

AEnemyGroupManager::AEnemyGroupManager()
	: m_eFormation(EFormation_Type::FORMATION_END)
	, m_fSpace(0.0f),	m_fAngle(0.0f)
{
	PrimaryActorTick.bCanEverTick = false;
}

AEnemyGroupManager::~AEnemyGroupManager()
{
	Release();
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

TArray<class AEnemy*> AEnemyGroupManager::Get_Enemy(FString strGroupName)
{
	TArray<class AEnemy*>*			pAarrayActor = Get_Array(strGroupName);

	return *pAarrayActor;
}

void AEnemyGroupManager::Set_GroupSapce(float fSpace)
{
	m_fSpace = fSpace;
}

void AEnemyGroupManager::Set_Fomation(FString strGroupName, EFormation_Type eFormatio)
{
	switch (eFormatio)
	{
	case EFormation_Type::FORMATION_TRIANGLE:
		TriangleFormation(strGroupName);
		break;
	case EFormation_Type::FORMATION_RECT:
		break;
	case EFormation_Type::FORMATION_END:
		break;
	}
}

void AEnemyGroupManager::Inset_Enemey(FString strGroupName, class AEnemy* pActor)
{
	TArray<class AEnemy*>*			pAarrayActor = Get_Array(strGroupName);

	if (NULL == pAarrayActor)
	{
		TArray<class AEnemy*>		TarrayActor;
		TarrayActor.Add(pActor);
		m_MapGroup.Emplace(strGroupName, TarrayActor);
	}

	else
		pAarrayActor->Add(pActor);
}

void AEnemyGroupManager::Group_TargetMove(FString strGroupName, FVector Position, float fSpeed, float fDeltaSeconds)
{
	TArray<class AEnemy*>*			TarrayActor = Get_Array(strGroupName);

	if (NULL == TarrayActor)
		return;

	ARRAYACTOR::TIterator			iter_begin = TarrayActor[0];

	FVector							ActorPosition(0.0f, 0.0f, 0.0f);

	FRotator						ActorRotation(0.0f, 0.0f, 0.0f);

	FRotator						CrossAxis(0.0f, 0.0f, 0.0f);

	FVector							NormalPosition(0.0f, 0.0f, 0.0f);

	TriangleFormation(strGroupName);

	for (int index = 0; index != TarrayActor->Num(); ++index)
	{
		ActorPosition = (*iter_begin)->GetActorLocation();
		
		Position = Position.GetSafeNormal();

		NormalPosition = ActorPosition.GetSafeNormal();

		ActorRotation = (*iter_begin)->GetActorRotation();

		CrossAxis = Get_AngleToAxis(ActorPosition, Position);

		//ActorRotation.Pitch += FMath::Cos(m_fAngle);
		ActorRotation.Yaw += FMath::Sin(m_fAngle);

		(*iter_begin)->SetActorRotation(ActorRotation);

		++iter_begin;
	}
}

TArray<class AEnemy*>* AEnemyGroupManager::Get_Array(FString strGroupName)
{
	if (NULL == m_MapGroup.Find(strGroupName))
		return NULL;

	else
		return m_MapGroup.Find(strGroupName);
}

FRotator AEnemyGroupManager::Get_AngleToAxis(FVector PositionVector, FVector NormalVector)
{
	FVector					CorssAxis(0.0f, 0.0f, 0.0f);

	m_fAngle = FVector::DotProduct(PositionVector, NormalVector);

	m_fAngle = FMath::Acos(m_fAngle);

	m_fAngle = FMath::RadiansToDegrees(m_fAngle);

	//CorssAxis = FVector::CrossProduct(FVector::ForwardVector, NormalVector);

	if (CorssAxis.Z < 0)
		m_fAngle *= -1;

	m_fAngle = FMath::Abs(m_fAngle);

	FRotator	Rotator(CorssAxis.Y, CorssAxis.Z, CorssAxis.X);

	//Rotator = Rotator.GetNormalized();

	return Rotator;
}

void AEnemyGroupManager::TriangleFormation(FString strGroupName)
{
	TArray<class AEnemy*>*			TarrayActor = Get_Array(strGroupName);

	if (NULL == TarrayActor)
		return;

	ARRAYACTOR::TIterator			iter_begin = TarrayActor[0];

	FVector		VecPosition = (*iter_begin)->GetActorLocation();
	FVector		VecSpacePosition(0, 0, 0);

	int											iIndex(0);
	int											iCount(0);
	int											iAddValue(1);
	float										fSpcaceCal(0.0f);

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

void AEnemyGroupManager::Release(void)
{
}