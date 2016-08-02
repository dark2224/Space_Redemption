// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SecondMissile.generated.h"

UCLASS()
// 2�� �����̻����� ��� ���� �ö󰬴ٰ� �������� ��� ��� ���ּ����� ������������ �ٰ����� �, �ΰ����� ���� �� �ִ�.
class SPACE_REDEMPTION_API ASecondMissile : public AActor
{
	GENERATED_BODY()
private:
	// ���� ������� ��� Ÿ��
	class AEnemy* target;
	// ������ ��� �߷¿� �����Ǵ� �Ʒ����� ���ӵ�
	float droppingAcceleration;
	// ����Ÿ���� ���� ������� ���������� ���ư��� ��� �ӷ�
	float RealVelocity;
	// FirstLeftTime�� ó�� �̻����� ��������� �̻����� ������ �±���� �ɸ��� �ð�
	float FirstLeftTime;
	// LeftTime�� ���� �̻����� ������ ���������� ���� �ð�
	float LeftTime;
	// �̻����� ����Ǵ� ������ �������� �ӵ�
	float FirstUpSpeed;
	// �̻����� ����Ǵ� ������ Ÿ�ٰ� �̻��� �� ��ġ�� ����
	FVector _FirstDisplacement;
	// �� ������ �� �̻����� ��ġ, �̸� ������ġ�� ��� �̻����� ������ ������.
	FVector _LocationBefore;
	
public:	
	// Sets default values for this actor's properties
	ASecondMissile();
	// �ݵ�� �������� ȣ���������. Ÿ������ ��� ���� �Ű������� �����̻��� ��� �ʿ��� �ʱ⼳���� ���ش�.
	// RealVelocity�� DroppingAccel�� ���� �⺻���� 1000,-1000����, �������Ʈ���� ���Ƿ� ������ �� �ִ�.
	UFUNCTION(BlueprintCallable,Category = "Init")
	void GoGetEm(class AEnemy* target,float RealVelocity = 1000,float DroppingAccel = -1000);
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaSeconds ) override;

};
