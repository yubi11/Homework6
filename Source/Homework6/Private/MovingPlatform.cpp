// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
    SetRootComponent(Scene);

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMesh->SetupAttachment(Scene);

    Direction = FVector(1, 0, 0);
    Speed = 200.f;
    Range = 500.f;
    bMovingForward = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

    StartLocation = GetActorLocation();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector MoveStep = Direction.GetSafeNormal() * Speed * DeltaTime; //�� �����Ӵ� �̵� �Ÿ� ����*�ӵ�*DeltaTime
    FVector NextLocation = GetActorLocation() + (bMovingForward ? MoveStep : -MoveStep);
    FVector HalfDist = NextLocation - StartLocation;

	float ForwardDistance = HalfDist.X * Direction.X + HalfDist.Y * Direction.Y + HalfDist.Z * Direction.Z; // -100~100 �̷� ���� �ƴ� 0~100���� �����̰� ����

    if (ForwardDistance >= Range)
    {
        bMovingForward = false;
    }
    else if (ForwardDistance <= 0)
    {
        bMovingForward = true;
	}
        SetActorLocation(NextLocation);

}

