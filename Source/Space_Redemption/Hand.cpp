// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "InteractionStatus.h"
#include "TangibleActor.h"
#include "Hand.h"

// Sets default values for this component's properties
UHand::UHand()
	: TargetTangibleActor(NULL)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	Status = Idle;
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UHand::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

void UHand::DefaultSet(USceneComponent* Shoulder, USceneComponent* RealWorldHand) {
	_ShoulderScene = Shoulder;
	_RealHandScene = RealWorldHand;
}
// Called every frame
void UHand::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	float CurrentDistance;
	switch (Status) {
	case Idle:
		// 아래는 어깨에서 현실손까지의 거리
		CurrentDistance = (_RealHandScene->GetComponentLocation() - _ShoulderScene->GetComponentLocation()).Size();
		//아래 조건 : 팔길이보다 현실손이 가까이 있다면
		if (_ArmLength > CurrentDistance)
			SetWorldTransform(_RealHandScene->GetComponentTransform());
		else
		{
			SetWorldLocation(_ShoulderScene->GetComponentLocation() + _ArmLength*(_RealHandScene->GetComponentLocation() - _ShoulderScene->GetComponentLocation()) / CurrentDistance);
			SetWorldRotation(_RealHandScene->GetComponentRotation());
		}
		break;
	case Approaching:
		//애니메이션 블렌딩용 float 조작
		CurrentDistance = (_RealHandScene->GetComponentLocation() - _ShoulderScene->GetComponentLocation()).Size();
		//아래 조건 : 팔길이보다 현실손이 가까이 있다면
		if (_ArmLength > CurrentDistance)
		{
			SetWorldTransform(_RealHandScene->GetComponentTransform());
			SetWorldRotation(TargetTangibleActor->GetNormalizedApproachingDistance()*TargetTangibleActor->GetRotatorBeforeApproach() + (1 - TargetTangibleActor->GetNormalizedApproachingDistance())*TargetTangibleActor->GetDesiredHandTransform()->GetComponentTransform().Rotator());
		}
		else
		{
			SetWorldLocation(_ShoulderScene->GetComponentLocation() + _ArmLength*(_RealHandScene->GetComponentLocation() - _ShoulderScene->GetComponentLocation()) / CurrentDistance);
			SetWorldRotation(TargetTangibleActor->GetNormalizedApproachingDistance()*TargetTangibleActor->GetRotatorBeforeApproach() + (1 - TargetTangibleActor->GetNormalizedApproachingDistance())*TargetTangibleActor->GetDesiredHandTransform()->GetComponentTransform().Rotator());
		}
		break;
	case Interacting:
		SetWorldTransform(TargetTangibleActor->GetDesiredHandTransform()->GetComponentTransform());
		break;
	default:
		break;
	}
}

void UHand::StartApproaching(class ATangibleActor* TargetTangibleActor) {
	if (Status != Idle)
		return;
	Status = Approaching;
	this->TargetTangibleActor = TargetTangibleActor;
}
void UHand::StartInteraction() {
	if (Status != Approaching)
		return;
	Status = Interacting;
}
void UHand::QuitInteraction() {
	if (Status != Interacting)
		return;
	Status = Idle;
}