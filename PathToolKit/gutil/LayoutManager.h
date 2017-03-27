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
class Component;

class LayoutManager
{
	//TODO
public:
	LayoutManager();
	virtual ~LayoutManager();

	void Add(Component* component);
	virtual void UpdateSize(int width, int height);

private:
	int width;
	int height;
	//Partition the sizes based on the stuff here.
};

} /* namespace Pathfinder */

#endif /* LAYOUTMANAGER_H_ */
