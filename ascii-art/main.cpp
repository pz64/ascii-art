// ascii-art.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "image.h"

int main()
{   

	auto img = Image("C:/Users/71000430/Documents/Projects/others/ascii-art/tests/photo_1.jpg");


	img.grayscale();

	img.resizeWrtHeight(123);
	
	img.write("C:/Users/71000430/Documents/Projects/others/ascii-art/tests/out.jpg");

}