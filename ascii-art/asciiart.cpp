#include "asciiart.h"

#include<iostream>
#include <cstring>

ASCIIArt::ASCIIArt(Image* image, char brightness[256]) :image(image)
{
	memcpy(BRIGHTNESS, brightness, 256);
}

void ASCIIArt::generateArt(bool inverse)
{
	if (!image)
	{
		std::cerr << "Image can't be null. Are you kidding me?!";
		return;
	}

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
