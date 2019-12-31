#include "fontrender.h"

#include "stb_image_write.h"

#define STB_TRUETYPE_IMPLEMENTATION 
#include "stb_truetype.h" 
#include <fstream>
#include <iostream>



void FontRender::init()
{
	textSize = 20;
	canvasWidth = 256;
	canvasHeight = 256;
}

FontRender::FontRender()
{
	init();
	fontPath = "../fonts/Roboto-Regular.ttf";
	allocate();
}


FontRender::FontRender(std::string fontPath) :fontPath(fontPath)
{
	init();
	allocate();
}

FontRender::~FontRender()
{
	delete[] fontBuffer;
}

void FontRender::renderText(char text)
{
	stbtt_fontinfo info;

	auto offset = stbtt_GetFontOffsetForIndex(fontBuffer, 0);
	if (!stbtt_InitFont(&info, fontBuffer, offset))
	{
		cantReadFont = true;
		std::cerr << "Unable to load font!";
		return;
	}



	float scale = stbtt_ScaleForPixelHeight(&info, textSize);

	int x1, y1, x2, y2;
	stbtt_GetCodepointBitmapBox(&info, text, scale, scale, &x1, &y1, &x2, &y2);

	int width = canvasWidth;
	int height = canvasHeight;

	int fWidth = x2 - x1;
	int fHeight = y2 - y1;

	if (width < fWidth || height < fHeight)
	{
		width = fWidth;
		height = fHeight;
	}

	auto* bitmap = new unsigned char[width * height];

	for (auto* i = bitmap; i != bitmap + width * height; ++i)
		*i = 0;

	stbtt_MakeCodepointBitmap(&info,bitmap , fWidth, fHeight, width, scale, scale, text);

	stbi_write_png("../outs/fonts/font.png", width, height, 1, bitmap, width);

	delete[] bitmap;
}

void FontRender::setCanvasDimension(int width, int height)
{
	canvasWidth = width;
	canvasHeight = height;
}

void FontRender::allocate()
{
	std::ifstream in = std::ifstream(fontPath, std::ios::binary);

	if (!in.is_open())
	{
		cantReadFont = true;
		std::cerr << "Unable to open font file!";
		return;
	}

	in.ignore(std::numeric_limits<std::streamsize>::max());
	size = static_cast<size_t>(in.gcount());
	in.eof();
	in.seekg(0, std::ios_base::beg);

	fontBuffer = new unsigned char[size];

	in.read((char*)fontBuffer, size);

	in.close();

}
