// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MiniGun.generated.h"

UCLASS()
class SPACE_REDEMPTION_API AMiniGun : public AActor
{
	GENERATED_BODY()
private:
	const float GunRotatingSpeed = 360;
	const FRotator Clamper = FRotator(22.5f,70.0f,0);
	class ATouchPad* targetPad;
	float RotatorSize(struct FRotator param);
	float SquaredRotatorSize(struct FRotator param);
protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* LaserPointer;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* RealGunMesh;
public:	
	// Sets default values for this actor's properties
	AMiniGun();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	void LinkPad(class ATouchPad* target);
};
