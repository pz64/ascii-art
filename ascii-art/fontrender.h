#pragma once

#include <string>

class FontRender
{
public:
	int textSize;
	int canvasWidth, canvasHeight;
private:

	size_t size;
	unsigned char* fontBuffer;
	std::string fontPath;
	bool cantReadFont = false;

public:
	FontRender();
	FontRender(std::string fontPath);
	~FontRender();

	void renderTextToPng(char text, std::string outputPath);
	void renderTextToBitmap(char text, unsigned char* bitmap);
	void setCanvasDimension(int width, int height);
	void calculateDimensions(char text, int& outWidth, int& outHeight);

private:
	void renderText(char text, unsigned char* bitmap);
	void init();
	void allocate();
};

