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
	GENERATED_BODY()
private:
	FVector2D _NormalizedFacingVector;
	//float ReturningFactor;
	//const float ReturningRate = 1.0f;
protected:
	UFUNCTION(BlueprintCallable, Category = "InsrumentStatus")
		virtual void SetNormalizedFacingVector(FVector2D value);
public:
	UFUNCTION(BlueprintCallable, Category = "InsrumentStatus")
		virtual FVector2D GetNormalizedFacingVector();
	//UFUNCTION(BlueprintCallable, Category = "InsrumentStatus")
	//	void QuitInteraction();
	//UFUNCTION(BlueprintCallable, Category = "InsrumentStatus")
	//	void StartInteraction();
};