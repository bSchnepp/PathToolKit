/*
 * grstructs.h
 *
 *  Created on: Mar 7, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_GRAPHIC_GSTRUCTS_H_
#define PATHTOOLKIT_GRAPHIC_GSTRUCTS_H_

#include "../gutil/Color.h"
namespace PathDraw
{
//Forward declaration because dependencies. My C++ is awful, and I'm used to Java for the longest time where this isn't a problem.
class Shape;

typedef enum PTK_Cap_Style
{
	CAP_BUTT, CAP_ROUND, CAP_SQUARE
} PTK_Cap_style;

typedef enum PTK_Join_Style
{
	JOIN_ROUND, JOIN_MITER, JOIN_BEVEL
} PTK_Join_Style;

typedef struct PTK_Point
{
	float posx;
	float posy;
} PTK_Point;

typedef struct PTK_Stroke
{
	Color** colors;
	float* colorChanges;
	float blending;

	float width;
} PTK_Stroke;

typedef struct PTK_Object
{
	PathDraw::Shape* shape;
	PathDraw::PTK_Stroke* stroke;
} PTK_Object;

// Generate a nice generic default object.
PTK_Object* CreateShape(Shape* shape);
PTK_Object* CreateShapeColor(Shape* shape, Color* color);

}

#endif /* PATHTOOLKIT_GRAPHIC_GSTRUCTS_H_ */
