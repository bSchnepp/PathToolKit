/*
 * ObjectCanvas.h
 *
 *  Created on: Mar 6, 2017
 *      Author: Brian Schnepp
 */

#ifndef PATHTOOLKIT_GRAPHIC_OBJECTCANVAS_H_
#define PATHTOOLKIT_GRAPHIC_OBJECTCANVAS_H_

#include <vector>
#include  <cstdint>

namespace Pathfinder
{

/*
 *	TODO --
 *	Take a bunch of graphical objects, grab their functions for how they are to be represented (ie, box, line, curve, etc.)
 *	Apply it to a 'canvas' (ie, this), which is what rasterizes the vector components and puts the shapes in terms of the size of this canvas object.
 */



class ObjectCanvas
{
public:
	ObjectCanvas();
	virtual ~ObjectCanvas();

	void Repaint();
	void AddItem();	//TODO
	void RemoveItem(int index);
	//std::vector<VectorItem> GetItems(); //TODO

private:
	uint16_t width;
	uint16_t height;
	//TODO: array of objects...
};

} /* namespace Pathfinder */

#endif /* PATHTOOLKIT_GRAPHIC_OBJECTCANVAS_H_ */
