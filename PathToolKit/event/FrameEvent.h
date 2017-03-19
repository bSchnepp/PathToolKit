/*
 * FrameEvent.h
 *
 *  Created on: Feb 20, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef FRAMEEVENT_H_
#define FRAMEEVENT_H_

#include "event.h"

namespace PathEvent
{

class FrameEvent : public Event
{
public:
	FrameEvent();
	virtual ~FrameEvent();
};

} /* namespace Pathfinder */

#endif /* FRAMEEVENT_H_ */
