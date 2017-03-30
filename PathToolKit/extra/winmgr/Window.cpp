/*
 * Window.cpp
 *
 *  Created on: Mar 29, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <PathToolKit/extra/winmgr/Window.h>

namespace Pathfinder
{

Window::Window(std::string title)
{
	this->title = title;
	this->topbar = nullptr;
	this->content = nullptr;
	//todo
}

Window::~Window()
{
	// TODO Auto-generated destructor stub
}

} /* namespace Pathfinder */
