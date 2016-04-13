// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "VREditorGizmoHandle.h"
#include "VREditorTranslationGizmoHandle.generated.h"

/**
 * Gizmo handle for translating
 */
UCLASS()
class UVREditorTranslationGizmoHandleGroup : public UVREditorGizmoHandleGroup
{
	GENERATED_BODY()

public:

	/** Default constructor that sets up CDO properties */
	UVREditorTranslationGizmoHandleGroup();
	
	/** Updates the gizmo handles */
	virtual void UpdateGizmoHandleGroup( const FTransform& LocalToWorld, const FBox& LocalBounds, const FVector ViewLocation, bool bAllHandlesVisible, class UActorComponent* DraggingHandle, const TArray< UActorComponent* >& HoveringOverHandles, float AnimationAlpha, float GizmoScale, const float GizmoHoverScale, const float GizmoHoverAnimationDuration, bool& bOutIsHoveringOrDraggingThisHandleGroup ) override;
	
	/** Gets the InteractionType for this Gizmo handle */
	virtual ETransformGizmoInteractionType GetInteractionType() const override;

	/** Gets the GizmoType for this Gizmo handle */
	virtual EGizmoHandleTypes GetHandleType() const override;
};
