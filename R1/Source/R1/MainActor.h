

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "R1Actor.h"
#include "MainActor.generated.h"

struct MyVector
{
public:
	double X;
	double Y;
	double Z;

	// 크기
	// Length, Size
	// sqrt(X*X + Y*Y + Z*Z);

	// 방향
	// Normalize
	// (X / sqrt(Length), Y / sqrt(Length), Z / sqrt(Length))
};

UCLASS()
class R1_API AMainActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	TObjectPtr<AR1Actor> Actor;

	TSubclassOf<AR1Actor> ActorClass; // BP_R1Actor
};
