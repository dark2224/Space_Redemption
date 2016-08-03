// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class SPACE_REDEMPTION_API AEnemySpawner : public AActor
{
	GENERATED_BODY()

private:
	float _ElapsedTime;
	bool _Activated;
	void SpawnFighter(FVector location, AActor* target);
public:
	// Sets default values for this actor's properties
	AEnemySpawner();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	void ActivateSpawner();
};