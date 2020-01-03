#include "image.h"

#include <iostream>
#include <utility>

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h" 


Image::~Image()
{
	if (pixels)
		stbi_image_free(pixels);
}

void Image::read()
{
	pixels = static_cast<unsigned char*>(stbi_load(filename.c_str(), &width, &height, &channels, 0));
	if (!pixels)
	{
		std::cerr << "Image Corrupt or memory error.";
		return;
	}
	size = height * width * channels;
}

void Image::write(std::string name)
{
	if (!pixels) return;
	stbi_write_jpg(name.c_str(), width, height, channels, pixels, 50);
}

void Image::resize(int newWidth, int newHeight)
{
	if (newWidth > width || newHeight > height)
	{
		std::cerr << "Height and width must be smaller than actual value";
		return;
	}
	auto result = stbir_resize_uint8(pixels, width, height, 0,
		pixels, newWidth, newHeight, 0, channels);

	if (result == 1) {
		width = newWidth;
		height = newHeight;
		size = width * height * channels;
	}
	else std::cerr << "Unable to resize!";

}

void Image::resize(float factor)
{
	int newHeight = (int)(height * factor);
	int newWidth = (int)(width * factor);
	resize(newWidth, newHeight);
}

void Image::resizeWrtWidth(int newWidth)
{
	float factor = float(newWidth) / float(width);
	resize(factor);
}

void Image::resizeWrtHeight(int newHeight)
{
	float factor = float(newHeight) / float(height);
	resize(factor);
}

void Image::grayscale()
{
	if (!pixels) return;

	int singlechannel = 1;
	size_t newsize = width * height * singlechannel;
	auto* outpix = new unsigned char[newsize];

	for (unsigned char* i = pixels, *o = outpix; i != size + pixels; i += channels, o += singlechannel)
	{
		auto average = static_cast<unsigned char>((*(i + 0) + *(i + 1) + *(i + 2)) / 3);
		*o = average;
	}

	stbi_image_free(pixels);
	pixels = static_cast<unsigned char*> (malloc(size));
	pixels = std::move(outpix);
	channels = singlechannel;
	size = newsize;
}
