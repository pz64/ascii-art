#pragma once

#include <string>

/**
	[FontRender] class read Truetype font files, render font to bitmap.
*/
class FontRender
{
public:
	int textSize;
	int canvasWidth, canvasHeight;
	std::string fontPath;
private:

	size_t size;
	unsigned char* fontBuffer;
	bool cantReadFont = false;

public:
	FontRender();

	/*
		This font path is the path of your local ttf file path.
	*/
	FontRender(std::string fontPath);
	~FontRender();

	/*
	Render [text] to output [outputPath] in png format.
	font in [fontPath] is used to render.
	*/
	void renderTextToPng(char text, std::string outputPath);

	/*
	Render [text] to [bitmap] variable.
	dimension of bitmap is same as canvasWidth and canvasHeight, single channel.
	font in [fontPath] is used to render.
	*/
	void renderTextToBitmap(char text, unsigned char* bitmap);
	void setCanvasDimension(int width, int height);

	/*
		If canvas dimension is lower than the minimum dimension needed for font to display,
		call `calculateDimensions` it output the minimum dimension for the font which can be used to update output code.
		this is already managed in the `renderTextToPng` function.
	*/
	void calculateDimensions(char text, int& outWidth, int& outHeight);

private:
	void renderText(char text, unsigned char* bitmap);
	void init();
	void allocate();
};

