/*
 * Circle.cpp
 *
 *  Created on: Mar 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <PathToolKit/graphic/Circle.h>

namespace PathDraw
{

Circle::Circle(PTK_Point center, uint16_t radius)
{
	this->center = center;
	this->radius = radius;
	this->isCircle = true;
	this->dynamic = false;
}

bool Circle::IsArc()
{
	return false;
}

bool Circle::IsCircle()
{
	return true;
}

uint16_t Circle::GetRadius()
{
	return this->radius;
}

PTK_Point* Circle::GetPoints()
{
	return &this->center;
}
uint16_t Circle::GetNumPoints()
{
	return 1;
}

Circle::~Circle()
{
	// TODO Auto-generated destructor stub
}

} /* namespace Pathfinder */
