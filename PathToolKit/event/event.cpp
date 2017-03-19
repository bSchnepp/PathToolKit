/*
 * event.cpp
 *
 *  Created on: Feb 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include "event.h"
#include "../component.h"

#include "xcb/xcb.h"

namespace PathEvent
{

Event::Event() :
		Event::Event(nullptr)
{
}

Event::Event(PathDraw::Component* source)
{
	this->source = source;
	PF_KeyDown_t* keys = new PF_KeyDown_t;	//TODO
	this->keysDown = keys;
}

Event::~Event()
{
	delete this->keysDown;
	/* We do NOT delete the component, because it could still be in use. */
}

} /* namespace Pathfinder */
