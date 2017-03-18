/*
 * structdefs.h
 *
 *  Created on: Feb 23, 2017
 *      Author: Brian Schnepp
 */

#ifndef STRUCTDEFS_H_
#define STRUCTDEFS_H_

namespace Pathfinder
{
class Component;
typedef struct PF_COMPONENT_SERIAL
{
	const Pathfinder::Component* component;
	unsigned long long int cid;
} PF_COMPONENT_SERIAL;
}


#endif /* STRUCTDEFS_H_ */
