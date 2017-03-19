/*
 * ActionEvent.h
 *
 *  Created on: Feb 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef ACTIONEVENT_H_
#define ACTIONEVENT_H_

#include "event.h"

namespace PathEvent
{

class ActionEvent : public Event
{
public:
	ActionEvent();
	virtual ~ActionEvent();
};

} /* namespace Pathfinder */

#endif /* ACTIONEVENT_H_ */
