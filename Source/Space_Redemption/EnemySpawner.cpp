// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "EnemySpawner.h"
#include "AEnemyFighter.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	_ElapsedTime = 0.0f;
	_Activated = false;
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	if (!_Activated)
		return;
	Super::Tick(DeltaTime);
	_ElapsedTime += DeltaTime;

}
void AEnemySpawner::ActivateSpawner() {
	_Activated = true;
}
void AEnemySpawner::SpawnFighter(FVector location, AActor* target) {

	//GWorld->SpawnActor<AAEnemyFighter>(AAEnemyFighter::StaticClass(), location, FRotator());

	AAEnemyFighter* Baby = (AAEnemyFighter*)GWorld->SpawnActor<AAEnemyFighter>(AAEnemyFighter::StaticClass(), location, FRotator());
	Baby->SetStategy(target,2000.0f,FRotator());
}