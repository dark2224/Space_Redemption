// Fill out your copyright notice in the Description page of Project Settings.
/*
손의 상태 : 만질 수 있는 오브젝트에 접근중, 만질 수 있는 오브젝트와 상호작용중, 자유이동중
입력 : 접근기능 Activate(불리언으로 관리)
레퍼런싱 : 타겟으로 삼는 만질 수 있는 오브젝트 레퍼런스 변수
*/
#pragma once

#include "Components/SceneComponent.h"
#include "TangibleActor.h"
#include "Hand.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACE_REDEMPTION_API UHand : public UActorComponent
{
protected:
	bool ReadyToContact;
	class TangibleActor* TargetTangibleActor;
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHand();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	
};
