/*
 * Arc.cpp
 *
 *  Created on: Mar 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <graphic/Arc.h>

namespace Pathfinder
{

Arc::Arc(PTK_Point center, uint16_t radius, uint16_t startangle, uint16_t arcangle)
{
	this->center = center;
	this->radius = radius;
	this->startangle = startangle;
	this->arcangle = arcangle;
}


Arc::~Arc()
{
	// TODO Auto-generated destructor stub
}

} /* namespace Pathfinder */
