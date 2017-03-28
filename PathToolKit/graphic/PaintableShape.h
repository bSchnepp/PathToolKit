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
struct PTK_Stroke;
class Color;

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
	virtual bool isRectangle();
	virtual bool isIrregularArc();
	virtual bool isIrregularCircle();

	virtual ~PaintableShape();

	void SetStroke(PTK_Stroke* stroke);
	PTK_Stroke GetStroke();

	void SetSolidColor(Color* color);
	void SetLinearGradientColor(Color* color1, Color* color2);
	void SetGradientRadial(bool val);

protected:
	bool fill;
	bool isArc = false;
	bool isCircle = false;
	PTK_Stroke* stroke;
};

} /* namespace Pathfinder */

#endif /* PATHTOOLKIT_GRAPHIC_PAINTABLESHAPE_H_ */
