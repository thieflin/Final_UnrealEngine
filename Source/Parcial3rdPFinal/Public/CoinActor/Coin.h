// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coin.generated.h"

UCLASS()
class PARCIAL3RDPFINAL_API ACoin : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int coin;

	UPROPERTY(EditAnywhere)
		 class ACurrentCoinCounter* TotalCoins;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* Mesh;


	UPROPERTY(EditAnywhere)
		class UBoxComponent* Collider;

	UFUNCTION()
		void GetCoin();

	UFUNCTION(BlueprintCallable)
		int ReturnMyCoins();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USoundBase* coinSound;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};