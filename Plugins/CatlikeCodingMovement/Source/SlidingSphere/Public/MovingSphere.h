// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingSphere.generated.h"

UCLASS()
class SLIDINGSPHERE_API AMovingSphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingSphere();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	void BindInput();

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere)
	class USphereMovementComponent* MovementComponent;
};
