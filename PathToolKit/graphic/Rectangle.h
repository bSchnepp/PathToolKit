/*
 * Rectangle.h
 *
 *  Created on: Mar 25, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_GRAPHIC_RECTANGLE_H_
#define PATHTOOLKIT_GRAPHIC_RECTANGLE_H_

#include <PathToolKit/graphic/PaintableShape.h>

namespace PathDraw
{

class Rectangle: public PaintableShape
{
public:
	Rectangle(PTK_Point origin, float width, float height);

	virtual ~Rectangle();

	bool isRectangle();
	PTK_Point* GetPoints();
	uint16_t GetNumPoints();

	inline float getWidth()
	{
		return dwidth;
	}

	inline void setWidth(float dwidth)
	{
		this->dwidth = dwidth;
	}

	inline float getHeight()
	{
		return dheight;
	}

	inline void setHeight(float dheight)
	{
		this->dheight = dheight;
	}

private:
	float dwidth;
	float dheight;
	PTK_Point origin;
};

} /* namespace PathDraw */

#endif /* PATHTOOLKIT_GRAPHIC_RECTANGLE_H_ */
