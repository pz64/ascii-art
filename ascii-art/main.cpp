// ascii-art.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "image.h"
#include "fontrender.h"
int main()
{   
	auto x = FontRender("C:\\Users\\71000430\\Downloads\\BRADHITC.TTF");
	x.textSize = 200;
	x.setCanvasDimension(128, 128);
	x.renderText('X');
}