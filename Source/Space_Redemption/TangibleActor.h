/*
손으로 만지고 상호작용할 수 있는 물체들의 부모 클래스입니다.
*/
#pragma once

#include "GameFramework/Actor.h"
#include "TangibleActor.generated.h"

UCLASS()
class SPACE_REDEMPTION_API ATangibleActor : public AActor
{
	GENERATED_BODY()
protected:
	// 메쉬에 대한 손의 상대적 위치와 각도를 저장합니다. Set메서드를 통해 블루프린트상에서 초기화해줘야 합니다.
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent *DesiredHandTransform;
	// 손이 오브젝트에 다가갈 때 호출되는 함수입니다. 호출되었을 때 손이 상호작용을 시작하지는 않지만
	// 손이 오브젝트에 가까워짐에 따라 애니메이션이 상호작용 idle 애니메이션으로 블렌딩됩니다.
	UFUNCTION(BlueprintCallable, Category = "Updatingstat")
		virtual void Beingapproached(class UHand* param) {}
	// 손과 오브젝트가 상호작용을 시작해야 할때 호출됩니다. 이때부터 손과 오브젝트는 서로 딱 붙게 됩니다.
	UFUNCTION(BlueprintCallable, Category = "Updatingstat")
		virtual void StartInteraction(class UHand* param) {}
	// 손과 오브젝트가 상호작용을 멈춰야 할 때 호출됩니다. 손과 오브젝트는 이때부터 서로 독립됩니다.
	UFUNCTION(BlueprintCallable, Category = "Updatingstat")
		virtual void QuitInteraction(class UHand* param) {}
	// 손 위치에 대한 세터
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
