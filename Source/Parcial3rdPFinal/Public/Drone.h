// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Drone.generated.h"

UCLASS()
class PARCIAL3RDPFINAL_API ADrone : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADrone();

	//Variable de a que wp va a ir mi torretita
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class ATargetPoint* targetElement;
		

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* MeshDrone;


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
