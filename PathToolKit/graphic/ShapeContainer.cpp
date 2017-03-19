/*
 * ObjectCanvas.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <graphic/ShapeContainer.h>

namespace Pathfinder
{

ShapeContainer::ShapeContainer()
{
	// TODO Auto-generated constructor stub

}

bool ShapeContainer::Repaint()
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

ShapeContainer::~ShapeContainer()
{
	// TODO Auto-generated destructor stub
}

} /* namespace Pathfinder */
