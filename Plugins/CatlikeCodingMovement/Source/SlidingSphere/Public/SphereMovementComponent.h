// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "SphereMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLIDINGSPHERE_API USphereMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USphereMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Movement
public:
	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

	void MoveForward(float Value);

	void MoveRight(float Value);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveRadius = 200.0f;
};
