/*
 * Listener.h
 *
 *  Created on: Feb 20, 2017
 *      Author: Brian Schnepp
 */

#ifndef LISTENER_H_
#define LISTENER_H_

namespace Pathfinder
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
