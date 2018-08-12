// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Tank.h" // So we can impliment OnDeath
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "AITankController.generated.h"

class UTankAimingComponent;

/**
*
*/
UCLASS()
class BATTLETANK_API AAITankController : public AAIController
{
	GENERATED_BODY()

public:

	UFUNCTION()
	void OnPossedTankDeath();

protected:

	// How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float AcceptanceRadius = 8000;

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	void SetPawn(APawn* InPawn);



};