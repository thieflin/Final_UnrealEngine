	// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"

// Sets default values
ATree::ATree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Collider->SetupAttachment(GetRootComponent());
	isGoingBlueUp = false;
	isGoingRedUp = false;
	isGoingRedDrop = false;
	isGoingBlueDrop = true;
}

// Called when the game starts or when spawned
void ATree::BeginPlay()
{
	Super::BeginPlay();

	Material = Mesh->GetMaterial(0);
	dynamicMatInst = UMaterialInstanceDynamic::Create(Material, this);
	Mesh->SetMaterial(0, dynamicMatInst);
	dynamicMatInst->SetScalarParameterValue(TEXT("EmissiveStrength"), 80);
	dynamicMatInst->SetVectorParameterValue(TEXT("Colour"), FLinearColor::Red);
	
}





// Called every frame
void ATree::Tick(float DeltaTime)
{
	RedToBlueEmissiveDrop();
	RedToBlueEmissiveUp();
	BlueToRedEmissiveDrop();
	BlueToRedEmissiveUp();

}

void ATree::RedToBlueEmissiveDrop()
{
	if (isGoingBlueDrop) {
		colourValue--;
		dynamicMatInst->SetScalarParameterValue(TEXT("EmissiveStrength"), colourValue);
		if (colourValue <= 0) {
			dynamicMatInst->SetVectorParameterValue(TEXT("Colour"), FLinearColor::Blue);
			isGoingBlueUp = true;
			isGoingBlueDrop = false;
		}
	}
}

void ATree::RedToBlueEmissiveUp()
{
	if (isGoingBlueUp) {
		colourValue++;
		dynamicMatInst->SetScalarParameterValue(TEXT("EmissiveStrength"), colourValue);
		if (colourValue >= 80) {
			isGoingRedDrop = true;
			isGoingBlueUp = false;
		}
	}
}

void ATree::BlueToRedEmissiveDrop()
{
	if (isGoingRedDrop) {
		colourValue--;
		dynamicMatInst->SetScalarParameterValue(TEXT("EmissiveStrength"), colourValue);
		if (colourValue <= 0) {
			dynamicMatInst->SetVectorParameterValue(TEXT("Colour"), FLinearColor::Red);
			isGoingRedUp = true;
			isGoingRedDrop = false;
		}
	}
}

void ATree::BlueToRedEmissiveUp()
{
	if (isGoingRedUp) {
		colourValue++;
		dynamicMatInst->SetScalarParameterValue(TEXT("EmissiveStrength"), colourValue);
		if (colourValue >= 80) {
			isGoingBlueDrop = true;
			isGoingRedUp = false;
		}
	}
}

