// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "opencv2/core/core.hpp"

/**
 * 
 */
class GEVISION_API ScreenImage
{
public:
	ScreenImage();
    ScreenImage(int Ydesired, int Xdesired);
	~ScreenImage();
    
    void grab();
    void save();
    void show();
    
private:
    cv::Mat screenshot;
    cv::Mat image;
    int Yscreen;
    int Xscreen;
    int Y;
    int X;
    bool displayed;
    
};
