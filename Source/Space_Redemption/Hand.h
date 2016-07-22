// Fill out your copyright notice in the Description page of Project Settings.
/*
손이 있어야할 위치는 이 클래스에서 어깨와 현실컨트롤러의 위치를 참조해서 계산한다.
손의 상태 : 만질 수 있는 오브젝트에 접근중, 만질 수 있는 오브젝트와 상호작용중, 자유이동중
입력 : 접근기능 Activate(불리언으로 관리)
레퍼런싱 : 타겟으로 삼는 만질 수 있는 오브젝트 레퍼런스 변수
*/
#pragma once

#include "Components/SceneComponent.h"
//#include "TangibleActor.h"
#include "Hand.generated.h"

//enum InteractionStatus {
//	Idle, Approaching, Interacting
//};
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPACE_REDEMPTION_API UHand : public USceneComponent
{
	GENERATED_BODY()
private:
	float _CurrentHandSpeed = 0;
	float _MaxHandSpeed = 100;
	float _HandAccel = 2000;
	float _CurrentHandRotationSpeed = 0;
	float _MaxHandRotationSpeed = 100;
	float _HandRotationAccel = 200;
	bool _DoesWantToGrab = false;
	float _ArmLength = 120;
	class UPrimitiveComponent* _HandCollision;
	class UPrimitiveComponent* _RealHandCollision;
	void FollowTargetWithSpeed(FVector target, float DeltaTime, float Rate = 1);
	void FollowTargetWithSpeed(FRotator target, float DeltaTime, float Rate = 1);
protected:
	USceneComponent* _ShoulderScene;
	USceneComponent* _RealHandScene;
	// 손의 현재상태를 나타냅니다. 상태는 다음 세가지 중 하나입니다.
	// 노는중, 상호작용가능한 오브젝트에 접근중, 상호작용중 
	enum InteractionStatus Status;
	// 지금 상호작용의 대상이 되는 오브젝트의 레퍼런스입니다.
	class ATangibleActor* TargetTangibleActor;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision)
	//class UPrimitiveComponent* _HandSceneCollision;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision)
	//class UPrimitiveComponent* _RealHandSceneCollision;
public:
	UFUNCTION(BlueprintCallable, Category = "Activation")
		void MakeGrabAvailable() { _DoesWantToGrab = true; }
	UFUNCTION(BlueprintCallable, Category = "Activation")
		void MakeGrabUnable() { _DoesWantToGrab = false; }
	UFUNCTION(BlueprintCallable, Category = "Initialization")
		void DefaultSet(class UPrimitiveComponent* _HandCollision, class UPrimitiveComponent* _RealHandCollision);
	UHand();
	// 오브젝트에 접근을 시작할때
	UFUNCTION(BlueprintCallable, Category = "GetInfo")
		virtual UPrimitiveComponent* GetHandSceneCollision();
	UFUNCTION(BlueprintCallable, Category = "GetInfo")
		virtual UPrimitiveComponent* GetRealHandSceneCollision();
	// 오브젝트에 접근을 시작할때
	UFUNCTION(BlueprintCallable, Category = "Updatingstat")
		virtual void StartApproaching(class ATangibleActor* TargetTangibleActor);
	// 오브젝트와 상호작용을 시작할때
	UFUNCTION(BlueprintCallable, Category = "Updatingstat")
		virtual void StartInteraction();
	// 오브젝트와 상호작용이 끝났을때
	UFUNCTION(BlueprintCallable, Category = "Updatingstat")
		virtual void QuitInteraction();
	// Sets default values for this component's properties
	// 어깨와 현실위치씬의 포인터를 매개변수로 전달해줍니다. 반드시 생성후 바로 호출되어야합니다.
	void DefaultSet(USceneComponent* Shoulder, USceneComponent* RealWorldHand);
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable, Category = "StatusReference")
		bool DoesWantToGrab();
	UFUNCTION(BlueprintCallable, Category = "StatusReference")
		InteractionStatus GetStaus() { return Status; }
	UFUNCTION(BlueprintCallable, Category = "StatusReference")
		void SetStaus(InteractionStatus param) { Status = param; }
	UFUNCTION(BlueprintCallable, Category = "StatusReference")
		class ATangibleActor* GetTargetTangibleObject() { return TargetTangibleActor; }
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
