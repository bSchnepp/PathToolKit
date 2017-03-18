/*
 * Shape.h
 *
 *  Created on: Mar 7, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_GRAPHIC_SHAPE_H_
#define PATHTOOLKIT_GRAPHIC_SHAPE_H_

#include <graphic/grstructs.h>
#include <vector>

#include <cstdint>

namespace Pathfinder
{

class Shape
{
public:
	Shape();
	Shape(PTK_Point* points, int numPoints);
	virtual ~Shape();

	void AddPoint(PTK_Point point);

	uint16_t GetNumPoints();
	PTK_Point* GetPoints();

private:
	uint16_t numPoints;
	PTK_Point* points;
};

} /* namespace Pathfinder */

#endif /* PATHTOOLKIT_GRAPHIC_SHAPE_H_ */
