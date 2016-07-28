// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TangibleActor.h"
#include "TouchPad.generated.h"

/**
 * 
 */
UCLASS()
class SPACE_REDEMPTION_API ATouchPad : public ATangibleActor
{
	GENERATED_BODY()
private : 
	class AMiniGun* Minigun;
	FVector2D MappingCoordinate;
protected:
	UFUNCTION(BlueprintCallable, Category = "Initialization")
		void SetMappingCoordinate(FVector2D value);
public:
	FVector2D GetMappingCoordinate();
	void LinkMinigun(class AMiniGun* target);
};
