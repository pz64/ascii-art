#pragma once

#include <string>

class FontRender
{
public:
	int textSize;

private:
	int canvasWidth, canvasHeight;
	size_t size;
	unsigned char* fontBuffer;
	std::string fontPath;
	bool cantReadFont = false;

public:
	FontRender();
	FontRender(std::string fontPath);
	~FontRender();

	void renderText(char text);
	void setCanvasDimension(int width, int height);

private:
	void init();
	void allocate();
};

