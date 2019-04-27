// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Auctoritas3PlayerController.generated.h"

UCLASS()
class AAuctoritas3PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuctoritas3PlayerController(const FObjectInitializer& ObjectInitializer);

	// Input handlers
	void OnMoveForwardAxis(float axisValue);

	void OnMoveRightAxis(float axisValue);

	void OnMouseHorizontal(float axisValue);

	void OnMouseVertical(float axisValue);

	void OnZoomInAction();

	void OnZoomOutAction();

	void OnLookAroundStart();

	void OnLookAroundStop();

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	//uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	///** Resets HMD orientation in VR. */
	//void OnResetVR();
	//
	///** Navigate player to the current mouse cursor location. */
	//void MoveToMouseCursor();
	//
	///** Navigate player to the current touch location. */
	//void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	//
	///** Navigate player to the given world location. */
	//void SetNewMoveDestination(const FVector DestLocation);
	//
	///** Input handlers for SetDestination action. */
	//void OnSetDestinationPressed();
	//void OnSetDestinationReleased();

private:
	bool lookAroundEnabled = false;
	int32 mouseLockPositionX;
	int32 mouseLockPositionY;
};


