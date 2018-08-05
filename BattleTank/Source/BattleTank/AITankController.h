// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "AITankController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API AAITankController : public AAIController
{
	GENERATED_BODY()

public:

	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank * GetControlledTank() const;

	ATank* GetPlayerTank() const;



};
