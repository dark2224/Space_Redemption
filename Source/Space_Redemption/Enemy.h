// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UENUM(BlueprintType)
enum class Enemy_Type : uint8
{
	ENEMY_Alive UMETA(DisplayName = "Enemy_Alive"),
	ENEMY_DEATH UMETA(DisplayName = "Enemy_Death"),
	ENEMY_END UMETA(DisplayName = "Enemy_End"),
};

UCLASS()
class SPACE_REDEMPTION_API AEnemy : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AEnemy();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
public:
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		Enemy_Type Get_Type();
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		int Get_Hp();
public:
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		void Set_Hp(int iHp);
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		void Set_Damage(int iDamage);
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		void Set_EnemyType(Enemy_Type eEnemyType);
private:
	Enemy_Type								m_eEnemy_Type;
	int										m_iHp;
};