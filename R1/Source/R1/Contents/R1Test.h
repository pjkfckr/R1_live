

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "R1Test.generated.h"

UCLASS()
class R1_API AR1Test : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AR1Test();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
