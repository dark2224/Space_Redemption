// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "EventDoor.generated.h"

UENUM(BlueprintType)
enum class Door_Type : uint8
{
	DOOR_On UMETA(DisplayName = "Door_On"),
	DOOR_Off UMETA(DisplayName = "Door_Off"),
	DOOR_END UMETA(DisplayName = "Door_End"),
};

UCLASS()
class SPACE_REDEMPTION_API AEventDoor : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AEventDoor();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
public:		// Get
	UFUNCTION(BlueprintCallable, Category = "Event")
	bool	Distance(FVector vStartPosition, FVector vEndPosition);
public:		// Set
	UFUNCTION(BlueprintCallable, Category = "Event")
	void	Set_Position(FVector vPosition);
public:
	UFUNCTION(BlueprintCallable, Category = "Event")
	void	OnOff_Door(Door_Type eType, FVector vPosition, float fUPValue);
	UFUNCTION(BlueprintCallable, Category = "Event")
	bool	Delay();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Evnet")
	float				m_fDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Evnet")
	float				m_fSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Evnet")
	float				m_fTime;
private:
	FVector				m_VecOriPoistion;
};