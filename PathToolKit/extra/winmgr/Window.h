/*
 * Window.h
 *
 *  Created on: Mar 29, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_EXTRA_WINMGR_WINDOW_H_
#define PATHTOOLKIT_EXTRA_WINMGR_WINDOW_H_

#include <string>

namespace PathDraw
{
class Component;
} /* namespace PathDraw */

//TODO: Manage windows.

namespace Pathfinder
{

class Window
{
public:
	Window(std::string title);
	virtual ~Window();

private:
	PathDraw::Component* topbar;
	PathDraw::Component* content;

	std::string title;
};

} /* namespace Pathfinder */

#endif /* PATHTOOLKIT_EXTRA_WINMGR_WINDOW_H_ */
