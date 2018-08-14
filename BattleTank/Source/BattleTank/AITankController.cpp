// Fill out your copyright notice in the Description page of Project Settings.


#include "AITankController.h"
#include "TankAimingComponent.h"

// Depends on movement component via pathfinding system

void AAITankController::BeginPlay()
{
	Super::BeginPlay();
}

void AAITankController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		// Subscribe our local method to the tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &AAITankController::OnPossedTankDeath);
	}
}

void AAITankController::OnPossedTankDeath()
{
	if (!ensure(GetPawn())) { return; } // TODO remove if ok
	UE_LOG(LogTemp, Warning, TEXT("Succeed"));
	GetPawn()->DetachFromControllerPendingDestroy();
}


// Called every frame
void AAITankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!PlayerTank && ControlledTank) { return; }
	{
		// TODO Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius, true, true, false, 0, true);
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		// Aim towards the player
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		if (AimingComponent->GetFiringState() == EFiringState::Locked)
		{
			AimingComponent->Fire(); // TODO fix firing
		}
	}
}

