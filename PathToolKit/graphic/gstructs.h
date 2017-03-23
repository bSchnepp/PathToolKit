/*
 * grstructs.h
 *
 *  Created on: Mar 7, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_GRAPHIC_GSTRUCTS_H_
#define PATHTOOLKIT_GRAPHIC_GSTRUCTS_H_

namespace PathDraw
{
class Color;
} /* namespace PathDraw */

namespace PathDraw
{
//Forward declaration because dependencies. My C++ is awful, and I'm used to Java for the longest time where this isn't a problem.
class Shape;

typedef enum class PTK_Cap_Style
{
	CAP_BUTT, CAP_ROUND, CAP_SQUARE
} PTK_Cap_Style;

typedef enum class PTK_Join_Style
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
	Color* colors;
	float* colorChanges;
	float blending;
	float width;
	PTK_Join_Style joinstyle;
	PTK_Cap_Style capstyle;
} PTK_Stroke;

}

#endif /* PATHTOOLKIT_GRAPHIC_GSTRUCTS_H_ */
