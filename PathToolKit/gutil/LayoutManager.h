/*
 * LayoutManager.h
 *
 *  Created on: Feb 20, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef LAYOUTMANAGER_H_
#define LAYOUTMANAGER_H_

namespace PathDraw
{
struct PF_COMPONENT_SERIAL;
} /* namespace PathDraw */

namespace PathDraw
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
