// ascii-art.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "image.h"
#include "fontrender.h"
#include "pixelbrightness.h"
#include "asciiart.h"

int main()
{
    /*
    uses default font:
    "./fonts/Roboto-Regular.ttf
    */
    FontRender robotoDefault;

    Image plant("../out/photo_1.jpg");
    plant.resizeWrtWidth(80);

    ASCIIArt art(&plant,&robotoDefault);
    art.generateArt();
}