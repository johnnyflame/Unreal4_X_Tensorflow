// Fill out your copyright notice in the Description page of Project Settings.

#include "geVision.h"
#include "ScreenImage.h"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/nonfree/features2d.hpp"

#include <vector>

ScreenImage::ScreenImage()
{
    Xscreen = 0;
    Yscreen = 0;
    X = 0;
    Y = 0;
    displayed = false;
}

ScreenImage::ScreenImage(int Ydesired, int Xdesired) : ScreenImage() {
    Y = Ydesired;
    X = Xdesired;
    image = cv::Mat(Y,X, CV_8UC3);
}

ScreenImage::~ScreenImage()
{
    if(displayed) {
        cv::destroyWindow("geVision screenshot");
    }
}

void ScreenImage::grab() {
    
    //Save screenshot to file using Unreal API
    /*
     FString filename = "geScreenshot.png";
     FScreenshotRequest::RequestScreenshot(filename, false, false);
     */
    
    //Grab screenshot to memory
    UGameViewportClient* gameViewport = GEngine->GameViewport;
    FViewport* InViewport = gameViewport->Viewport;
    TArray<FColor> Bitmap;
    FIntRect Rect(0, 0, InViewport->GetSizeXY().X, InViewport->GetSizeXY().Y);
    //Store screenshot in Bitmap array
    bool bScreenshotSuccessful = GetViewportScreenShot(InViewport, Bitmap, Rect);

    if (bScreenshotSuccessful){
        //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Screenshot taken!"));
    
        // Get screenshot size
        FIntVector Size(InViewport->GetSizeXY().X, InViewport->GetSizeXY().Y, 0);
        // Define CV image of same size
        
        if(Xscreen == 0 || Yscreen == 0) {
            Xscreen = Size.X;
            Yscreen = Size.Y;
            screenshot = cv::Mat(Yscreen,Xscreen, CV_8UC3);
            if(X == 0 || Y == 0) {
                image = screenshot;
                X = Xscreen;
                Y = Yscreen;
            }
        }
        //Copy pixel values from the Bitmap array to CV image
        int32 i=0;
        int32 j=0;
        for (auto& pix : Bitmap)
        {
            cv::Point3_<uchar>* p = screenshot.ptr<cv::Point3_<uchar> >(i,j);
            p->x = pix.B;
            p->y = pix.G;
            p->z = pix.R;
            j++;
            if(j >= Size.X) {
                j = 0;
                i++;
            }
        }
        if(X != Xscreen || Y != Yscreen) {
            //Resize CV image
            cv::resize(screenshot, image, image.size());
        }
    } else {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Screenshot grab fail!"));
    }
}

void ScreenImage::save() {
        //Save resized image
        //Saves to /Users/Shared/UnrealEngine/4.11/Engine/Binaries/Mac/
        cv::imwrite( "./geScreenshot.jpg", image);
    
}

void ScreenImage::show() {
    if(!displayed) {
        cv::namedWindow( "geVision screenshot", cv::WINDOW_AUTOSIZE );
    }

    cv::SiftFeatureDetector detector;
    std::vector<cv::KeyPoint> keypoints;
    detector.detect(image, keypoints);
    
    // Add results to image and save.
    cv::Mat output;
    cv::drawKeypoints(image, keypoints, output, -1 , cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    
    cv::imshow( "geVision screenshot", output );
    cv::waitKey(1);
}
