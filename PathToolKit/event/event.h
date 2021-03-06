/*
 * event.h
 *
 *  Created on: Feb 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "../component.h"
#include <cstdint>

namespace PathEvent
{

/** Because packed structs tend to be compiler-specific, this is a mess of memory. Not too bad though, promise. */
typedef struct PF_KeyDown_t
{
	uint8_t wasLShiftDown;
	uint8_t wasRShiftDown;
	uint8_t wasLCtrlDown;
	uint8_t wasRCtrlDown;
	uint8_t wasLAltDown;
	uint8_t wasRAltDown;
	uint8_t wasTabDown;
	uint8_t wasEnterDown;

	uint8_t mainKeyDown;
} PF_KeyDown_t;

typedef struct PF_Mouse_Location_t
{
	uint16_t xpos;
	uint16_t ypos;
} PF_Mouse_Location_t;

class Event
{
public:
	Event();
	Event(PathDraw::Component* source);

	//Implement a way to update the KeyDown thing here.
	virtual ~Event();

	PathDraw::Component* GetSource();
	PF_KeyDown_t* GetKeys();

private:
	PathDraw::Component* source;
	PF_KeyDown_t* keysDown;
};

} /* namespace Pathfinder */

#endif /* EVENT_H_ */
