/*
 * Shape.h
 *
 *  Created on: Mar 7, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_GRAPHIC_SHAPE_H_
#define PATHTOOLKIT_GRAPHIC_SHAPE_H_

#include "PaintableShape.h"

#include <graphic/gstructs.h>
#include <cstdint>

namespace PathDraw
{

class Shape : public PaintableShape
{
public:
	Shape();
	Shape(PTK_Point* points, int numPoints);
	Shape(PTK_Point* points, int numPoints, bool fill);
	virtual ~Shape();

	void AddPoint(PTK_Point point);
	void AddPoint(PTK_Point point, int index);

	uint16_t GetNumPoints();
	PTK_Point* GetPoints();

private:
	uint16_t numPoints;
	PTK_Point* points;
};

} /* namespace Pathfinder */

#endif /* PATHTOOLKIT_GRAPHIC_SHAPE_H_ */
