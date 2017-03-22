/*
 * Arc.h
 *
 *  Created on: Mar 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_GRAPHIC_ARC_H_
#define PATHTOOLKIT_GRAPHIC_ARC_H_

#include "PaintableShape.h"

#include <graphic/gstructs.h>
#include <cstdint>

namespace PathDraw
{

class Arc : public PaintableShape
{
public:
	Arc(PTK_Point center, uint16_t radius, uint16_t startangle, uint16_t arcangle);
	virtual ~Arc();

	uint16_t GetRadius();
	uint16_t GetStartAngle();
	uint16_t GetArcAngle();

	uint16_t GetNumPoints();
	PTK_Point* GetPoints();

	bool IsArc();
	bool IsCircle();

private:
	PTK_Point center;
	uint16_t radius;
	uint16_t startangle;
	uint16_t arcangle;
};

} /* namespace Pathfinder */

#endif /* PATHTOOLKIT_GRAPHIC_ARC_H_ */
