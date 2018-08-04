// Fill out your copyright notice in the Description page of Project Settings.

#include "AITankController.h"



void AAITankController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not posessing a tank"));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Possessing: %s"), *ControlledTank->GetName());
	}

}

ATank * AAITankController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}