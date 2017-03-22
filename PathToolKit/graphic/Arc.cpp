/*
 * Arc.cpp
 *
 *  Created on: Mar 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <graphic/Arc.h>
#include <cstdint>

namespace PathDraw
{

Arc::Arc(PTK_Point center, uint16_t radius, uint16_t startangle, uint16_t arcangle)
{
	this->center = center;
	this->radius = radius;
	this->startangle = startangle;
	this->arcangle = arcangle;
	this->isArc = true;
}

uint16_t Arc::GetRadius()
{
	return this->radius;
}
uint16_t Arc::GetStartAngle()
{
	return this->startangle;
}

uint16_t Arc::GetArcAngle()
{
	return this->arcangle;
}

uint16_t Arc::GetNumPoints()
{
	return 1;
}

PTK_Point* Arc::GetPoints()
{
	return &(this->center);
}

bool Arc::IsArc()
{
	return true;
}

bool Arc::IsCircle()
{
	return false;
}



Arc::~Arc()
{
	// TODO Auto-generated destructor stub
}

} /* namespace Pathfinder */
