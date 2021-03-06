// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PlayerShip.generated.h"

UCLASS()
class SPACE_REDEMPTION_API APlayerShip : public AActor
{
	GENERATED_BODY()
private:
	bool IsAccelerating = false;
	FRotator CurrentRotationSpeed = FRotator(0.0f,0.0f,0.0f);
	FRotator TargetRotationSpeed = FRotator(0.0f, 0.0f, 0.0f);
	float CurrentSpeed;
	const float MaxSpeed = 300.0f;
	const float Acceleration = 80.0f;
	const float Decceleration = 100;
	const float RotationAcceleration = 20;
	const float RotationDeccelration = 20;
	const float MaxRotationspeed = 10;
	const float PitchClamper = 30;
	const float IgnorableAxisValue = 0.1f;
	float RotatorSize(struct FRotator param);
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
	class ATangibleActor* EmergencyLever;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
		class ATouchPad* GunPad;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
		class AHandleStick* HandleStick;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
		class ATangibleActor* MissileButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
		class APilotPawn* Pilot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
		class AMiniGun* Minigun;
public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
		class UStaticMeshComponent* Cockpit;
	// Sets default values for this actor's properties
	APlayerShip();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable, Category = "Initialization")
		virtual void DefaultSet(class ATangibleActor* emergencyLever_p, class ATouchPad* GunPad_p, class AHandleStick* HandleStick_p, class ATangibleActor* MissileButton_p, class APilotPawn* Pilot_p, class AMiniGun* minigun_p);
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;	
};