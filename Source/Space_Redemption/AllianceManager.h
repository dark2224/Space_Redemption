// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include "Alliance.h"

#include "AllianceManager.generated.h"

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
	UFUNCTION(BlueprintCallable, Category = "AllianceGroup")
		TArray<class AAlliance*> Get_Alliance();
public: // Inset
	UFUNCTION(BlueprintCallable, Category = "AllianceGroup")
		void Inset_Alliacne(TArray<class AAlliance*> AAlliance);
private:
	TArray<class AAlliance*>							m_AllianceArray;
	typedef TArray<class AAlliance*>					ALLIANCEARRAY;
};