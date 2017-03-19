/*
 * Listener.h
 *
 *  Created on: Feb 20, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef LISTENER_H_
#define LISTENER_H_

namespace PathEvent
{

class Listener
{
public:
	Listener();
	virtual ~Listener();

	void AssignFunction(void* function);

protected:
	void* function;
};

} /* namespace Pathfinder */

#endif /* LISTENER_H_ */
