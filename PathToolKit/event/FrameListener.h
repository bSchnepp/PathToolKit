/*
 * FrameListener.h
 *
 *  Created on: Feb 20, 2017
 *      Author: Brian Schnepp
 */

#ifndef FRAMELISTENER_H_
#define FRAMELISTENER_H_

#include "Listener.h"

namespace Pathfinder
{

class FrameListener : public Listener
{
public:
	FrameListener();
	virtual ~FrameListener();
};

} /* namespace Pathfinder */

#endif /* FRAMELISTENER_H_ */
