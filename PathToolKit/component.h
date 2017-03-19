/*
 * Component.h
 *
 *  Created on: Feb 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <event/Listener.h>
#include <structdefs.h>
#include <cstdint>
#include <vector>

namespace Pathfinder
{
class PaintableShape;
} /* namespace Pathfinder */

namespace Pathfinder
{
class LayoutManager;
class PfInstance;
class ShapeContainer;
} /* namespace Pathfinder */

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
	void Repaint();

	/** Reassigns a PfInstance to this component. Note that by default, there is none. This should be called by the PfInstance, so don't worry about this. */
	virtual void AssignInstance(PfInstance* instance);

	Frame* GetRootFrame();

	void SetGraphics(PfGraphics* gfx);

	void AddShape(PaintableShape* shape);

	void SetWidth(uint16_t width);
	void SetHeight(uint16_t height);
	uint16_t GetHeight();
	uint16_t GetWidth();

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

	ShapeContainer* container;
	LayoutManager* manager;

	PfInstance* instance;
	PfGraphics* graphics;
};



} /* namespace Pathfinder */

#endif /* COMPONENT_H_ */
