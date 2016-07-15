// Fill out your copyright notice in the Description page of Project Settings.
/*
���� ���� : ���� �� �ִ� ������Ʈ�� ������, ���� �� �ִ� ������Ʈ�� ��ȣ�ۿ���, �����̵���
�Է� : ���ٱ�� Activate(�Ҹ������� ����)
���۷��� : Ÿ������ ��� ���� �� �ִ� ������Ʈ ���۷��� ����
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
