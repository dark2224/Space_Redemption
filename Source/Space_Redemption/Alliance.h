// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Alliance.generated.h"

UENUM(BlueprintType)
enum class Alliance_Type : uint8
{
	ALLIANCE_Alive UMETA(DisplayName = "Alliance_Alive"),
	ALLIANCE_DEATH UMETA(DisplayName = "Alliance_Death"),
	ALLIANCE_END UMETA(DisplayName = "Alliance_End"),
};

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
		Alliance_Type	Get_Type();
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		bool			Get_Delay();
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		int				Get_Hp();
public:
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		void			Set_Hp(int iHp);
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		void			Set_Damage(int iDamage);
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		void			Set_AllianceType(Alliance_Type eAllianceType);
public:
	UFUNCTION(BlueprintCallable, Category = "Alliance")
		bool			Booster_Delay();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alliance")
		float									m_fDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alliance")
		float									m_fBoosterTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alliance")
		float									m_fOriBoosterTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alliance")
		int										m_iHp;
private:
	Alliance_Type								m_eAlliance_Type;
private:
	float										m_fTime;
};