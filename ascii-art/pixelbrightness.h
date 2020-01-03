#pragma once
#include <string>
#include <vector>
#include "fontrender.h"

/**
	[PixelBrightness] class generate the [BRIGHTNESS] array input for given font.
	the [BRIGHTNESS] array otput is input for the [ASCIIArt] class to draw.

	Note:
	This class doesn't need to be called onn each run. Once the brightness array is obtained via console output,
	copy it to actual code . This array wont change for this font. Only generate new array if new font is input.
*/
class PixelBrightness
{

private:
	FontRender* renderer;
	std::vector<std::pair<char, float>> brightness;
	std::string workingDirectory;
public:
	char BRIGHTNESS[256];

private:
	void stretchBrightnessArray();
	void calculateBrightness_Internal(bool writeImagesToDirectory = false);
public:
	~PixelBrightness();
	void setFontRenderer(FontRender* fontRenderer);

	/*
		This function output the BRIGHTNESS array for [ASCIIArt] class.
	*/
	void calculateBrightness();

};

