/*
 * PaintableShape.h
 *
 *  Created on: Mar 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_GRAPHIC_PAINTABLESHAPE_H_
#define PATHTOOLKIT_GRAPHIC_PAINTABLESHAPE_H_

#include <cstdint>
#include "gstructs.h"

namespace Pathfinder
{

class PaintableShape
{
public:
	PaintableShape();

	virtual uint16_t GetNumPoints();
	virtual PTK_Point* GetPoints();
	bool GetFill();

	virtual ~PaintableShape();

protected:
	bool fill;
};

} /* namespace Pathfinder */

#endif /* PATHTOOLKIT_GRAPHIC_PAINTABLESHAPE_H_ */
