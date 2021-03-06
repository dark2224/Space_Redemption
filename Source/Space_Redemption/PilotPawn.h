// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Hand.h"
#include "PilotPawn.generated.h"

UCLASS()
class SPACE_REDEMPTION_API APilotPawn : public APawn
{
	GENERATED_BODY()
		/** 몸 메쉬입니다. */
private:
	FVector Deltahandloc;
public:
	const FVector RelativeArmposition = FVector(-20.0f, 0.0f, -175.0f);
	// Sets default values for this pawn's properties
	APilotPawn();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Location)
		FVector Hand_move_dirvec;
	UPROPERTY(VisibleDefaultsOnly, Category = Scene)
		USceneComponent* RightShoulderScene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Location)
		USceneComponent* RightRealHandScene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Location)
		class UHand* RightHand;
	UPROPERTY(VisibleDefaultsOnly, Category = Scene)
		USceneComponent* LeftShoulderScene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Location)
		USceneComponent* LeftRealHandScene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Location)
		class UHand* LeftHand;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* Origin;

	//UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* Dev_HeadMesh;
	// Dev들어간 변수는 나중에 없애주면 됨.
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* RightArm;
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* LeftArm;
	//UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	//	class USkeletalMeshComponent* RealBody;
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UCameraComponent* FirstPersonCameraComponent;
	UFUNCTION(BlueprintCallable, Category = "ComponentGetters")
		class UHand* GetRightHand() { return RightHand; }
	UFUNCTION(BlueprintCallable, Category = "ComponentGetters")
		class USceneComponent* GetRealWorldRightHand() { return RightRealHandScene; }
	UFUNCTION(BlueprintCallable, Category = "ComponentGetters")
		class UHand* GetLeftHand() { return LeftHand; }
	UFUNCTION(BlueprintCallable, Category = "ComponentGetters")
		class USceneComponent* GetRealWorldLeftHand() { return LeftRealHandScene; }
};
