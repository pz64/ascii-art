#pragma once
#include <string>
#include <vector>
#include "fontrender.h"

class PixelBrightness
{

private:
	FontRender* renderer;
	std::vector<std::pair<char, float>> brightness;
public:
	std::string workingDirectory;
	char BRIGHTNESS[256];

private:
	void stretchBrightnessArray();
public:
	PixelBrightness();
	PixelBrightness(std::string workingDirectory)
		:workingDirectory(workingDirectory) {}
	void setFontRenderer(FontRender* fontRenderer);
	void calculateBrightness(bool writeImagesToDirectory = false);

};

