/*
 * BasicFrame.cpp
 *
 *  Created on: Mar 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <PathToolKit/extra/BasicFrame.h>
#include <PathToolKit/PfGraphics.h>
#include <PathToolKit/PfInstance.h>

#include <iostream>

namespace PathExtension
{

BasicFrame::BasicFrame() :
		PathDraw::Frame()
{
	this->instance = new PathDraw::PfInstance();
	this->graphics = new PathDraw::PfGraphics(this->instance);
	this->graphics->AssignComponent(this);
	this->AssignInstance(this->instance);
	this->instance->MakeFrame(this);
}

BasicFrame::BasicFrame(std::string title) :
		PathDraw::Frame(title)
{
	this->title = title;
	this->instance = new PathDraw::PfInstance();
	this->graphics = new PathDraw::PfGraphics(this->instance);
	this->graphics->AssignComponent(this);
	this->AssignInstance(this->instance);
	this->instance->MakeFrame(this);
}

PathDraw::PfGraphics* BasicFrame::GetGraphics()
{
	return this->graphics;
}

PathDraw::PfInstance* BasicFrame::GetInstance()
{
	return this->instance;
}

BasicFrame::~BasicFrame()
{
	delete this->graphics;
	delete this->instance;
}

} /* namespace PathExtension */
