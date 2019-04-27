// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuctoritasHUD.generated.h"

/**
 * 
 */

 // ++ A predeclaration of SStandardSlateWidget that we need. The .h will be added to .cpp instead.
class SSettlementMenu;

UCLASS()
class AUCTORITAS3_API AuctoritasHUD : public AHUD
{
	GENERATED_BODY()

	// ++ Reference to an SCompoundWidget, TSharedPtr adds to the refcount of MyUIWidget
	// MyUIWidget will not self-destruct as long as refcount > 0. refcount will be (refcout-1) if HUD is destroyed.
	TSharedPtr<SSettlementMenu> SettlementMenuWidget;

	// ++ Called as soon as game starts, create SCompoundWidget and give Viewport access
	void BeginPlay();

	static AuctoritasHUD* ModuleManager;
public:	
	AuctoritasHUD();

	static int getInstance();

	void AddSettlementMenuWidget();

private:
	static AuctoritasHUD AuctoritasHUDInstance;
};
