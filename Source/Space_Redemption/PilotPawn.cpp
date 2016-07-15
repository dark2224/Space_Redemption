// Fill out your copyright notice in the Description page of Project Settings.

#include "Space_Redemption.h"
#include "PilotPawn.h"


// Sets default values
APilotPawn::APilotPawn()
{
	//Math_IP::Elbowposition(FVector(100, 0, 0), FVector(0, 0, 0), 100, 100);
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	BodyMesh->SetOnlyOwnerSee(true);
	BodyMesh->bCastDynamicShadow = false;
	BodyMesh->CastShadow = false;

	/*HandMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hands"));
	HandMesh->SetupAttachment(BodyMesh);
	HandMesh->RelativeLocation = FVector(1.18f, -0.82f, 0.02f);*/

	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(BodyMesh);
	FirstPersonCameraComponent->RelativeLocation = FVector(-12.75f, 0, 99.151726f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// ��¥ �����̴� ��
	RealArm = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RealArms"));
	RealArm->SetupAttachment(BodyMesh);

	//��¥ �����̴� ����
	RealBody = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RealBody"));
	RealBody->SetupAttachment(BodyMesh);

	// �޼� ���̺� ��Ʈ�ѷ� ��ġ
	RightHand = CreateDefaultSubobject<UHand>(TEXT("RealWorld_RightHand"));
	//Dev_HandMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DevLeftHand"));
	//Dev_HandMesh->SetupAttachment(RealArm);

	// �Ӹ��� HMD ��ġ
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
	}
	else
		Hand_move_dirvec.X = 30000;
	//Hand_move_dirvec /= (float)Hand_move_dirvec.Size();
	RightHand->AddLocalOffset(Hand_move_dirvec * 1);
}

// Called to bind functionality to input
void APilotPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("XaxisLook", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("YaxisLook", this, &APawn::AddControllerPitchInput);
	//���� ����� Dev ���� �Լ��� �˴� ��Ȱ��ȭ�Ͻÿ�.
	InputComponent->BindAxis("HandX");
	InputComponent->BindAxis("HandY");
	InputComponent->BindAxis("HandZ");
}