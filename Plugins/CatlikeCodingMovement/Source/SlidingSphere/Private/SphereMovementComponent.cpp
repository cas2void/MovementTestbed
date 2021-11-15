// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereMovementComponent.h"

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
}

void USphereMovementComponent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (PlayerInputComponent)
	{
		PlayerInputComponent->BindAxis("MoveForward", this, &USphereMovementComponent::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight", this, &USphereMovementComponent::MoveRight);
	}
}

void USphereMovementComponent::MoveForward(float Value)
{
	FVector Location = GetOwner()->GetActorLocation();
	GetOwner()->SetActorLocation(FVector(MoveRadius * Value, Location.Y, Location.Z));
}

void USphereMovementComponent::MoveRight(float Value)
{
	FVector Location = GetOwner()->GetActorLocation();
	GetOwner()->SetActorLocation(FVector(Location.X, MoveRadius * Value, Location.Z));
}