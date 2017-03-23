/*
 * PaintableShape.cpp
 *
 *  Created on: Mar 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <PathToolKit/graphic/PaintableShape.h>
#include "../gutil/Color.h"
#include <cstdlib>

namespace PathDraw
{

PaintableShape::PaintableShape()
{
	this->fill = true;
	this->stroke = static_cast<PTK_Stroke*>(malloc(sizeof(PTK_Stroke)));
	this->stroke->colors = {new Color(0,0,0)};
	this->stroke->joinstyle = PTK_Join_Style::JOIN_MITER;
	this->stroke->capstyle = PTK_Cap_Style::CAP_BUTT;
}

PaintableShape::~PaintableShape()
{
	delete[] this->stroke->colors;
	free(this->stroke);
}

uint16_t PaintableShape::GetNumPoints()
{
	//Circle/Arcs  should always return 1
	//Shape should do this as intended.
	return 0;
}

PTK_Point* PaintableShape::GetPoints()
{
	//Circle/arc should return their single point as a pointer.
	//Refactor later.
	return nullptr;
}

bool PaintableShape::GetFill()
{
	return this->fill;
}

void PaintableShape::SetFill(bool fill)
{
	this->fill = fill;
}

bool PaintableShape::IsArc()
{
	return false;
}

bool PaintableShape::IsCircle()
{
	return false;
}

} /* namespace Pathfinder */
