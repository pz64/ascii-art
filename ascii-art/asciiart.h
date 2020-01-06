#pragma once
/**
	The [ASCIIArt] class
*/
class ASCIIArt
{
private:
	char BRIGHTNESS[256];
	class FontRender* renderer;
	class Image* image;
public:
	ASCIIArt(Image* image, FontRender* renderer);


private:
public:
	/*
		This function generates the ascii art on the console.
		set [inverse] to true if the image pixels need to be inverted while generating art.
	*/
	void generateArt(bool inverse = false);
};
