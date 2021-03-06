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
	bool IsGoingForward = false;
	UPROPERTY()
	UAudioComponent* MovingLoopSound;
	FVector2D _NormalizedFacingVector;
	//float ReturningFactor;
	//const float ReturningRate = 1.0f;
protected:
	UFUNCTION(BlueprintCallable, Category = "InsrumentStatus")
		virtual void SetNormalizedFacingVector(FVector2D value);
	UFUNCTION(BlueprintCallable, Category = "DefaultSet")
		void SetSound(UAudioComponent* reference);
public:
	UFUNCTION(BlueprintCallable, Category = "InsrumentStatus")
		bool GetIsGoingForward();
		//AHandleStick();
	UFUNCTION(BlueprintCallable, Category = "InsrumentStatus")
		virtual FVector2D GetNormalizedFacingVector();
	//UFUNCTION(BlueprintCallable, Category = "InsrumentStatus")
	//	void QuitInteraction();
	//UFUNCTION(BlueprintCallable, Category = "InsrumentStatus")
	//	void StartInteraction();
	void AHandleStick::StartSecondaryGrap() override;
	void AHandleStick::StopSecondaryGrap() override;
};