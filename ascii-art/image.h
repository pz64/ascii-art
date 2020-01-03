#pragma once
#include <iostream>

/**
	[Image] class can do basic image operations like reading, writing, resizing
	and converting pixels to grayscale.
*/
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

	/*
		Resize image to [newWidth] and [newHeight]. 
		Doesn't preserve the ratio.
	*/
	void resize(int newWidth, int newHeight);
	/*
		Resize image by factor.
		eg:a factor of 0.5 scale image to tha half of it's original dimension.
	
		supported values - 0 to 1

		Preserve the ratio.
	*/
	void resize(float factor);
	/*
	Adjust height according to given width.
	Preserve the ratio.
    */
	void resizeWrtWidth(int newWidth);
	/*
	Adjust width according to given height.
	Preserve the ratio.
	*/
	void resizeWrtHeight(int newHeight);

	void grayscale();
	unsigned char* get() { return pixels; }
	/*
	Write image to given storage path.
	*/
	void write(std::string fileName);

private:
	void read();

};

