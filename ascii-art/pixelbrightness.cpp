#include "pixelbrightness.h"
#include <iostream>
#include <string>
#include<algorithm>
#include "image.h"

void PixelBrightness::setFontRenderer(FontRender* fontRenderer)
{
	renderer = fontRenderer;
}

void PixelBrightness::calculateBrightness(bool writeImagesToDirectory)
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

	size_t size = renderer->canvasHeight * renderer->canvasHeight;

	auto* bitmap = new unsigned char[size];

	for (auto i = 32; i < 127; ++i)
	{
		renderer->renderTextToBitmap(i, bitmap);
		
		if (writeImagesToDirectory)
			renderer->renderTextToPng(i, workingDirectory + std::to_string(i) + std::string(".png"));

		float sum = 0;
		for (auto* i = bitmap; i != bitmap + size; ++i)
			sum += *i;
		auto avg = sum/size ;
		brightness.push_back(std::pair((char)i, avg));

	}
	delete[] bitmap;

	std::sort(brightness.begin(), brightness.end(), [](auto& left, auto& right) {
		return left.second < right.second;
	});

	std::cout << "ASCII" << "\t" << "CHAR" << "\t" << "BRIGHTNESS" << std::endl;
	for (auto i : brightness)
	{
		std::cout << int(i.first) << "\t"<< i.first << "\t" << i.second << std::endl;
	}
}
