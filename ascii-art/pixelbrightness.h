#pragma once
#include <string>
#include <vector>
#include "fontrender.h"
class PixelBrightness
{
	

private:
	FontRender* renderer;
public:
	std::string workingDirectory;
	std::vector<std::pair<char, float>> brightness;

private:
public:
	PixelBrightness();
	PixelBrightness(std::string workingDirectory)
		:workingDirectory(workingDirectory) {}
	void setFontRenderer(FontRender* fontRenderer);
	void calculateBrightness(bool writeImagesToDirectory = false);

};

