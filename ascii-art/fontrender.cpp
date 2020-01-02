#include "fontrender.h"

#define STB_TRUETYPE_IMPLEMENTATION 
#include "stb_truetype.h" 
#include "stb_image_write.h"
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

void FontRender::renderText(char text, unsigned char* bitmap)
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


	int fWidth = x2 - x1;
	int fHeight = y2 - y1;

	if (canvasWidth < fWidth || canvasHeight < fHeight)
	{
		std::cerr << "Input dimension values are lower than required values of (" << fWidth
			<< "x" << fHeight
			<< ").\nCall `calculateDimensions(char text)` and initialize `unsigned char bitmap` with updated `canvasWidth` and `canvasHeight`\nbefore calling this function.\n\n";
		return;
	}

	for (auto* i = bitmap; i != bitmap + canvasWidth * canvasHeight; ++i)
		*i = 0;

	stbtt_MakeCodepointBitmap(&info, bitmap, fWidth, fHeight, canvasWidth, scale, scale, text);
}

void FontRender::renderTextToPng(char text, std::string outputPath)
{
	int w = 0, h = 0;
	calculateDimensions(text, w, h);

	unsigned char* bitmap = new unsigned char[canvasWidth * canvasHeight];
	renderText(text, bitmap);
	stbi_write_png(outputPath.c_str(), canvasWidth, canvasHeight, 1, bitmap, canvasWidth);
	delete[] bitmap;
}

void FontRender::renderTextToBitmap(char text, unsigned char* bitmap)
{
	renderText(text, bitmap);
}

void FontRender::setCanvasDimension(int width, int height)
{
	canvasWidth = width;
	canvasHeight = height;
}

void FontRender::calculateDimensions(char text, int& outWidth, int& outHeight)
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

	outWidth = x2 - x1;
	outHeight = y2 - y1;
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
