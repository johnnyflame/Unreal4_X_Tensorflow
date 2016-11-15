// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "MyProject2HUD.generated.h"

UCLASS()
class AMyProject2HUD : public AHUD
{
	GENERATED_BODY()

public:
	AMyProject2HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

