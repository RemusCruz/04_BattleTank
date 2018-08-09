// Fill out your copyright notice in the Description page of Project Settings.


#include "AITankController.h"
#include "Tank.h"
// Depends on movement component via pathfinding system

void AAITankController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAITankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank))
	{
		// TODO Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius, true, true, false, 0, true);

		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//ControlledTank->Fire(); // TODO limit firing rate
	}
}

