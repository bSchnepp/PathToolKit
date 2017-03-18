/*
 * Shape.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <graphic/gstructs.h>
#include <graphic/Shape.h>
#include <cstdlib>

namespace Pathfinder
{

Shape::Shape()
{
	this->numPoints = 0;
	//Strange hacks to get this to work as intended -- we want to eventually rewrite this all in C for portability.
	this->points = nullptr;
	this->fill = true;
}

Shape::Shape(PTK_Point* points, int numPoints)
{
	this->numPoints = static_cast<uint16_t>(numPoints);
	this->points = (PTK_Point*)malloc(sizeof(PTK_Point) *  numPoints);
	for (int i = 0; i < numPoints; i++)
	{
		this->points[i] = points[i];
	}
	this->fill = true;
}

Shape::Shape(PTK_Point* points, int numPoints, bool fill)
{
	this->numPoints = static_cast<uint16_t>(numPoints);
	this->points = (PTK_Point*)malloc(sizeof(PTK_Point) *  numPoints);
	for (int i = 0; i < numPoints; i++)
	{
		this->points[i] = points[i];
	}
	this->fill = fill;
}


Shape::~Shape()
{
	free(this->points);
}

uint16_t Shape::GetNumPoints()
{
	return static_cast<uint16_t>(this->numPoints);
}

PTK_Point* Shape::GetPoints()
{
	return this->points;
}

void Shape::AddPoint(PTK_Point point)
{
	//I have a feeling there's a memory leak here I'm not seeing.
	this->numPoints++;
	PTK_Point* npoints = new PTK_Point[this->GetNumPoints()];
	for (int i = 0; i < this->numPoints; i++)
	{
		npoints[i] = this->points[i];
	}
	free(this->points);
	this->points[this->numPoints - 1] = point;
}

} /* namespace Pathfinder */
