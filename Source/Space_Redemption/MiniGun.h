// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MiniGun.generated.h"

UCLASS()
class SPACE_REDEMPTION_API AMiniGun : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UMeshComponent* LaserPointer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UMeshComponent* RealGunMesh;
public:	
	// Sets default values for this actor's properties
	AMiniGun();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
