// ascii-art.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "image.h"
#include "fontrender.h"
#include "pixelbrightness.h"
#include "asciiart.h"
int main()
{

    char BRIGHTNESS[256] = {

         32,32,32,32,32,32,32,96,96,96,96,96,96,96,46,46,
         46,46,46,46,45,45,45,45,45,45,44,44,44,44,44,44,
         39,39,39,39,39,95,95,95,95,95,58,58,58,58,58,126,
         126,126,126,126,34,34,34,34,59,59,59,59,33,33,33,33,
         124,124,124,124,61,61,61,61,42,42,42,43,43,43,62,62,
         62,60,60,60,105,105,105,114,114,114,108,108,74,74,94,94,
         76,76,99,99,118,118,122,122,115,115,120,120,110,110,117,117,
         40,73,55,91,93,63,70,116,41,53,89,84,101,50,47,92,
         49,125,123,80,67,69,85,97,111,51,90,72,119,86,83,109,
         106,121,75,75,88,88,78,78,52,52,104,104,65,65,66,66,
         82,82,68,68,107,107,102,102,102,36,36,36,71,71,71,77,
         77,77,79,79,79,113,113,113,112,112,112,112,57,57,57,57,
         48,48,48,48,98,98,98,98,100,100,100,100,56,56,56,56,
         56,54,54,54,54,54,87,87,87,87,87,103,103,103,103,103,
         35,35,35,35,35,35,37,37,37,37,37,37,81,81,81,81,
         81,81,64,64,64,64,64,64,64,38,38,38,38,38,38,38
    };


	auto plant = Image("../out/ebin.jpg");
	plant.resizeWrtWidth(50);

	auto asciiArt = ASCIIArt(&plant, BRIGHTNESS);
	asciiArt.generateArt(false);



	/*auto renderer = FontRender("C:\\Users\\71000430\\Downloads\\lucon.ttf");
	renderer.textSize = 24;
	renderer.setCanvasDimension(32, 32);

	auto calc = PixelBrightness("../out/fonts/");
	calc.setFontRenderer(&renderer);
	calc.calculateBrightness(true);*/


}