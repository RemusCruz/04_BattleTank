// Fill out your copyright notice in the Description page of Project Settings.

#include "AITankController.h"



void AAITankController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController cant find tank"));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *ControlledTank->GetName());
	}

}

ATank * AAITankController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* AAITankController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; } // Note the !, very important
	return Cast<ATank>(PlayerPawn);
}

