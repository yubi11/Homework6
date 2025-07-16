// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Goal.generated.h"

class UBoxComponent;

UCLASS()
class HOMEWORK6_API AGoal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    // ��Ʈ ������Ʈ (��)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Goal")
    USceneComponent* Scene;
    // �浹 ������Ʈ (�÷��̾� ���� ���� ������)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Goal")
    UBoxComponent* Collision;
    // ������ �ð� ǥ���� ����ƽ �޽�
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Goal")
    UStaticMeshComponent* StaticMesh;
	
	UFUNCTION()
	void OnOverlapGoal(
		UPrimitiveComponent* OverlappedComponent, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep, 
		const FHitResult& SweepResult);

};
