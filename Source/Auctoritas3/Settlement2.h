// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/PrimitiveComponent.h"
#include "Misc/MessageDialog.h"
#include "Engine/GameViewportClient.h"
#include "Editor/EditorEngine.h"

#include "Settlement2.generated.h"

UCLASS()
class AUCTORITAS3_API ASettlement2 : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASettlement2();

	FString name;

#pragma region Income
	int tradeResources;
	int tradeBuildingBonus;
	int tradeIncome				= tradeResources * tradeBuildingBonus;

	int taxRate;
	int taxBuildingBonus;
	int taxIncome				= population * taxRate * taxBuildingBonus;

	int harvestResources;
	int harvestBuildingBonus;
	int harvestIncome			= harvestResources * harvestBuildingBonus;

	int income					= tradeIncome + taxIncome + harvestIncome;
#pragma endregion Income

#pragma region Population Growth
	int population;

	int healthBuildings;
	int farmBuildings;

	int populationBuildings = healthBuildings + farmBuildings;

	int populationLocalModifier;

	int squalor = population * healthBuildings;

#pragma endregion Population Growth

#pragma region Expenditure
	int infrastructureUpkeep;

	// Local Government bodies and officials
	int governmentUpkeep;

	int expenditure				= population * (infrastructureUpkeep + governmentUpkeep);
#pragma endregion Expenditure

#pragma region Total
	int total = income - expenditure;
#pragma endregion Total

#pragma region Loyalty
	int happinessBuildingBonus;
	int loyaltyBuildingBonus;

	int happiness = happinessBuildingBonus + loyaltyBuildingBonus;
	int loyalty = income - expenditure;
#pragma endregion Loyalty

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UStaticMeshComponent* StaticMeshComponent;

	void OpenSettlementDetails();

	void SetTaxRate(int _taxRate);

	void NotifyActorOnClicked(FKey ButtonPressed) override;
};
