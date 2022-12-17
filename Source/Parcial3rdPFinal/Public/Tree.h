// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tree.generated.h"

UCLASS()
class PARCIAL3RDPFINAL_API ATree : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATree();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isGoingRedDrop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isGoingRedUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isGoingBlueDrop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isGoingBlueUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float colourValue;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* Collider;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UMaterialInterface* Material;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UMaterialInstanceDynamic* dynamicMatInst;


	UFUNCTION(BlueprintCallable)
		void RedToBlueEmissiveDrop();

	UFUNCTION(BlueprintCallable)
		void RedToBlueEmissiveUp();

	UFUNCTION(BlueprintCallable)
		void BlueToRedEmissiveDrop();

	UFUNCTION(BlueprintCallable)
		void BlueToRedEmissiveUp();
};
