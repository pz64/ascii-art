// ascii-art.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "image.h"
#include "fontrender.h"
#include "pixelbrightness.h"
#include "asciiart.h"


int main()
{
    /** Example 1: 
        READING , PROCESSING,  WRITING IMAGE.

        Read an image, scale it to half of it's original dimension and convert it to grayscale.
        Finally write back to storage.
    */
    std::string imgPath = "../out/photo_1.jpg";
    std::string outPath = "../out/photo_1_out.jpg";

    Image image(imgPath);
    image.resize(0.5);
    image.grayscale();
    image.write(outPath);

 
    /** Example 2:
        GENERATING BRIGHTNESS ARRAY FOR ASCII ART.
    */

    /*FontRender renderer;

    PixelBrightness brightness;
    brightness.setFontRenderer(&renderer);
    brightness.calculateBrightness();*/

  

    /** Example 3:
        GENERATING ASCII ART.
    */

    char BRIGHTNESS[256] = {

        32,32,32,32,32,32,32,46,46,46,46,46,46,46,96,96,
        96,96,96,96,45,45,45,45,45,45,39,39,39,39,39,39,
        44,44,44,44,44,95,95,95,95,95,58,58,58,58,58,34,
        34,34,34,34,59,59,59,59,108,108,108,108,124,124,124,124,
        126,126,126,126,105,105,105,105,33,33,33,94,94,94,73,73,
        73,114,114,114,61,61,61,42,42,42,60,60,62,62,116,116,
        106,106,49,49,47,47,118,118,102,102,93,93,91,91,92,92,
        43,40,41,122,63,110,120,115,99,117,125,123,76,55,101,74,
        111,97,70,121,84,107,104,50,53,54,51,112,89,98,69,52,
        57,100,90,90,113,113,85,85,80,80,86,86,48,48,56,56,
        119,119,103,103,75,75,83,83,83,67,67,67,65,65,65,88,
        88,88,72,72,72,68,68,68,66,66,66,66,35,35,35,35,
        82,82,82,82,37,37,37,37,109,109,109,109,71,71,71,71,
        71,36,36,36,36,36,78,78,78,78,78,79,79,79,79,79,
        38,38,38,38,38,38,81,81,81,81,81,81,77,77,77,77,
        77,77,87,87,87,87,87,87,87,64,64,64,64,64,64,64
    };

    Image plant("../out/photo_1.jpg");
    plant.resizeWrtWidth(300);

    ASCIIArt art(&plant,BRIGHTNESS);
    art.generateArt();

}