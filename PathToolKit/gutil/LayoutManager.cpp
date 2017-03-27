/*
 * LayoutManager.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <PathToolKit/gutil/LayoutManager.h>

namespace PathDraw
{

LayoutManager::LayoutManager()
{
	this->height = 10000;
	this->width = 10000;	//TODO
}

void LayoutManager::UpdateSize(int width, int height)
{
	this->height = height;
	this->width = width;
	//Subclasses should then resize components and all.
}

LayoutManager::~LayoutManager()
{
	// TODO Auto-generated destructor stub
}

} /* namespace Pathfinder */
