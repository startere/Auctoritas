// Fill out your copyright notice in the Description page of Project Settings.

#include "Government.h"

Government::Government()
{
}

Government::~Government()
{
}

int Government::GetTotalSettlementIncome()
{
	int settlementIncome = 0;

	for (int32 i = 0; i != settlements.Num(); ++i)
		settlementIncome += Cast<ASettlement2>(settlements[i])->total;

	return settlementIncome;
}
