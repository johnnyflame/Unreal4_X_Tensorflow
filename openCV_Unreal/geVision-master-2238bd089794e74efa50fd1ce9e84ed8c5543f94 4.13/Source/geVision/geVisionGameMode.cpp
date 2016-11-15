// Fill out your copyright notice in the Description page of Project Settings.

#include "geVision.h"
#include "geVisionGameMode.h"


AgeVisionGameMode::AgeVisionGameMode(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
    // Seems that grabbing screenshots too early crashes the engine,
    // so wait at least a second before the first screenshot is taken.
    screenshotSaveTimeCounter = 1;
    
    // The screenshot we will grab will be 480px high and 640px wide
    screen = ScreenImage(480,640);
}

void AgeVisionGameMode::StartPlay()
{
    Super::StartPlay();
    
    StartMatch();
}

// Called every frame
void AgeVisionGameMode::Tick( float DeltaTime )
{
    Super::Tick( DeltaTime );
    
    screenshotSaveTimeCounter -= DeltaTime;

    // Make sure to get a screenshot every screenShotSaveTime seconds
    if(screenshotSaveTimeCounter <= 0) {
        
        screenshotSaveTimeCounter = screenShotSaveTime;
        
        // Grab a screenshot
        screen.grab();
        
        screen.show();
    }
}



