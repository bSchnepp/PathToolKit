/*
 * Circle.cpp
 *
 *  Created on: Mar 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <graphic/Circle.h>

namespace PathDraw
{

Circle::Circle(PTK_Point center, uint16_t radius)
{
	this->center = center;
	this->radius = radius;
}


Circle::~Circle()
{
	// TODO Auto-generated destructor stub
}

} /* namespace Pathfinder */
