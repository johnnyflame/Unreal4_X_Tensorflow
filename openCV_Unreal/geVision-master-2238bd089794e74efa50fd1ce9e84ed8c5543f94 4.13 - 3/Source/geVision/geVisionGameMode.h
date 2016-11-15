// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "ScreenImage.h"
#include "geVisionGameMode.generated.h"

/**
 * 
 */
UCLASS()
class GEVISION_API AgeVisionGameMode : public AGameMode
{
	GENERATED_BODY()
	
    AgeVisionGameMode(const FObjectInitializer& ObjectInitializer);
	virtual void StartPlay() override; 
    virtual void Tick( float DeltaSeconds ) override;

private:
    float screenShotSaveTime = 0;
    float screenshotSaveTimeCounter;
    ScreenImage screen;
};
