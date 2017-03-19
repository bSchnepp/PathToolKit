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


private:
	PTK_Point center;
	uint16_t radius;
	uint16_t startangle;
	uint16_t arcangle;
};

} /* namespace Pathfinder */

#endif /* PATHTOOLKIT_GRAPHIC_ARC_H_ */
