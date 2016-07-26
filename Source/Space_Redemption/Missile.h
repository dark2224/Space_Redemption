// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Missile.generated.h"

UENUM(BlueprintType)
enum class Direction_Type : uint8
{
	DIR_Z UMETA(DisplayName = "Dir_Z"),
	DIR_YZ UMETA(DisplayName = "Dir_YZ"),
	DIR_Y UMETA(DisplayName = "Dir_Y"),
	DIR_YNZ UMETA(DisplayName = "Dir_YNZ"),
	DIR_NZ UMETA(DisplayName = "Dir_NZ"),
	DIR_NYNZ UMETA(DisplayName = "Dir_NYNZ"),
	DIR_NY UMETA(DisplayName = "Dir_NY"),
	DIR_NYZ UMETA(DisplayName = "Dir_NYZ"),
	DIR_END UMETA(DisplayName = "Dir_END")
};

UCLASS()
class SPACE_REDEMPTION_API AMissile : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AMissile();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
public:
	UFUNCTION(BlueprintCallable, Category = "Missile")
		void Set_Dir(Direction_Type eType);
public:
	Direction_Type Get_Dir();
private:
	Direction_Type							m_eDir;
};