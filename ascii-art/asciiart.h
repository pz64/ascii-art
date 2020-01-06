#pragma once

#include <string>
/**
	The [ASCIIArt] class
*/
class ASCIIArt
{
private:
	
	class FontRender* renderer;
	class Image* image;
public:
	std::string outputPath;
	
private:
public:
	ASCIIArt(Image* image, FontRender* renderer);

	/*
		This function generates the ascii art on the console.
		set [inverse] to true if the image pixels need to be inverted while generating art.
	*/
	void generateArt(bool inverse = false);
};
