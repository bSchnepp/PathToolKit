/*
 * ObjectCanvas.h
 *
 *  Created on: Mar 6, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_GRAPHIC_SHAPECONTAINER_H_
#define PATHTOOLKIT_GRAPHIC_SHAPECONTAINER_H_

#include <vector>
#include  <cstdint>

#include "gstructs.h"
#include "Shape.h"

namespace Pathfinder
{

class RenderSurface
{
	//Rasterization process goes here
};

/*
 *	TODO --
 *	Take a bunch of graphical objects, grab their functions for how they are to be represented (ie, box, line, curve, etc.)
 *	Apply it to a 'canvas' (ie, this), which is what rasterizes the vector components and puts the shapes in terms of the size of this canvas object.
 */
class ShapeContainer
{
public:
	ShapeContainer();
	virtual ~ShapeContainer();

	/* Paints all of the structures of this container with the associated stroke. */
	bool Repaint();

	void AddItem();	//TODO
	void RemoveItem(int index);
	std::vector<Shape*> GetItems(); //TODO

private:
	PTK_Stroke stroke;
	std::vector<Shape*> items;
};

} /* namespace Pathfinder */

#endif /* PATHTOOLKIT_GRAPHIC_SHAPECONTAINER_H_ */
