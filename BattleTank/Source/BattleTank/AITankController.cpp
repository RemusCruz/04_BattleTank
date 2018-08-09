// Fill out your copyright notice in the Description page of Project Settings.


#include "AITankController.h"
#include "TankAimingComponent.h"

// Depends on movement component via pathfinding system

void AAITankController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAITankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	{
		// TODO Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius, true, true, false, 0, true);
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		// Aim towards the player
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		AimingComponent->Fire(); // TODO fix firing
	}
}

