#include "asciiart.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include "image.h"
#include "fontrender.h"
#include "pixelbrightness.h"

ASCIIArt::ASCIIArt(Image* image, FontRender* renderer) :image(image), renderer(renderer)
{
}

void ASCIIArt::generateArt(bool inverse)
{
	if (!image)
	{
		std::cerr << "Image can't be null. Are you kidding me?!";
		return;
	}

	if (!renderer)
	{
		std::cerr << "Font Renderer can't be null.!";
		return;
	}

	std::ofstream fout;
	if (!outputPath.empty())
		fout.open(outputPath);

	PixelBrightness calc;
	calc.setFontRenderer(renderer);
	calc.calculateBrightness();

	image->grayscale();

	auto* data = image->get();

	int index = 0;
	for (auto* i = data; i != data + image->size; i += image->channels, ++index)
	{
		if (index % image->width == 0)
		{
			fout << std::endl;
			std::cout << std::endl;
		}
		if (inverse)
		{
			fout << calc.BRIGHTNESS[255 - *i];
			std::cout << calc.BRIGHTNESS[255 - *i];
		}
		else
		{
			fout << calc.BRIGHTNESS[*i];
			std::cout << calc.BRIGHTNESS[*i];
		}
	}

	if (fout.is_open())
		fout.close();
}
