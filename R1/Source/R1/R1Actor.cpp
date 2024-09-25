// Fill out your copyright notice in the Description page of Project Settings.


#include "R1Actor.h"
#include "R1Object.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AR1Actor::AR1Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UStaticMeshComponent>("Box");

	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("StaticMesh'/Game/_Park/SM_ChamferCube'"));

    if (FindMesh.Succeeded())
    {
    	Box -> SetStaticMesh(FindMesh.Object);
    }
}

// Called when the game starts or when spawned
void AR1Actor::BeginPlay()
{
	Super::BeginPlay();

	// Target = UGameplayStatics::GetActorOfClass(GetWorld(), AR1Actor::StaticClass());
	// std::vector
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Park"), Actors);

	if (Actors.Num() > 0)
	{
		Target = Actors[0];
	}
}

// Called every frame
void AR1Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Target != nullptr)
	{
		float Speed = 50.f;
		float Distance = DeltaTime * Speed;
	
		FVector Location = GetActorLocation();

		FVector DirectionVector = Target->GetActorLocation() - GetActorLocation();
		DirectionVector.Normalize();
		
	
		// Unreal forward vector (1,0,0)
		// FVector NewLocation = 	Location + FVector::ForwardVector * Distance;
		// FVector NewLocation = Location + DirectionVector * Distance;
	
		// SetActorLocation(NewLocation);
		AddActorWorldOffset(DirectionVector * Distance);
	}

}

 