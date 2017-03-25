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
	float width;
	PTK_Join_Style joinstyle;
	PTK_Cap_Style capstyle;
	PTK_Point* points;
	bool radial;
} PTK_Stroke;

}

#endif /* PATHTOOLKIT_GRAPHIC_GSTRUCTS_H_ */
