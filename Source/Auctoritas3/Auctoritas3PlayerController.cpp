// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Auctoritas3PlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "AuctoritasPlayer.h"
#include "Engine/World.h"
#include "Auctoritas3.h"
#include "Engine/LocalPlayer.h"

AAuctoritas3PlayerController::AAuctoritas3PlayerController(const FObjectInitializer& ObjectInitializer)
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bEnableTouchEvents = true;
	bEnableTouchOverEvents = true;
	//DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AAuctoritas3PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	//// keep updating the destination every tick while desired
	//if (bMoveToMouseCursor)
	//{
	//	MoveToMouseCursor();
	//}
}

void AAuctoritas3PlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	//InputComponent->BindAxis("MoveForward", this, &AAuctoritas3PlayerController::OnMoveForwardAxis);
	//InputComponent->BindAxis("MoveRight", this, &AAuctoritas3PlayerController::OnMoveRightAxis);
	//InputComponent->BindAxis("MouseHorizontal", this, &AAuctoritas3PlayerController::OnMouseHorizontal);
	//InputComponent->BindAxis("MouseVertical", this, &AAuctoritas3PlayerController::OnMouseVertical);
	//InputComponent->BindAction("ZoomIn", EInputEvent::IE_Pressed, this, &AAuctoritas3PlayerController::OnZoomInAction);
	//InputComponent->BindAction("ZoomOut", EInputEvent::IE_Pressed, this, &AAuctoritas3PlayerController::OnZoomOutAction);
	//InputComponent->BindAction("LookAround", EInputEvent::IE_Pressed, this, &AAuctoritas3PlayerController::OnLookAroundStart);
	//InputComponent->BindAction("LookAround", EInputEvent::IE_Released, this, &AAuctoritas3PlayerController::OnLookAroundStop);

	//InputComponent->BindAction("SetDestination", IE_Pressed, this, &AAuctoritas3PlayerController::OnSetDestinationPressed);
	//InputComponent->BindAction("SetDestination", IE_Released, this, &AAuctoritas3PlayerController::OnSetDestinationReleased);
	//
	//// support touch devices 
	//InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AAuctoritas3PlayerController::MoveToTouchLocation);
	//InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AAuctoritas3PlayerController::MoveToTouchLocation);
	//
	//InputComponent->BindAction("ResetVR", IE_Pressed, this, &AAuctoritas3PlayerController::OnResetVR);
}

void AAuctoritas3PlayerController::OnMoveForwardAxis(float axisValue)
{
	APawn* const Pawn = GetPawn();
	AuctoritasPlayer* character = Cast<AuctoritasPlayer>(Pawn);
	if (character)
	{
		character->MovePlayerForward(axisValue);
	}
}

void AAuctoritas3PlayerController::OnMoveRightAxis(float axisValue)
{
	APawn* const Pawn = GetPawn();
	AuctoritasPlayer* character = Cast<AuctoritasPlayer>(Pawn);
	if (character)
	{
		character->MovePlayerRight(axisValue);
	}
}

void AAuctoritas3PlayerController::OnMouseHorizontal(float axisValue)
{
	if (lookAroundEnabled)
	{
		APawn* const Pawn = GetPawn();
		Pawn->AddControllerYawInput(axisValue);
		Cast<ULocalPlayer>(Player)->ViewportClient->Viewport->SetMouse(mouseLockPositionX, mouseLockPositionY);
	}
}

void AAuctoritas3PlayerController::OnMouseVertical(float axisValue)
{
	if (lookAroundEnabled)
	{
		APawn* const Pawn = GetPawn();
		AuctoritasPlayer* character = Cast<AuctoritasPlayer>(Pawn);
		if (character)
		{
			character->RotateCameraArm(FRotator(axisValue, 0.0f, 0.0f));
		}
		Cast<ULocalPlayer>(Player)->ViewportClient->Viewport->SetMouse(mouseLockPositionX, mouseLockPositionY);
	}
}

void AAuctoritas3PlayerController::OnZoomInAction()
{
	APawn* const Pawn = GetPawn();
	AuctoritasPlayer* character = Cast<AuctoritasPlayer>(Pawn);
	if (character)
	{
		character->ChangeCameraArmLength(-1.0f);
	}
}

void AAuctoritas3PlayerController::OnZoomOutAction()
{
	APawn* const Pawn = GetPawn();
	AuctoritasPlayer* character = Cast<AuctoritasPlayer>(Pawn);
	if (character)
	{
		character->ChangeCameraArmLength(1.0f);
	}
}

void AAuctoritas3PlayerController::OnLookAroundStart()
{
	//Lock mouse cursor
	//lookAroundEnabled = true;
	//bShowMouseCursor = false;
	//mouseLockPositionX = Cast<ULocalPlayer>(Player)->ViewportClient->Viewport->GetMouseX();
	//mouseLockPositionY = Cast<ULocalPlayer>(Player)->ViewportClient->Viewport->GetMouseY();
}

void AAuctoritas3PlayerController::OnLookAroundStop()
{
	//Unlock mouse cursor
	lookAroundEnabled = false;
	bShowMouseCursor = true;
}

//void AAuctoritas3PlayerController::OnResetVR()
//{
//	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
//}
//
//void AAuctoritas3PlayerController::MoveToMouseCursor()
//{
//	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
//	{
//		if (AuctoritasPlayer* MyPawn = Cast<AuctoritasPlayer>(GetPawn()))
//		{
//			if (MyPawn->GetCursorToWorld())
//			{
//				UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
//			}
//		}
//	}
//	else
//	{
//		// Trace to see what is under the mouse cursor
//		FHitResult Hit;
//		GetHitResultUnderCursor(ECC_Visibility, false, Hit);
//
//		if (Hit.bBlockingHit)
//		{
//			// We hit something, move there
//			SetNewMoveDestination(Hit.ImpactPoint);
//		}
//	}
//}
//
//void AAuctoritas3PlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
//{
//	FVector2D ScreenSpaceLocation(Location);
//
//	// Trace to see what is under the touch location
//	FHitResult HitResult;
//	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
//	if (HitResult.bBlockingHit)
//	{
//		// We hit something, move there
//		SetNewMoveDestination(HitResult.ImpactPoint);
//	}
//}
//
//void AAuctoritas3PlayerController::SetNewMoveDestination(const FVector DestLocation)
//{
//	APawn* const MyPawn = GetPawn();
//	if (MyPawn)
//	{
//		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());
//
//		// We need to issue move command only if far enough in order for walk animation to play correctly
//		if ((Distance > 120.0f))
//		{
//			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
//		}
//	}
//}
//
//void AAuctoritas3PlayerController::OnSetDestinationPressed()
//{
//	// set flag to keep updating destination until released
//	bMoveToMouseCursor = true;
//}
//
//void AAuctoritas3PlayerController::OnSetDestinationReleased()
//{
//	// clear flag to indicate we should stop updating the destination
//	bMoveToMouseCursor = false;
//}
