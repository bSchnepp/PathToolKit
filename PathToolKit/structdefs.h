/*
 * structdefs.h
 *
 *  Created on: Feb 23, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef STRUCTDEFS_H_
#define STRUCTDEFS_H_

namespace Pathfinder
{
class Component;
typedef struct PF_COMPONENT_SERIAL
{
	const Pathfinder::Component* component;
} PF_COMPONENT_SERIAL;
}


#endif /* STRUCTDEFS_H_ */
