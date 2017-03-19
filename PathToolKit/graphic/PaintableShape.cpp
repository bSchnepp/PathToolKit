/*
 * PaintableShape.cpp
 *
 *  Created on: Mar 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <graphic/PaintableShape.h>

namespace Pathfinder
{

PaintableShape::PaintableShape()
{
	this->fill = true;
}

PaintableShape::~PaintableShape()
{
	// TODO Auto-generated destructor stub
}

uint16_t PaintableShape::GetNumPoints()
{
	//Circle/Arcs  should always return 1
	//Shape should do this intentionally
	return 0;
}

PTK_Point* PaintableShape::GetPoints()
{
	//Circle/arc should return their single point as a pointer.
	return nullptr;
}

bool PaintableShape::GetFill()
{
	return this->fill;
}

} /* namespace Pathfinder */