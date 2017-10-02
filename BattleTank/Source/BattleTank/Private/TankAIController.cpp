// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI - Controlled tank not found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI - Controlled tank is %s"), *ControlledTank->GetName());
	}
	PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI - Player tank not found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI - Player tank is %s"), *PlayerTank->GetName());
	}

}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ControlledTank && PlayerTank)
	{
		//Move towards player
		//Aim at player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		//Fire if ready
	}
}
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


