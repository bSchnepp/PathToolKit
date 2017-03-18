/*
 * LayoutManager.h
 *
 *  Created on: Feb 20, 2017
 *      Author: Brian Schnepp
 */

#ifndef LAYOUTMANAGER_H_
#define LAYOUTMANAGER_H_

#include "../structdefs.h"

namespace Pathfinder
{

class LayoutManager
{
	//TODO
public:
	LayoutManager();
	virtual ~LayoutManager();

	void Add(PF_COMPONENT_SERIAL* component);
};

} /* namespace Pathfinder */

#endif /* LAYOUTMANAGER_H_ */
