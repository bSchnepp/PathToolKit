/*
 * frame.h
 *
 *  Created on: Feb 18, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef FRAME_H_
#define FRAME_H_

#include "PfInstance.h"
#include "component.h"
#include <string>
#include <X11/Xlib.h>
#include <xcb/xcb.h>

/**
 * Base class for a frame on Pathfinder
 *  You must create a PfInstance first, then bind this frame to it. You should __not__ need to call AssignInstance.
 */
namespace Pathfinder
{
class PfInstance;
class Frame: public Component
{
public:
	Frame();
	Frame(std::string title);

	virtual ~Frame();

	/** Sets the size of the frame in pixels. */
	void SetSize(unsigned int w, unsigned int h);

	/** Sets the position on the screen of the frame. */
	void SetPos(uint16_t x, uint16_t y);

	/** Sets the border width of this frame. */
	void SetBorderWidth(int w);

	/** Gets the width of this frame. */
	int GetWidth();

	/** Gets the height of this frame. */
	int GetHeight();

	/** Gets the X-coodinate of this frame */
	int GetPosX();

	/** Gets the Y-coordinate of this frame. */
	int GetPosY();

	/** Gets the border width of this frame */
	int GetBorderWidth();

	/** Reassigns a PfInstance to this frame. Note that by default, there is none. This should be called by the PfInstance, so don't worry about this. */
	void AssignInstance(PfInstance* instance);

	/** Gets the window object... */
	uint32_t GetWindow();

	/** Sets up whatever it needs, then actually creates/displays the window.*/
	void CreateWindow();

	/* Sets the title of the frame to something else. */
	void SetTitle(char const* newTitle);	//Something's wrong with G++ here, so...

protected:
	uint32_t frame;
	std::string title;
	PfInstance* instance;
	uint32_t window;

private:
	int bwidth;
};
}

#endif /* FRAME_H_ */
