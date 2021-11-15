// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereMovementComponent.h"

static FName ForwardAxis("MoveForward");
static FName RightAxis("MoveRight");

// Sets default values for this component's properties
USphereMovementComponent::USphereMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USphereMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void USphereMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	float ForwardValue = GetOwner()->GetInputAxisValue(ForwardAxis);
	float RightValue = GetOwner()->GetInputAxisValue(RightAxis);
	FVector InputVector(ForwardValue, RightValue, 0.0f);
	FVector TargetLocation = InputVector.GetClampedToSize(0.0f, 1.0f) * MoveRadius;

	FVector Location = GetOwner()->GetActorLocation();
	GetOwner()->SetActorLocation(FVector(TargetLocation.X, TargetLocation.Y, Location.Z));
}

void USphereMovementComponent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (PlayerInputComponent)
	{
		PlayerInputComponent->BindAxis(ForwardAxis);
		PlayerInputComponent->BindAxis(RightAxis);
	}
}