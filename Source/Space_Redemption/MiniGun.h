#pragma once

#include "GameFramework/Actor.h"
#include "MiniGun.generated.h"

UCLASS()
class SPACE_REDEMPTION_API AMiniGun : public AActor
{
	GENERATED_BODY()
private:
	bool Deccelerating = false;
	const float GunRotatingSpeed = 1440;
	float CurrentRotationSpeedFactor = 0;
	const FRotator Clamper = FRotator(22.5f, 70.0f, 0);
	class ATouchPad* targetPad;
	float RotatorSize(struct FRotator param);
	float SquaredRotatorSize(struct FRotator param);
	float GapBetweenFire = 0.5f;
	float AccumulatedTimeAfterFire = 0;
	bool isleftturn = false;
protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Mesh")
		UStaticMeshComponent* LaserPointer;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Mesh")
		UStaticMeshComponent* RealGunMesh;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Mesh")
		UParticleSystemComponent* LeftFire;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Mesh")
		UParticleSystemComponent* RightFire;
	UFUNCTION(BlueprintCallable, Category = "Rotation")
		float GetRotationSpeed();
public:
	// Sets default values for this actor's properties
	AMiniGun();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	void LinkPad(class ATouchPad* target);
	void StartRotation();
	void StopRotation();
};