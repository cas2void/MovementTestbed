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

	float ForwardValue = GetOwner()->GetInputAxisValue(ForwardAxis);
	float RightValue = GetOwner()->GetInputAxisValue(RightAxis);
	FVector InputVector(ForwardValue, RightValue, 0.0f);

	FVector DesiredVelocity = InputVector.GetClampedToSize(0.0f, 1.0f) * MaxSpeed;
	float MaxSpeedChange = MaxAcceleration * DeltaTime;

	if (Velocity.X < DesiredVelocity.X)
	{
		Velocity.X = FMath::Min(Velocity.X + MaxSpeedChange, DesiredVelocity.X);
	}
	else if (Velocity.X > DesiredVelocity.X)
	{
		Velocity.X = FMath::Max(Velocity.X - MaxSpeedChange, DesiredVelocity.X);
	}

	if (Velocity.Y < DesiredVelocity.Y)
	{
		Velocity.Y = FMath::Min(Velocity.Y + MaxSpeedChange, DesiredVelocity.Y);
	}
	else if (Velocity.Y > DesiredVelocity.Y)
	{
		Velocity.Y = FMath::Max(Velocity.Y - MaxSpeedChange, DesiredVelocity.Y);
	}

	FVector LocationOffset = Velocity * DeltaTime;
	GetOwner()->AddActorWorldOffset(LocationOffset);
}

void USphereMovementComponent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (PlayerInputComponent)
	{
		PlayerInputComponent->BindAxis(ForwardAxis);
		PlayerInputComponent->BindAxis(RightAxis);
	}
}