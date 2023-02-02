// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if(InFireRange())
	{
		RotateTurret(Tank->GetActorLocation());
	}
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void ATower::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandle,this, &ATower::CheckFireConditions,FireRate,true);
}

void ATower::CheckFireConditions()
{
	if(InFireRange())
	{
		Fire();
	}
}

bool ATower::InFireRange()
{
	if(Tank)
	{
		FVector TankLocation = Tank->GetActorLocation();
		float fDistance = FVector::Dist(GetActorLocation(),TankLocation);

		return (fDistance <= FireRange);
	}
	return false;
}
