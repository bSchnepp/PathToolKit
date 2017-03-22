/*
 * ObjectCanvas.h
 *
 *  Created on: Mar 6, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_GRAPHIC_SHAPECONTAINER_H_
#define PATHTOOLKIT_GRAPHIC_SHAPECONTAINER_H_

#include <PathToolKit/graphic/gstructs.h>
#include <PathToolKit/graphic/PaintableShape.h>
#include <vector>

namespace PathDraw
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

	void AddItem(PaintableShape* item);	//TODO
	void RemoveItem(int index);
	void RemoveItem(PaintableShape* item);
	std::vector<PaintableShape*> GetItems();

private:
	PTK_Stroke stroke;
	std::vector<PaintableShape*> items;
};

} /* namespace Pathfinder */

#endif /* PATHTOOLKIT_GRAPHIC_SHAPECONTAINER_H_ */
