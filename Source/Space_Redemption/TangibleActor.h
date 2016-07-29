/*
손으로 만지고 상호작용할 수 있는 물체들의 부모 클래스입니다.
*/
#pragma once

#include "GameFramework/Actor.h"
#include "InteractionStatus.h"
#include "TangibleActor.generated.h"

UCLASS()
class SPACE_REDEMPTION_API ATangibleActor : public AActor
{
	GENERATED_BODY()
private:
	FRotator ApproachingDeltaRotation;
protected:
	bool isPushingSecond = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
		UAnimSequence* InteractingAnimation;
	enum InteractionStatus Status;
	FRotator RotatorBeforeApproach;
	float DistanceBeforeApproach;
	float NormalizedApproachingDistance;
	// 메쉬에 대한 손의 상대적 위치와 각도를 저장합니다. Set메서드를 통해 블루프린트상에서 초기화해줘야 합니다.
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent *DesiredHandTransform;
	UPROPERTY()
		//class APilotPawn* TargetPilotPawn;
		class UHand* TargetHand;
	class USceneComponent *TargetRealHandScene;
	// 손이 오브젝트에 다가갈 때 한번만 호출되는 함수입니다. 대부분의 필요한 변수가 초기화됩니다. 참조하고 있는 Hand 객체의 StartApproaching 메서드도 호출합니다.
	UFUNCTION(BlueprintCallable, Category = "Updatingstat")
		virtual void StartBeingApproached(class UHand* handparam, class USceneComponent *RealHandSceneParm,FRotator DeltaRotation);
	//// 손과 오브젝트가 상호작용을 시작해야 할때 호출됩니다. 이때부터 손과 오브젝트는 서로 딱 붙게 됩니다.
	//UFUNCTION(BlueprintCallable, Category = "Updatingstat")
	//	virtual void StartInteraction(class UHand* param) { TargetHand = param; Status = Interacting; }
	//// 손과 오브젝트가 상호작용을 멈춰야 할 때 호출됩니다. 손과 오브젝트는 이때부터 서로 독립됩니다.
	//UFUNCTION(BlueprintCallable, Category = "Updatingstat")
	//	virtual void QuitInteraction(class UHand* param) { TargetHand = nullptr; };
	// 손 위치에 대한 세터
	UFUNCTION(BlueprintCallable, Category = "InitializationRequired")
		void SetDistanceBeforeApproach(float param) { DistanceBeforeApproach = param; }
	UFUNCTION(BlueprintCallable, Category = "InitializationRequired")
		void SetRotatorBeforeApproach(FRotator param) { RotatorBeforeApproach = param; }
	UFUNCTION(BlueprintCallable, Category = "InitializationRequired")
		void SetDesiredHandTransform(USceneComponent* param) { DesiredHandTransform = param; }
	UFUNCTION(BlueprintCallable, Category = "InitializationRequired")
		void SetNormalizedApproachingDistance(float param) { NormalizedApproachingDistance = (param < 1) ? param : 1; }
public:
	// Sets default values for this actor's properties
	ATangibleActor();
	// 타겟 손, 타겟 현실 손 씬 컴포넌트는 여기서 겟쎗 가능.
	virtual void BeginPlay() override;
	FRotator GetApproachingDeltaRotation() {
		return ApproachingDeltaRotation;
	}
	UFUNCTION(BlueprintCallable, Category = "IntearctionStatus")
		float GetNormalizedApproachingDistance() { return NormalizedApproachingDistance; }
	UFUNCTION(BlueprintCallable, Category = "IntearctionStatus")
		InteractionStatus GetStaus() { return Status; }
	UFUNCTION(BlueprintCallable, Category = "IntearctionStatus")
		void SetStaus(InteractionStatus param) { Status = param; }
	UFUNCTION(BlueprintCallable, Category = "IntearctionStatus")
		void SetTargetHand(class UHand* param) { TargetHand = param; }
	UFUNCTION(BlueprintCallable, Category = "IntearctionStatus")
		class UHand* GetTargetHand() { return TargetHand; }
	UFUNCTION(BlueprintCallable, Category = "IntearctionStatus")
		void SetTargetRealHandScene(class USceneComponent* param) { TargetRealHandScene = param; }
	UFUNCTION(BlueprintCallable, Category = "IntearctionStatus")
		class USceneComponent* GetTargetRealHandScene() { return TargetRealHandScene; }
	UFUNCTION(BlueprintCallable, Category = "IntearctionStatus")
		float GetDistanceBeforeApproach() { return DistanceBeforeApproach; }
	UFUNCTION(BlueprintCallable, Category = "IntearctionStatus")
		FRotator GetRotatorBeforeApproach() { return RotatorBeforeApproach; }
	UFUNCTION(BlueprintCallable, Category = "Animation")
		UAnimSequence* GetInteractingAnimation() { return InteractingAnimation; }
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	UFUNCTION(BlueprintCallable, Category = "SecondFunction")
		virtual void StartSecondaryGrap() {}
	UFUNCTION(BlueprintCallable, Category = "SecondFunction")
		virtual void StopSecondaryGrap(){}
	bool GetisPushingSecond();
	virtual class USceneComponent* GetDesiredHandTransform() { return DesiredHandTransform; }
	void SetIsPushingSecond(bool value);
};
