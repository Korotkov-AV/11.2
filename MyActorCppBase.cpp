// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorCppBase.h"

// Sets default values
AMyActorCppBase::AMyActorCppBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Frequency = 4.0f;
	Amplitude = 70.0f;
}

// Called when the game starts or when spawned
void AMyActorCppBase::BeginPlay()
{
	Super::BeginPlay();
	
	InitialLocation = GetTransform().GetLocation();
}

void AMyActorCppBase::SinMovement()
{
	InitialLocation.Z += FMath::Sin(GetWorld()->GetTimeSeconds()* Frequency)*Amplitude;
	SetActorLocation(InitialLocation);
}

// Called every frame
void AMyActorCppBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

