// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include "AI_State.h"

#include "Enemy.generated.h"

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
		State_Type	Get_Type();
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		bool		Get_Delay();
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		int			Get_Hp();
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		int			Get_Dagame();
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		bool		Get_Shoot();
public:
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		void Set_Hp(int iHp);
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		void Set_Damage(int iDamage);
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		void Set_EnemyType(State_Type eEnemyType);
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		void			Set_Shoot(bool bShoot);
public:
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		bool	Booster_Delay();
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		bool			Shoot_Delay();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	float									m_fDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	float									m_fBoosterTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	float									m_fOriBoosterTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	float									m_fShootDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	float									m_fOriShootDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	int										m_iHp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	int										m_iDamage;
private:
	State_Type								m_eEnemy_Type;
private:
	float									m_fTime;
	bool									m_bShoot;
};