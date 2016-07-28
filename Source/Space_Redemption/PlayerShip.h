// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PlayerShip.generated.h"

UCLASS()
class SPACE_REDEMPTION_API APlayerShip : public AActor
{
	GENERATED_BODY()

private:
	FRotator CurrentRotationSpeed = FRotator(0.0f,0.0f,0.0f);
	const float RotationAcceleration = 30;
	const float RotationDeccelration = 20;
	const float MaxRotationspeed = 20;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
	class ATangibleActor* EmergencyLever;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
		class ATangibleActor* GunPad;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
		class ATangibleActor* HandleStick;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
		class ATangibleActor* MissileButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main")
		class APilotPawn* Pilot;
public:	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
		class UStaticMeshComponent* Cockpit;
	// Sets default values for this actor's properties
	APlayerShip();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable, Category = "DeveloperTest")
		virtual void DefaultSet(class ATangibleActor* emergencyLever_p, class ATangibleActor* GunPad_p, class ATangibleActor* HandleStick_p, class ATangibleActor* MissileButton_p, class APilotPawn* Pilot_p);
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;	
};
