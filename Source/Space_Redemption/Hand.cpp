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

	//_HandSceneCollision = CreateDefaultSubobject<USphereComponent>(TEXT("RightHandCollision"));
	//_HandSceneCollision->SetupAttachment(this);
	//_RealHandSceneCollision = CreateDefaultSubobject<USphereComponent>(TEXT("RightRealHandCollision"));
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
	//_RealHandSceneCollision->SetupAttachment(_RealHandScene);
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
		{
			SetWorldLocation(_RealHandScene->GetComponentLocation());
			//FollowTargetWithSpeed(_RealHandScene->GetComponentLocation(), DeltaTime);
		}
		else
		{
			SetWorldLocation(_RealHandScene->GetComponentLocation() + _ArmLength*(_RealHandScene->GetComponentLocation() - _ShoulderScene->GetComponentLocation()));
			//FollowTargetWithSpeed(_ShoulderScene->GetComponentLocation() + _ArmLength*(_RealHandScene->GetComponentLocation() - _ShoulderScene->GetComponentLocation()).GetSafeNormal(), DeltaTime);
		}
		FollowTargetWithSpeed(FRotationMatrix::MakeFromX((GetComponentLocation() - _ShoulderScene->GetComponentLocation()).GetSafeNormal()).Rotator() + FRotator(90, 90, 0), DeltaTime);
		break;
	case Approaching:
		//애니메이션 블렌딩용 float 조작
		CurrentDistance = (_RealHandScene->GetComponentLocation() - _ShoulderScene->GetComponentLocation()).Size();
		//아래 조건 : 팔길이보다 현실손이 가까이 있다면
		if (_ArmLength > CurrentDistance)
		{
			SetWorldLocation(_RealHandScene->GetComponentLocation());
			//FollowTargetWithSpeed(_RealHandScene->GetComponentLocation(), DeltaTime);
			FollowTargetWithSpeed(TargetTangibleActor->GetNormalizedApproachingDistance()*TargetTangibleActor->GetRotatorBeforeApproach() + (1 - TargetTangibleActor->GetNormalizedApproachingDistance())*TargetTangibleActor->GetDesiredHandTransform()->GetComponentTransform().Rotator(), DeltaTime);
		}
		else
		{
			SetWorldLocation(_RealHandScene->GetComponentLocation() + _ArmLength*(_RealHandScene->GetComponentLocation() - _ShoulderScene->GetComponentLocation()));
			//FollowTargetWithSpeed(_ShoulderScene->GetComponentLocation() + _ArmLength*(_RealHandScene->GetComponentLocation() - _ShoulderScene->GetComponentLocation()).GetSafeNormal(),DeltaTime);
			FollowTargetWithSpeed(TargetTangibleActor->GetNormalizedApproachingDistance()*TargetTangibleActor->GetRotatorBeforeApproach() + (1 - TargetTangibleActor->GetNormalizedApproachingDistance())*TargetTangibleActor->GetDesiredHandTransform()->GetComponentTransform().Rotator(), DeltaTime);
		}
		break;
	case Interacting:
		SetWorldTransform(TargetTangibleActor->GetDesiredHandTransform()->GetComponentTransform());
		//FollowTargetWithSpeed(TargetTangibleActor->GetDesiredHandTransform()->GetComponentLocation(), DeltaTime,1000);
		//FollowTargetWithSpeed(TargetTangibleActor->GetDesiredHandTransform()->GetComponentRotation(), DeltaTime,2000);
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
bool UHand::DoesWantToGrab() {
	return _DoesWantToGrab;
}
void UHand::DefaultSet(class UPrimitiveComponent* HandCollision, class UPrimitiveComponent* RealHandCollision)
{
	this->_HandCollision = HandCollision;
	this->_RealHandCollision = RealHandCollision;
}
UPrimitiveComponent* UHand::GetHandSceneCollision() { return _HandCollision; }
UPrimitiveComponent* UHand::GetRealHandSceneCollision() { return _RealHandCollision; }	// 오브젝트에 접근을 시작할때
void UHand::FollowTargetWithSpeed(FVector target, float DeltaTime, float Rate) {
	FVector displacement = target - GetComponentLocation();
	//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, displacement.ToCompactString());
	if (displacement.Size() < Rate*_CurrentHandSpeed*DeltaTime)
	{
		_CurrentHandSpeed = _HandAccel*DeltaTime;
		SetWorldLocation(target);
	}
	else
	{
		if (_CurrentHandSpeed > _MaxHandSpeed)
			_CurrentHandSpeed = _MaxHandSpeed;
		AddWorldOffset(displacement.GetSafeNormal()*_CurrentHandSpeed*Rate*DeltaTime);
		_CurrentHandSpeed += _HandAccel*DeltaTime;
	}
}
void UHand::FollowTargetWithSpeed(FRotator target, float DeltaTime, float Rate) {
	FRotator first = GetComponentRotation();
	FVector displacement = FVector(target.Roll-first.Roll, target.Pitch - first.Pitch, target.Yaw-first.Yaw);
	FVector Newdisplacement(0,0,0);
	for (float i = -1; i <= 1; i+=1.0f) {
		for (float j = -1; i <= 1; i += 1.0f) {
			for (float k = -1; i <= 1; i += 1.0f) {
				FVector challenger = FVector(displacement.X+i*360,displacement.Y+j*360,displacement.Z+360*k);
				if(Newdisplacement.Size() > challenger.Size())
				Newdisplacement = challenger;
			}
		}
	}
	displacement = Newdisplacement;
	//GEngine::AddOnScreenDebugMessage(-1, 3.0, FColor::Blue, displacement.ToCompactString());
	if (displacement.Size() < Rate*_CurrentHandRotationSpeed*DeltaTime)
	{
		_CurrentHandRotationSpeed = _HandRotationAccel*DeltaTime;
		SetWorldRotation(target);
	}
	else
	{
		if (_CurrentHandRotationSpeed > _MaxHandRotationSpeed)
			_CurrentHandRotationSpeed = _MaxHandRotationSpeed;
		displacement = displacement.GetSafeNormal()*_CurrentHandRotationSpeed*Rate*DeltaTime;
		AddWorldRotation(FRotator(displacement.Y, displacement.Z, displacement.X));
		_CurrentHandRotationSpeed += _HandRotationAccel*DeltaTime;
	}
}