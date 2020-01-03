#pragma once

#include "image.h"

/**
	The [ASCIIArt] class
*/
class ASCIIArt
{
private:
	char BRIGHTNESS[256];
	Image* image;
public:
	ASCIIArt(Image* image, char brightness[256]);

private:
public:
	/*
		This function generates the ascii art on the console.
		set [inverse] to true if the image pixels need to be inverted while generating art.
	*/
	void generateArt(bool inverse = false);
};
