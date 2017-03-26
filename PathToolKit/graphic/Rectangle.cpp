/*
 * Rectangle.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <PathToolKit/graphic/gstructs.h>
#include <PathToolKit/graphic/Rectangle.h>
#include <cstdlib>
#include <cstdint>

namespace PathDraw
{

Rectangle::Rectangle(PTK_Point origin, float width, float height)
{
	this->dheight = width;
	this->dwidth = height;
	this->origin = origin;
}

bool Rectangle::isRectangle()
{
	return true;
}

PTK_Point* Rectangle::GetPoints()
{
	//Naughty naughty, you shouldn't use this and just use the width and height from origin. This is wrong and I'm not going to bother fixing it for a while.
	PTK_Point* array = static_cast<PTK_Point*>(malloc(sizeof(PTK_Point) * 4));
	array[0] = this->origin;

	PTK_Point p1, p2, p3;

	p1.posx = this->origin.posx + this->dwidth;
	p1.posy = this->origin.posy;

	p2.posx = this->origin.posx + this->dwidth;
	p2.posy = this->origin.posy + this->dheight;

	p3.posx = this->origin.posx;
	p3.posy = this->origin.posy + this->dheight;

	array[1] = p1;
	array[2] = p2;
	array[3] = p3;

	return array;	//Up to caller to deallocate, always.
}
uint16_t Rectangle::GetNumPoints()
{
	return 4;
}

Rectangle::~Rectangle()
{
	// TODO Auto-generated destructor stub
}

} /* namespace PathDraw */
