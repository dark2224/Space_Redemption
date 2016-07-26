// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TangibleActor.h"
#include "HandleStick.generated.h"

/**
 *
 */
UCLASS()
class SPACE_REDEMPTION_API AHandleStick : public ATangibleActor
{
private: FVector2D _NormalizedFacingVector;
		 GENERATED_BODY()
protected:
	UFUNCTION(BlueprintCallable, Category = "InsrumentStatus")
		virtual void SetNormalizedFacingVector(FVector2D value);
public:
	UFUNCTION(BlueprintCallable, Category = "InsrumentStatus")
		virtual FVector2D GetNormalizedFacingVector();
};