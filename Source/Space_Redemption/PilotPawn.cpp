// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "PilotPawn.h"


// Sets default values
APilotPawn::APilotPawn()
{
	//Math_IP::Elbowposition(FVector(100, 0, 0), FVector(0, 0, 0), 100, 100);
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Origin = CreateDefaultSubobject<USceneComponent>(TEXT("Origin"));

	/*HandMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hands"));
	HandMesh->SetupAttachment(BodyMesh);
	HandMesh->RelativeLocation = FVector(1.18f, -0.82f, 0.02f);*/

	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(Origin);
	FirstPersonCameraComponent->RelativeLocation = FVector(-32.75f, 0, 99.151726f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = false;

	// 진짜 움직이는 팔
	RightArm = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RightArm"));
	RightArm->SetupAttachment(Origin);

	RightRealHandScene = CreateDefaultSubobject<USceneComponent>(TEXT("RightRealHandScene"));
	RightShoulderScene = CreateDefaultSubobject<USceneComponent>(TEXT("RightShoulder"));
	RightShoulderScene->SetupAttachment(RightArm);

	//진짜 움직이는 몸통
	//RealBody = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RealBody"));
	//RealBody->SetupAttachment(BodyMesh);

	// 오른손, 이 손의 트랜스폼은 가상세계에 반영되는 플레이어 오른손의 위치와 같다.
	RightHand = CreateDefaultSubobject<UHand>(TEXT("RealWorld_RightHand"));
	RightHand->SetupAttachment(RightArm);
	RightHand->DefaultSet(RightShoulderScene, RightRealHandScene);
	RightHand->SetRelativeLocation(FVector(0, 0, 0));
	RightHand->SetRelativeRotation(FQuat(FRotator(0, 0, 0)));
	//Dev_HandMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DevLeftHand"));
	//Dev_HandMesh->SetupAttachment(RightArm);

	LeftArm = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LeftArm"));
	LeftArm->SetupAttachment(Origin);

	LeftRealHandScene = CreateDefaultSubobject<USceneComponent>(TEXT("LeftRealHandScene"));
	LeftShoulderScene = CreateDefaultSubobject<USceneComponent>(TEXT("LeftShoulder"));
	LeftShoulderScene->SetupAttachment(LeftArm);

	LeftHand = CreateDefaultSubobject<UHand>(TEXT("RealWorld_LeftHand"));
	LeftHand->SetupAttachment(LeftArm);
	LeftHand->DefaultSet(LeftShoulderScene, LeftRealHandScene);
	LeftHand->SetRelativeLocation(FVector(0, 0, 0));
	LeftHand->SetRelativeRotation(FQuat(FRotator(0, 0, 0)));

	// 머리통 HMD 위치
	Dev_HeadMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HeadMesh"));


	Hand_move_dirvec = FVector(10.0f, 0.0f, 0.0f);

}
// Called when the game starts or when spawned
void APilotPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APilotPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//InputComponent->GetAxisValue("HandX");
	Hand_move_dirvec.X = 3;

	if (InputComponent)
	{
		//InputComponent->GetAxisValue("HandX");
		Hand_move_dirvec.X = InputComponent->GetAxisValue("HandX");
		Hand_move_dirvec.Y = InputComponent->GetAxisValue("HandY");
		Hand_move_dirvec.Z = InputComponent->GetAxisValue("HandZ");
		InputComponent->GetAxisValue("RightGrasp") > 0 ? RightHand->MakeGrabAvailable() : RightHand->MakeGrabUnable();
		InputComponent->GetAxisValue("LeftGrasp") > 0 ? LeftHand->MakeGrabAvailable() : LeftHand->MakeGrabUnable();
		InputComponent->GetAxisValue("LeftSecondaryGrasp") > 0 ? LeftHand->MakeSecondaryGraspAvailable() : LeftHand->MakeSecondaryGraspUnable();
		InputComponent->GetAxisValue("RightSecondaryGrasp") > 0 ? RightHand->MakeSecondaryGraspAvailable() : RightHand->MakeSecondaryGraspUnable();
	}
	else
		Hand_move_dirvec.X = 30000;
	//Hand_move_dirvec /= (float)Hand_move_dirvec.Size();
	RightArm->SetRelativeLocation(FirstPersonCameraComponent->RelativeLocation + RelativeArmposition);
	LeftArm->SetRelativeLocation(FirstPersonCameraComponent->RelativeLocation + RelativeArmposition);

	LeftRealHandScene->AddLocalOffset(FVector(InputComponent->GetAxisValue("LeftHandX"), InputComponent->GetAxisValue("LeftHandY"), InputComponent->GetAxisValue("LeftHandZ")));
	RightRealHandScene->AddLocalOffset(Hand_move_dirvec * 1);
	FirstPersonCameraComponent->AddRelativeRotation(FRotator(-InputComponent->GetAxisValue("YaxisLook"), InputComponent->GetAxisValue("XaxisLook"), 0));
}

// Called to bind functionality to input
void APilotPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("XaxisLook");
	InputComponent->BindAxis("YaxisLook");
	//정식 빌드시 Dev 들어가는 함수는 죄다 비활성화하시오.
	InputComponent->BindAxis("HandX");
	InputComponent->BindAxis("HandY");
	InputComponent->BindAxis("HandZ");
	InputComponent->BindAxis("LeftHandX");
	InputComponent->BindAxis("LeftHandY");
	InputComponent->BindAxis("LeftHandZ");
	InputComponent->BindAxis("LeftSecondaryGrasp");
	InputComponent->BindAxis("RightSecondaryGrasp");
	InputComponent->BindAxis("LeftGrasp");
	InputComponent->BindAxis("RightGrasp");
}