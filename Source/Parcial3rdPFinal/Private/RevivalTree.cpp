// Fill out your copyright notice in the Description page of Project Settings.


#include "RevivalTree.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"

// Sets default values
ARevivalTree::ARevivalTree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Collider->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ARevivalTree::BeginPlay()
{
	Super::BeginPlay();

	Collider->OnComponentBeginOverlap.AddDynamic(this, &ARevivalTree::NewOverlapEvent);

	Material = Mesh->GetMaterial(0);
	dynamicMatInst = UMaterialInstanceDynamic::Create(Material, this);
	Mesh->SetMaterial(0, dynamicMatInst);
	dynamicMatInst->SetScalarParameterValue(TEXT("EmissiveStrength"), 0);
	dynamicMatInst->SetVectorParameterValue(TEXT("Colour"), FLinearColor::Red);
}

// Called every frame
void ARevivalTree::Tick(float DeltaTime)
{
	ChangeColour();

}

void ARevivalTree::ChangeColour() {
	if (collidedWithTree) {
		colourValue++;
		dynamicMatInst->SetScalarParameterValue(TEXT("EmissiveStrength"), colourValue);
		if (colourValue >= 80) {
			dynamicMatInst->SetVectorParameterValue(TEXT("Colour"), FLinearColor::Blue);
			collidedWithTree = false;
		}
	}
}

