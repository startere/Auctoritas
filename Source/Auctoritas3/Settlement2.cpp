// Fill out your copyright notice in the Description page of Project Settings.

#include "Settlement2.h"
#include "Kismet/KismetStringLibrary.h"
#include "AuctoritasHUD.h"
#include "SSettlementMenu.h"

// Sets default values
ASettlement2::ASettlement2()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	name = this->GetName();

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponentSettlement"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh_obj(TEXT("/Engine/BasicShapes/Cube.Cube"));
	StaticMeshComponent->SetStaticMesh(StaticMesh_obj.Object);
	//StaticMeshComponent->OnClicked.AddDynamic(this, &ASettlement2::OnClick);
	StaticMeshComponent->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ASettlement2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASettlement2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASettlement2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASettlement2::OpenSettlementDetails()
{
	UE_LOG(LogTemp, Warning, TEXT("Settlement menu open."));

	TSharedRef<SSettlementMenu> settlementMenu = SNew(SSettlementMenu);
	settlementMenu->ParentSettlement = this;

	GEngine->GameViewport->AddViewportWidgetContent(settlementMenu);
	UE_LOG(LogTemp, Warning, TEXT("Bool value is: %s"), (settlementMenu->IsEnabled() ? TEXT("true") : TEXT("false")));

	settlementMenu->SetVisibility(EVisibility::Visible);
}

void ASettlement2::SetTaxRate(int _taxRate)
{
	taxRate = _taxRate;
}

void ASettlement2::NotifyActorOnClicked(FKey ButtonPressed)
{
	OpenSettlementDetails();
}