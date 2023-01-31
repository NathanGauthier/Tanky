// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(Tank)
	{
		FVector TankLocation = Tank->GetActorLocation();
		float fDistance = FVector::Dist(GetActorLocation(),TankLocation);

		if(fDistance <= FireRange)
		{
			RotateTurret(TankLocation);
		}
	}
}

void ATower::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
}
