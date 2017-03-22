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

namespace PathDraw
{
struct PTK_Point;
} /* namespace PathDraw */

namespace PathDraw
{

class PaintableShape
{
public:
	PaintableShape();

	virtual uint16_t GetNumPoints();
	virtual PTK_Point* GetPoints();
	bool GetFill();
	void SetFill(bool fill);

	virtual bool IsArc();
	virtual bool IsCircle();

	virtual ~PaintableShape();

protected:
	bool fill;
	bool isArc = false;
	bool isCircle = false;
};

} /* namespace Pathfinder */

#endif /* PATHTOOLKIT_GRAPHIC_PAINTABLESHAPE_H_ */
