// Fill out your copyright notice in the Description page of Project Settings.
/*
���� �־���� ��ġ�� �� Ŭ�������� ����� ������Ʈ�ѷ��� ��ġ�� �����ؼ� ����Ѵ�.
���� ���� : ���� �� �ִ� ������Ʈ�� ������, ���� �� �ִ� ������Ʈ�� ��ȣ�ۿ���, �����̵���
�Է� : ���ٱ�� Activate(�Ҹ������� ����)
���۷��� : Ÿ������ ��� ���� �� �ִ� ������Ʈ ���۷��� ����
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
	// ���� ������¸� ��Ÿ���ϴ�. ���´� ���� ������ �� �ϳ��Դϴ�.
	// �����, ��ȣ�ۿ밡���� ������Ʈ�� ������, ��ȣ�ۿ��� 
	enum InteractionStatus Status;
	// ���� ��ȣ�ۿ��� ����� �Ǵ� ������Ʈ�� ���۷����Դϴ�.
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
	// ������Ʈ�� ������ �����Ҷ�
	UFUNCTION(BlueprintCallable, Category = "GetInfo")
		virtual UPrimitiveComponent* GetHandSceneCollision();
	UFUNCTION(BlueprintCallable, Category = "GetInfo")
		virtual UPrimitiveComponent* GetRealHandSceneCollision();
	// ������Ʈ�� ������ �����Ҷ�
	UFUNCTION(BlueprintCallable, Category = "Updatingstat")
		virtual void StartApproaching(class ATangibleActor* TargetTangibleActor);
	// ������Ʈ�� ��ȣ�ۿ��� �����Ҷ�
	UFUNCTION(BlueprintCallable, Category = "Updatingstat")
		virtual void StartInteraction();
	// ������Ʈ�� ��ȣ�ۿ��� ��������
	UFUNCTION(BlueprintCallable, Category = "Updatingstat")
		virtual void QuitInteraction();
	// Sets default values for this component's properties
	// ����� ������ġ���� �����͸� �Ű������� �������ݴϴ�. �ݵ�� ������ �ٷ� ȣ��Ǿ���մϴ�.
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
