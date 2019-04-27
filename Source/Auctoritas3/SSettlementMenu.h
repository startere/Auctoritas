// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/SOverlay.h"
#include "Settlement2.h"

/**
 * 
 */
class AUCTORITAS3_API SSettlementMenu : public SCompoundWidget
{
protected:
	FText GetTextValue() const;

	bool bUseMenuOpen;

public:
	SLATE_BEGIN_ARGS(SSettlementMenu)
	{}

	// ++ We add a new argument called OwnerHUDArg
	SLATE_ARGUMENT(TWeakObjectPtr<class AuctoritasHUD>, OwnerHUDArg);

	SLATE_END_ARGS()

	ASettlement2* ParentSettlement;

	/** Constructs this widget with InArgs */ // Constructs this widget with InArgs. Needed for every widget. Builds this widget and any of it's children
	void Construct(const FArguments& InArgs);

	void ToggleUseMenu(bool bOpen);

private:
	// ++ Pointer to our parent HUD. To make sure HUD's lifetime is controlled elsewhere, use "weak" ptr.
	// ++ HUD has a "strong" pointer to Widget, circular ownership would prevent/break self-destruction of hud/widget (cause a memory leak).
	TWeakObjectPtr<class AuctoritasHUD> OwnerHUD;

	TSharedRef<SWidget> GetUseMenu();
	SOverlay::FOverlaySlot* HelpTextSlot;
	SOverlay::FOverlaySlot* UseMenuSlot;

	//Start  button callback 
	FReply UseMenuButtonClick(FName Action);

	//Set tax rate button callback 
	void SetTaxRateButtonClick(const FText& InText, ETextCommit::Type InCommitType) const;

	//Enter tax rate callback 
	void TaxRateChosen(const FText& InText, ETextCommit::Type InCommitType) const;
};
