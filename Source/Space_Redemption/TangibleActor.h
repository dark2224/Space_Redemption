// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TangibleActor.generated.h"

UCLASS()
class SPACE_REDEMPTION_API ATangibleActor : public AActor
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintCallable, Category = "Updatingstat")
	void Beingapproached(class UHand* param);
public:	
	// Sets default values for this actor's properties
	ATangibleActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
