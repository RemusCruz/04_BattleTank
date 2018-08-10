// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	// How close can AI get to player
	UPROPERTY(EditAnyWhere, Category = "Setup")
	float AcceptanceRadius = 80000;

};