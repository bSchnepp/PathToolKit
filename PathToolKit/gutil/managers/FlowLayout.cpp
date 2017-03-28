/*
 * FlowLayout.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <PathToolKit/gutil/managers/FlowLayout.h>

namespace PathDraw
{

FlowLayout::FlowLayout()
{
	this->components = new std::vector<Component>();
	this->xgap = 0;
	this->ygap = 0;
}

void FlowLayout::UpdateSize(int width, int height)
{
	width++;
	height++;
	//TODO
}

FlowLayout::~FlowLayout()
{
	delete this->components;
}

} /* namespace PathDraw */
