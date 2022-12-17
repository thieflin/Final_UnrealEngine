// Fill out your copyright notice in the Description page of Project Settings.


#include "WinningDoor.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
AWinningDoor::AWinningDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxColl"));
	BoxCollider->SetBoxExtent(FVector(50.f, 10.f, 50.f));
	BoxCollider->SetupAttachment(GetRootComponent());
	RootComponent = BoxCollider;
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AWinningDoor::BeginPlay()
{
	Super::BeginPlay();
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AWinningDoor::NewOverlapEvent);
}

// Called every frame
void AWinningDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

