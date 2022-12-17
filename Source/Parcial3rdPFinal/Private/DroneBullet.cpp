// Fill out your copyright notice in the Description page of Project Settings.


#include "DroneBullet.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "HealthComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
ADroneBullet::ADroneBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	PrimaryActorTick.bCanEverTick = true;
	bulletDmg = 10;
	MeshBullet = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBullet"));
	MeshCarcaza = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshCarcaza"));
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = BoxCollider;
	

}

// Called when the game starts or when spawned
void ADroneBullet::BeginPlay()
{
	Super::BeginPlay();
	MeshBullet->SetupAttachment(GetRootComponent());
	MeshCarcaza->SetupAttachment(GetRootComponent());
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ADroneBullet ::NewOverlapEvent);
	
}

// Called every frame
void ADroneBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Funciona a la hora de tocarlo
