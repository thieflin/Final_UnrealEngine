// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinActor/Coin.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "CoinCounterC/CurrentCoinCounter.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
ACoin::ACoin()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Problema cuando compila que se me cambia de lugar capaz tendira que setear el transform. Preugntar ocmo hacerlo
	//Creo el collider y el tama;o que quiero
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Collider->SetupAttachment(GetRootComponent());
	//Lo hago trigger

	//Setteo las itnertacciones dinamicas
	
	//Collider->OnComponentEndOverlap.AddDynamic(this, &ACoin::OnOverlapEnd);



}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	//TotalCoins = Cast<ACurrentCoinCounter>(UGameplayStatics::GetActorOfClass(GetWorld(), 0));
	Super::BeginPlay();

	Collider->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnOverlapBegin);
	




}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoin::GetCoin()
{
	TotalCoins->UpdateCoins(coin);
}

int ACoin::ReturnMyCoins()
{
	return TotalCoins->UpdateCoinText();
}

//Funciona a la hora de tocarlo
void ACoin::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (TotalCoins) {
		GetCoin();
		Destroy();
		UGameplayStatics::PlaySound2D(GetWorld(), coinSound);
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "no Toy agarrando coin");
	}

}
