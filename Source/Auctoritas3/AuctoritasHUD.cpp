// Fill out your copyright notice in the Description page of Project Settings.

#include "AuctoritasHUD.h"
#include "SSettlementMenu.h"

// ++ The SWeakWidget we are using
#include "Widgets/SWeakWidget.h" 

// ++ To use GEngine. You can also import just "Engine.h" but some people mention this compiles slower than this header.
#include "Runtime/Engine/Classes/Engine/Engine.h" 


AuctoritasHUD::AuctoritasHUD()
{

}

void AuctoritasHUD::BeginPlay()
{
}

int AuctoritasHUD::getInstance()
{
	//bool IsValid = false;
	//AuctoritasHUDInstance = AuctoritasHUD();

	//IsValid = true;
	return 0;
}

void AuctoritasHUD::AddSettlementMenuWidget()
{
	// So far only TSharedPtr<SMyUIWidget> has been created, now create the actual object.
	// Create a SMyUIWidget on heap, our MyUIWidget shared pointer provides handle to object
	// Widget will not self-destruct unless the HUD's SharedPtr (and all other SharedPtrs) are destroyed first.
	SettlementMenuWidget = SNew(SSettlementMenu).OwnerHUDArg(this);
	
	// Pass our viewport a weak ptr to our widget
	// Viewport's weak ptr will not give Viewport ownership of Widget
	if (GEngine)
	{
		GEngine->GameViewport->AddViewportWidgetContent(
			SNew(SWeakWidget)
			.PossiblyNullContent(SettlementMenuWidget.ToSharedRef())
		);
	}

	// Set widget's properties as visible (sets child widget's properties recursively)
	SettlementMenuWidget->SetVisibility(EVisibility::Visible);
}