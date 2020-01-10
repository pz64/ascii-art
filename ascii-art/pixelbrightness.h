#pragma once
#include <string>
#include <vector>
#include "fontrender.h"

/**
	[PixelBrightness] class generate the [BRIGHTNESS] array input for given font.
	the [BRIGHTNESS] array otput is input for the [ASCIIArt] class to draw.
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

