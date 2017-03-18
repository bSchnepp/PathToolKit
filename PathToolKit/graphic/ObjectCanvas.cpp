/*
 * ObjectCanvas.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <graphic/ObjectCanvas.h>

namespace Pathfinder
{

ObjectCanvas::ObjectCanvas()
{
	// TODO Auto-generated constructor stub

}

bool ObjectCanvas::Repaint()
{
	bool success = true;
	for (Shape* n : this->items)
	{
		uint16_t pointCount = n->GetNumPoints();
		PTK_Point* points = n->GetPoints();
		pointCount++;
		points++;
		//TODO
	}
	return success;
}

ObjectCanvas::~ObjectCanvas()
{
	// TODO Auto-generated destructor stub
}

} /* namespace Pathfinder */
