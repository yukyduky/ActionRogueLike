// Fill out your copyright notice in the Description page of Project Settings.


#include "SBlackholeProjectile.h"
#include "Components/SphereComponent.h"

// Sets default values
ASBlackholeProjectile::ASBlackholeProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASBlackholeProjectile::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SphereComp->OnComponentHit.Clear();
}

// Called when the game starts or when spawned
void ASBlackholeProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASBlackholeProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

