#pragma once
#include <iostream>

class Image
{
private:
	unsigned char* pixels;
	std::string filename;

public:
	int width;
	int height;
	int channels;
	size_t size;

public:
	Image(std::string filename) :filename(filename) { read(); }
	~Image();

	void resize(int new_width, int new_height);
	void resize(float factor);
	void resizeWrtWidth(int newWidth);
	void resizeWrtHeight(int newHeight);

	void grayscale();
	unsigned char* get() { return pixels; }
	void write(std::string name);

private:
	void read();

};

