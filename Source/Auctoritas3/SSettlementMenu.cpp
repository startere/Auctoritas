// Fill out your copyright notice in the Description page of Project Settings.

#include "SSettlementMenu.h"
#include "SlateOptMacros.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SPanel.h"
#include "Widgets/Layout/SUniformGridPanel.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

// ++ This is needed in order to use the localization macro LOCTEXT
#define LOCTEXT_NAMESPACE "SSettlementMenu"
void SSettlementMenu::Construct(const FArguments& InArgs)
{
	// ++ Asign the argument to our local variable
	// name will be _OwnerHUDArg instead of OwnerHUDArg, see comments about SLATE_ARGUMENT before
	OwnerHUD = InArgs._OwnerHUDArg;

	bUseMenuOpen = false;

	FName actionName;

	ChildSlot
		.VAlign(VAlign_Bottom)
		.HAlign(HAlign_Right)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Left)
				.Padding(0, 0, 1, 0)
				[
					SNew(SButton)
					.Text(LOCTEXT("SetAsCapitalButtonText", "Set As Capital"))
					.HAlign(HAlign_Right)
					.VAlign(VAlign_Center)
					.OnClicked(this, &SSettlementMenu::UseMenuButtonClick, actionName)
				]

			+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Left)
				.Padding(0, 0, 1, 0)
				[
					SNew(SButton)
					.Text(LOCTEXT("SetTaxRateButtonText", "Set Tax Rate"))
					.HAlign(HAlign_Right)
					.VAlign(VAlign_Center)
					.OnClicked(this, &SSettlementMenu::UseMenuButtonClick, actionName)
				]

			+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Left)
				.Padding(0, 0, 1, 0)
				[
					SNew(SBox)
					.WidthOverride(75)
					[
						SNew(SEditableText)
						.Text(NSLOCTEXT("MyGame", "EnterTaxRate", "Enter tax rate here..."))
						.OnTextCommitted(this, &SSettlementMenu::SetTaxRateButtonClick)
					]
				]

			+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Left)
				.Padding(0, 0, 1, 0)
				[
					SNew(SButton)
					.Text(LOCTEXT("DetailsButtonText", "Details"))
					.HAlign(HAlign_Right)
					.VAlign(VAlign_Center)
					.OnClicked(this, &SSettlementMenu::UseMenuButtonClick, actionName)
				]

			+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Top)
				.HAlign(HAlign_Left)
				.Padding(0, 0, 1, 0)
				[
					SNew(SUniformGridPanel)
						+ SUniformGridPanel::Slot(0, 0)
						.VAlign(VAlign_Top)
						.HAlign(HAlign_Right)
						[
							SNew(SButton)
							.Text(LOCTEXT("Building1", "Building1"))
							.HAlign(HAlign_Right)
							.VAlign(VAlign_Center)
							.OnClicked(this, &SSettlementMenu::UseMenuButtonClick, actionName)
						]
					+ SUniformGridPanel::Slot(0, 1)
						.HAlign(HAlign_Right)
						[
							SNew(SButton)
							.Text(LOCTEXT("Building2", "Building2"))
							.HAlign(HAlign_Right)
							.VAlign(VAlign_Center)
							.OnClicked(this, &SSettlementMenu::UseMenuButtonClick, actionName)
						]
					+ SUniformGridPanel::Slot(0, 2)
						.HAlign(HAlign_Center)
						[
							SNew(SButton)
							.Text(LOCTEXT("Building3", "Building3"))
							.HAlign(HAlign_Right)
							.VAlign(VAlign_Center)
							.OnClicked(this, &SSettlementMenu::UseMenuButtonClick, actionName)
						]
					+ SUniformGridPanel::Slot(1, 0)
						[
							SNew(SButton)
							.Text(LOCTEXT("Building4", "Building4"))
							.HAlign(HAlign_Right)
							.VAlign(VAlign_Center)
							.OnClicked(this, &SSettlementMenu::UseMenuButtonClick, actionName)
						]
					+ SUniformGridPanel::Slot(1, 1)
						[
							SNew(SButton)
							.Text(LOCTEXT("Building5", "Building5"))
							.HAlign(HAlign_Right)
							.VAlign(VAlign_Center)
							.OnClicked(this, &SSettlementMenu::UseMenuButtonClick, actionName)
						]
					+ SUniformGridPanel::Slot(1, 2)
						[
							SNew(SButton)
							.Text(LOCTEXT("Building6", "Building6"))
							.HAlign(HAlign_Right)
							.VAlign(VAlign_Center)
							.OnClicked(this, &SSettlementMenu::UseMenuButtonClick, actionName)
						]
					]
		];

	


	/*
	ChildSlot
	[
		// Populate the widget
	];
	*/
}

void SSettlementMenu::ToggleUseMenu(bool bOpen)
{
	bUseMenuOpen = bOpen;

	if (bUseMenuOpen)
	{
		// Change the UseMenuSlot Widget to the menu
		UseMenuSlot->AttachWidget(GetUseMenu());
	}
	else
	{
		// Change the UseMenuSlot Widget to a null widget
		UseMenuSlot->DetachWidget();
	}
}

FText SSettlementMenu::GetTextValue() const
{
	FString String = "SETTLEMENTMENUTEXT";

	if (bUseMenuOpen)
	{
		return FText::FromString(String);
	}

	String = "Close";

	return FText::FromString(String);
}

TSharedRef<SWidget> SSettlementMenu::GetUseMenu()
{
	// Create menu builder. Note that you dont have to pass optional parameters!
	FMenuBuilder MenuBuilder(true, NULL);

	FName actionName;

	MenuBuilder.AddWidget(SNew(SButton)
		.Text(FText::FromString("Action"))
		.OnClicked(this, &SSettlementMenu::UseMenuButtonClick, actionName)
		, FText::GetEmpty());

	return MenuBuilder.MakeWidget();
}

FReply SSettlementMenu::UseMenuButtonClick(FName Action)
{
	UE_LOG(LogTemp, Warning, TEXT("Settlement menu clicked message."));

	if (GEngine)
	{
		FString Msg = "Menu Item Clicked: ";
		Msg.Append(Action.ToString());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, Msg);
	}

	this->SetVisibility(EVisibility::Hidden);

	return FReply::Handled();
}

void SSettlementMenu::SetTaxRateButtonClick(const FText& InText, ETextCommit::Type InCommitType) const
{
	UE_LOG(LogTemp, Warning, TEXT("Set Tax Rate Button clicked message."));

	if (GEngine)
	{
		FString Msg = "Set Tax Rate Button Clicked: " + ParentSettlement->name;
		//msg.Append(Action.ToString());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, Msg);


	}

	//return FReply::Handled();
}

void SSettlementMenu::TaxRateChosen(const FText& InText, ETextCommit::Type InCommitType) const
{
	UE_LOG(LogTemp, Warning, TEXT("TaxRateChosenCalled"));
}


// ++ We need to undefine this namespace after we finish creating the Slate widget
#undef LOCTEXT_NAMESPACE

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
