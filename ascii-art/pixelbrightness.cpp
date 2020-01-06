#include "pixelbrightness.h"
#include <iostream>
#include <string>
#include<algorithm>
#include "image.h"

void PixelBrightness::stretchBrightnessArray()
{

	int multiplier[95] = {
		6,6,5,5,5,4,4,4,4,3,3,3,3,3,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,4,4,4,4,5,5,5,6,6
	};

	int x = 0;
	for (int i = 0; i < 95; ++i)
	{
		for (int j = 0; j < multiplier[i] + 1; ++j)
		{
			BRIGHTNESS[x] = brightness[i].first;
			x += 1;
		}
	}
	/*
	std::cout << "Feed this array to ascii-art. Only generate this PixelBrightness Array if new font is added." << std::endl;
	std::cout << "\n\nchar BRIGHTNESS[256] = {"<<std::endl;

	for (int i = 0; i < 255; ++i)
	{
		if (i % 16 == 0)
			std::cout << std::endl << "\t";
		std::cout << int(BRIGHTNESS[i]) << ",";
	}
	std::cout << int(BRIGHTNESS[255])<< std::endl<< "};\n\n";
	*/
}

PixelBrightness::~PixelBrightness()
{
}

void PixelBrightness::setFontRenderer(FontRender* fontRenderer)
{
	renderer = fontRenderer;
}

void PixelBrightness::calculateBrightness()
{
	calculateBrightness_Internal(false);
}

void PixelBrightness::calculateBrightness_Internal(bool writeImagesToDirectory)
{
	if (!renderer)
	{
		std::cerr << "No renderer assigned!";
		return;
	}

	if (writeImagesToDirectory && workingDirectory.empty())
	{
		std::cerr << "No working directory set!";
		return;
	}



	for (auto i = (char)32; i < (char)127; ++i)
	{

		if (writeImagesToDirectory)
			renderer->renderTextToPng(i, workingDirectory + std::to_string(i) + std::string(".png"));


		int w, h;
		renderer->calculateDimensions(i, w, h);

		size_t footPrint = w * h;

		size_t dimen = renderer->canvasWidth * renderer->canvasHeight;

		auto* bitmap = new unsigned char[dimen];

		renderer->renderTextToBitmap(i, bitmap);

		float sum = 0;
		for (auto* i = bitmap; i != bitmap + dimen; ++i)
		{
			if (*i)
				sum += *i;
		}

		/*
		[avg] value holds a score that shows the number of white pixels present in its [footPrint].
		*/
		auto avg = (sum / dimen) * footPrint;

		brightness.push_back(std::pair((char)i, avg));

		delete[] bitmap;
	}


	std::sort(brightness.begin(), brightness.end(), [](auto& left, auto& right) {
		return left.second < right.second;
		});

	stretchBrightnessArray();
}
