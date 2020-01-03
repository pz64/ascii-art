#pragma once

#include "image.h"

class ASCIIArt
{
private:
	char BRIGHTNESS[256];
	Image* image;
public:
	ASCIIArt(Image* image, char brightness[256]);
private:
public:
	void generateArt(bool inverse = false);
};
