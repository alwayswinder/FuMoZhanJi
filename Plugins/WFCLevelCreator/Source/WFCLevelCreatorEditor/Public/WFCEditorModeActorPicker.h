// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "EdMode.h"
#include "ActorPickerMode.h"
 
DECLARE_DELEGATE(FOnActorRotate);

class FEditorViewportClient;
class FViewport;
class SWindow;

namespace EPickState
{
	enum Type
	{
		NotOverViewport,
		OverViewport,
		OverIncompatibleActor,
		OverActor,
	};
}

/**
 * Editor mode used to interactively pick actors in the level editor viewports.
 */
class FWFCEdModeActorPicker : public FEdMode
{
public:
	FWFCEdModeActorPicker();
	
	static const FEditorModeID EM_WFCManager;
	
	/** Begin FEdMode interface */
	virtual void Tick(FEditorViewportClient* ViewportClient, float DeltaTime) override;
	virtual bool MouseEnter(FEditorViewportClient* ViewportClient, FViewport* Viewport,int32 x, int32 y) override;
	virtual bool MouseLeave(FEditorViewportClient* ViewportClient, FViewport* Viewport) override;
	virtual bool MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x, int32 y) override;
	virtual bool CapturedMouseMove( FEditorViewportClient* InViewportClient, FViewport* InViewport, int32 InMouseX, int32 InMouseY )override;

	virtual bool LostFocus(FEditorViewportClient* ViewportClient, FViewport* Viewport) override;
	virtual bool InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event) override;
	virtual bool GetCursor(EMouseCursor::Type& OutCursor) const override;
	virtual bool UsesToolkits() const override;
	virtual bool IsCompatibleWith(FEditorModeID OtherModeID) const override;
	virtual void Enter() override;
	virtual void Exit() override;
	/** End FEdMode interface */

	/** Delegate used to display information about picking near the cursor */
	FText GetCursorDecoratorText() const;

	bool IsActorValid(const AActor *const Actor) const;

	/** Flag for display state */
	TWeakObjectPtr<AActor> HoveredActor;

	/** Flag for display state */
	EPickState::Type PickState;

	/** The window that owns the decorator widget */
	TSharedPtr<SWindow> CursorDecoratorWindow;

	/** Delegates used to pick actors */
	FOnActorSelected OnActorSelected;
	FOnActorRotate OnActorRotate;
	
	FOnGetAllowedClasses OnGetAllowedClasses;
	FOnShouldFilterActor OnShouldFilterActor;

private:
	bool bMouseButtonDown = false;
	bool bAltButtonDown = false;
	bool bShiftButtonDown = false;
};
