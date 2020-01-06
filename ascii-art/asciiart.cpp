#include "asciiart.h"

#include<iostream>
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

	PixelBrightness brightness;
	brightness.setFontRenderer(renderer);
	brightness.calculateBrightness();

	memcpy(BRIGHTNESS, brightness.BRIGHTNESS, 256);


	image->grayscale();

	auto* data = image->get();

	int index = 0;
	for (auto* i = data; i != data + image->size; i += image->channels, ++index)
	{
		if (index % image->width == 0)
			std::cout << std::endl;
		if (inverse)
		{
			std::cout << BRIGHTNESS[255 - *i];
		}
		else
		{
			std::cout << BRIGHTNESS[*i];
		}
	}

}
