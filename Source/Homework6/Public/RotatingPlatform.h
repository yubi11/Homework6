// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class HOMEWORK6_API ARotatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Platform")
	USceneComponent* Scene;

	// ȸ�� ���� �޽� ������Ʈ
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Platform")
	UStaticMeshComponent* StaticMesh;

	// �ʴ� ȸ�� ���� (deg/sec)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Settings")
	FRotator RotateSpeed;

};
