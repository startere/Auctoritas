// Fill out your copyright notice in the Description page of Project Settings.

#include "Settlement.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASettlement::ASettlement()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ASettlement::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASettlement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASettlement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//InputComponent->BindAction("OpenSettlementDetails", IE_Pressed, this, &ASettlement::OpenSettlementDetails);
}

void ASettlement::OpenSettlementDetails() 
{
	UE_LOG(LogTemp, Warning, TEXT("CLICK HANDLER CALLED."));
}