/*
 * Color.cpp
 *
 *  Created on: Feb 18, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <PathToolKit/gutil/Color.h>

#define PATHFINDER_INTERNAL_MULTFORFLOATCONVERT 255

namespace PathDraw
{

Color::Color()
{
	this->r = static_cast<uint16_t>(0);
	this->g = static_cast<uint16_t>(0);
	this->b = static_cast<uint16_t>(0);
}

Color::Color(Color* o)
{
	this->r = o->GetRed();
	this->g = o->GetGreen();
	this->b = o->GetBlue();
}

Color::Color(uint16_t r, uint16_t g, uint16_t b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

Color::Color(uint16_t r, uint16_t g, uint16_t b, uint16_t a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Color::Color(uint16_t r, uint16_t g, uint16_t b, Color* o)
{
	this->r = static_cast<uint16_t>(r + o->GetRed());
	this->g = static_cast<uint16_t>(g + o->GetGreen());
	this->b = static_cast<uint16_t>(b + o->GetBlue());
}

Color::Color(uint16_t r, uint16_t g, uint16_t b, uint16_t a, Color* o)
{
	this->r = static_cast<uint16_t>(r + o->GetRed());
	this->g = static_cast<uint16_t>(g + o->GetGreen());
	this->b = static_cast<uint16_t>(b + o->GetBlue());
	this->a = static_cast<uint16_t>(a + o->GetAlpha());
}

Color::Color(uint16_t c)
{
	this->r = static_cast<uint16_t>(c);
	this->g = static_cast<uint16_t>(c);
	this->b = static_cast<uint16_t>(c);
}

Color::Color(uint16_t c, uint16_t a)
{
	this->r = static_cast<uint16_t>(c);
	this->g = static_cast<uint16_t>(c);
	this->b = static_cast<uint16_t>(c);
	this->a = static_cast<uint16_t>(a);
}

Color::Color(int c)
{
	this->r = static_cast<uint16_t>(c);
	this->g = static_cast<uint16_t>(c);
	this->b = static_cast<uint16_t>(c);
}
Color::Color(int c, int a)
{
	this->r = static_cast<uint16_t>(c);
	this->g = static_cast<uint16_t>(c);
	this->b = static_cast<uint16_t>(c);
	this->a = static_cast<uint16_t>(a);
}
Color::Color(int r, int g, int b)
{
	this->r = static_cast<uint16_t>(r);
	this->g = static_cast<uint16_t>(g);
	this->b = static_cast<uint16_t>(b);
}
Color::Color(int r, int g, int b, Color* o)
{
	this->r = static_cast<uint16_t>(r + o->GetRed());
	this->g = static_cast<uint16_t>(g + o->GetGreen());
	this->b = static_cast<uint16_t>(b + o->GetBlue());
}
Color::Color(int r, int g, int b, int a)
{
	this->r = static_cast<uint16_t>(r);
	this->g = static_cast<uint16_t>(g);
	this->b = static_cast<uint16_t>(b);
	this->a = static_cast<uint16_t>(a);
}
Color::Color(int r, int g, int b, int a, Color* o)
{
	this->r = static_cast<uint16_t>(r + o->GetRed());
	this->g = static_cast<uint16_t>(g + o->GetGreen());
	this->b = static_cast<uint16_t>(b + o->GetBlue());
	this->a = static_cast<uint16_t>(a + o->GetAlpha());
}

Color::Color(float r, float g, float b, float a) :
		Color::Color(
				static_cast<uint8_t>(r * PATHFINDER_INTERNAL_MULTFORFLOATCONVERT),
				static_cast<uint8_t>(g * PATHFINDER_INTERNAL_MULTFORFLOATCONVERT),
				static_cast<uint8_t>(b * PATHFINDER_INTERNAL_MULTFORFLOATCONVERT),
				static_cast<uint8_t>(a * PATHFINDER_INTERNAL_MULTFORFLOATCONVERT))
{
}
Color::Color(float r, float g, float b) :
		Color::Color(
				static_cast<uint8_t>(r * PATHFINDER_INTERNAL_MULTFORFLOATCONVERT),
				static_cast<uint8_t>(g * PATHFINDER_INTERNAL_MULTFORFLOATCONVERT),
				static_cast<uint8_t>(b * PATHFINDER_INTERNAL_MULTFORFLOATCONVERT))
{
}

Color::~Color()
{
	// TODO Auto-generated destructor stub
}

uint16_t Color::GetRed()
{
	return this->r;
}

uint16_t Color::GetGreen()
{
	return this->g;
}

uint16_t Color::GetBlue()
{
	return this->b;
}

uint16_t Color::GetAlpha()
{
	return this->a;
}

Color* Color::Darker()
{
	return new Color(this->r - 20, this->g - 20, this->b - 20);
}

Color* Color::Brighter()
{
	return new Color(this->r + 20, this->g + 20, this->b + 20);
}

Color* Color::InvertRBG()
{
	return new Color(255 - this->r, 255 - this->g, 255 - this->b);
}

Color* Color::InvertHue()
{
	//TODO
	return this;
}

uint32_t Color::GenerateColor()
{
	uint32_t result = 0;
	result += this->r << 16;
	result += this->g << 8;
	result += this->b;
	return result;
}

} /* namespace Pathfinder */
