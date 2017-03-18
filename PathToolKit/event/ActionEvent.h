/*
 * ActionEvent.h
 *
 *  Created on: Feb 19, 2017
 *      Author: Brian Schnepp
 */

#ifndef ACTIONEVENT_H_
#define ACTIONEVENT_H_

#include "event.h"

namespace Pathfinder
{

class ActionEvent : public Event
{
public:
	ActionEvent();
	virtual ~ActionEvent();
};

} /* namespace Pathfinder */

#endif /* ACTIONEVENT_H_ */
