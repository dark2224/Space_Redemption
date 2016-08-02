// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include "AI_State.h"

#include "Alliance.generated.h"

UCLASS()
class SPACE_REDEMPTION_API AAlliance : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AAlliance();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
public:
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		State_Type		Get_Type();
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		bool			Get_Delay();
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		int				Get_Hp();
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		int				Get_Dagame();
	UFUNCTION(BlueprintCallable, Category = "Enemy")
		bool			Get_Shoot();
public:
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		void			Set_Hp(int iHp);
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		void			Set_Damage(int iDamage);
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		void			Set_AllianceType(State_Type eAllianceType);
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		void			Set_Shoot(bool bShoot);
public:
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		bool			Booster_Delay();
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		bool			Shoot_Delay();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alliance")
		float									m_fDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alliance")
		float									m_fBoosterTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alliance")
		float									m_fOriBoosterTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alliance")
		float									m_fShootDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alliance")
		float									m_fOriShootDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alliance")
		int										m_iHp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alliance")
		int										m_iDamage;
private:
	State_Type									m_eAlliance_Type;
private:
	float										m_fTime;
	bool										m_bShoot;
};