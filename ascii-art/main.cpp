// ascii-art.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "image.h"
#include "fontrender.h"
#include "pixelbrightness.h"

int main()
{

	auto renderer = FontRender();
	renderer.textSize = 24;
	renderer.setCanvasDimension(32, 32);

	auto calc = PixelBrightness("../outs/fonts/");
	calc.setFontRenderer(&renderer);
	calc.calculateBrightness(false);

}