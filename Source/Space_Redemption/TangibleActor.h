/*
������ ������ ��ȣ�ۿ��� �� �ִ� ��ü���� �θ� Ŭ�����Դϴ�.
*/
#pragma once

#include "GameFramework/Actor.h"
#include "TangibleActor.generated.h"

UCLASS()
class SPACE_REDEMPTION_API ATangibleActor : public AActor
{
	GENERATED_BODY()
protected:
	// �޽��� ���� ���� ����� ��ġ�� ������ �����մϴ�. Set�޼��带 ���� �������Ʈ�󿡼� �ʱ�ȭ����� �մϴ�.
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent *DesiredHandTransform;
	// ���� ������Ʈ�� �ٰ��� �� ȣ��Ǵ� �Լ��Դϴ�. ȣ��Ǿ��� �� ���� ��ȣ�ۿ��� ���������� ������
	// ���� ������Ʈ�� ��������� ���� �ִϸ��̼��� ��ȣ�ۿ� idle �ִϸ��̼����� �����˴ϴ�.
	UFUNCTION(BlueprintCallable, Category = "Updatingstat")
		virtual void Beingapproached(class UHand* param) {}
	// �հ� ������Ʈ�� ��ȣ�ۿ��� �����ؾ� �Ҷ� ȣ��˴ϴ�. �̶����� �հ� ������Ʈ�� ���� �� �ٰ� �˴ϴ�.
	UFUNCTION(BlueprintCallable, Category = "Updatingstat")
		virtual void StartInteraction(class UHand* param) {}
	// �հ� ������Ʈ�� ��ȣ�ۿ��� ����� �� �� ȣ��˴ϴ�. �հ� ������Ʈ�� �̶����� ���� �����˴ϴ�.
	UFUNCTION(BlueprintCallable, Category = "Updatingstat")
		virtual void QuitInteraction(class UHand* param) {}
	// �� ��ġ�� ���� ����
	UFUNCTION(BlueprintCallable, Category = "InitializationRequired")
		void SetDesiredHandTransform(USceneComponent* param) { DesiredHandTransform = param; }
public:
	// Sets default values for this actor's properties
	ATangibleActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	virtual class USceneComponent* GetDesiredHandTransform() { return DesiredHandTransform; }

};
