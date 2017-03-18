/*
 * Component.h
 *
 *  Created on: Feb 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <cstdint>
#include <vector>

#include "gutil/LayoutManager.h"
#include "event/Listener.h"

#include "structdefs.h"

namespace Pathfinder
{
class PfGraphics;
class Frame;
class Component;

class Component
{
public:
	Component();
	Component(Component* parent);
	virtual ~Component();

	void GetComponentID();

	Component* GetChild(unsigned long long int id);

	const std::vector<PF_COMPONENT_SERIAL> GetChildren();

	void AssignListener(Listener* listener);
	void AssignLayout(LayoutManager* layout);

	void AddComponent(Component* component);
	void AddComponent(Component* component, int index);

	void RemoveComponent(Component* component);
	void RemoveComponent(unsigned long long int id);

	Listener* GetListener(int id);
	std::vector<Listener>* GetListeners();

	void RemoveListener(int id);
	void RemoveListener(Listener* listener);

	void OptimizeListeners();

	void repaint();

protected:
	virtual void OnGraphicsUpdate(PfGraphics* graphics);

	/* Serialization, so we can keep track of the frames and whatnot... too many components will seriously slow down the system, but we can fix that later.
	 * Going to attempt to use structs and be slightly more wasteful with memory so that we don't go in a panic when we get 2 ^ 64 different components (aka *really* big number that you can still technically reach given enough time)
	 * Nooo, go away Cairo, we want to stay under the MIT license only.
	 */

	// TODO: We want to prefer using the heap over the stack as much as we can, so turn these all into pointers...
	// We're awful and manage memory ourselves for some reason, just because pointers are fun.

	/* This Component's ID*/
	unsigned long long int cid;

	/* This component's parent. When parent is killed, all of it's children are killed too. */
	Component* parent;

	uint16_t xpos;
	uint16_t ypos;

	uint16_t width;
	uint16_t height;

	bool visible;
	bool enabled;
	bool valid = false;

	/* Counter for the most recent item. */
	unsigned long long int childrecentid = 0;
	std::vector<PF_COMPONENT_SERIAL>* children;
	std::vector<Listener*>* listeners;

	LayoutManager* manager;
};



} /* namespace Pathfinder */

#endif /* COMPONENT_H_ */
