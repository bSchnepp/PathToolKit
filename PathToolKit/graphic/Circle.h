/*
 * Circle.h
 *
 *  Created on: Mar 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_GRAPHIC_CIRCLE_H_
#define PATHTOOLKIT_GRAPHIC_CIRCLE_H_

#include <PathToolKit/graphic/gstructs.h>
#include <PathToolKit/graphic/PaintableShape.h>
#include <cstdint>

namespace PathDraw
{

class Circle: public PaintableShape
{
public:
	Circle(PTK_Point center, uint16_t radius);
	virtual ~Circle();

	bool IsArc();
	bool IsCircle();

	uint16_t GetRadius();

	PTK_Point* GetPoints();
	uint16_t GetNumPoints();

private:
	PTK_Point center;
	uint16_t radius;
};

} /* namespace Pathfinder */

#endif /* PATHTOOLKIT_GRAPHIC_CIRCLE_H_ */
