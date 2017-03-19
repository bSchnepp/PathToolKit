/*
 * ObjectCanvas.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <graphic/ShapeContainer.h>

namespace PathDraw
{

ShapeContainer::ShapeContainer()
{
	// TODO Auto-generated constructor stub

}

ShapeContainer::~ShapeContainer()
{
	// TODO Auto-generated destructor stub
}

std::vector<PaintableShape*> ShapeContainer::GetItems()
{
	return this->items;
}

void ShapeContainer::AddItem(PaintableShape* item)
{
	this->items.push_back(item);
}

} /* namespace Pathfinder */
