// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingSphere.h"

#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"

#include "SphereMovementComponent.h"

// Sets default values
AMovingSphere::AMovingSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Mesh")));
	RootComponent = MeshComponent;

	MovementComponent = CreateDefaultSubobject<USphereMovementComponent>(FName(TEXT("Movement")));
}

// Called when the game starts or when spawned
void AMovingSphere::BeginPlay()
{
	Super::BeginPlay();

	BindInput();
}

// Called every frame
void AMovingSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMovingSphere::BindInput()
{
	EnableInput(GetWorld()->GetFirstPlayerController());
	MovementComponent->SetupPlayerInputComponent(InputComponent);
}