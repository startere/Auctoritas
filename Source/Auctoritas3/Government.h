// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Settlement2.h"

/**
 * 
 */
class AUCTORITAS3_API Government
{
public:
	Government();
	~Government();

	TArray<TSubclassOf<APawn>> settlements;

#pragma region Income
	int settlementIncome = GetTotalSettlementIncome();

	int diplomaticIncome;

	int plunder;

	int income = settlementIncome + diplomaticIncome + plunder;
#pragma endregion Income

#pragma region Expenditure
	int armyUpkeep;
	int armyInfrastructure;

	// Central Government bodies and officials
	int governmentUpkeep;
	int diplomaticExpenditure;

	int expenditure = governmentUpkeep + diplomaticExpenditure + armyUpkeep + armyInfrastructure;
#pragma endregion Expenditure

#pragma region Total
	int total = income - expenditure;
#pragma endregion Total

	int GetTotalSettlementIncome();
};
