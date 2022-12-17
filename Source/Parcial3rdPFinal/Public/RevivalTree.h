// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RevivalTree.generated.h"

UCLASS()
class PARCIAL3RDPFINAL_API ARevivalTree : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARevivalTree();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool collidedWithTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float colourValue;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* Collider;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UMaterialInterface* Material;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UMaterialInstanceDynamic* dynamicMatInst;

	UFUNCTION(BlueprintCallable)
		void ChangeColour();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void NewOverlapEvent(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
