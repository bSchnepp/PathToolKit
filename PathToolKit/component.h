/*
 * Component.h
 *
 *  Created on: Feb 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <PathToolKit/event/Listener.h>
#include <PathToolKit/themes/Theme.h>
#include <cstdint>
#include <vector>

namespace PathDraw
{
class PaintableShape;
class LayoutManager;
class PfInstance;
class ShapeContainer;
} /* namespace Pathfinder */

namespace PathDraw
{
class PfGraphics;
class Frame;
class Component;

class Component
{
public:
	/** Creates a new component, with no parent. */
	Component();

	/** Creates a component with a parent component, in which this will terminate if the parent does. */
	Component(Component* parent);

	virtual ~Component();

	/**
	 * Gets the children of this component.
	 */
	const std::vector<Component> GetChildren();

	/** Adds a listener to this component, in which it will do something if something is done to the component. */
	void AssignListener(PathEvent::Listener* listener);

	/** Assigns a layout to this component. */
	void AssignLayout(LayoutManager* layout);

	/** Adds a component to this component, as a child. */
	void AddComponent(Component* component);

	/** Adds a component at a specific location as a child. */
	void AddComponent(Component* component, int index);

	/** Remove a component by reference. */
	void RemoveComponent(Component* component);

	/** Removes a component based on it's index. */
	void RemoveComponent(unsigned long long int id);

	/** Grabs a listener. */
	PathEvent::Listener* GetListener(int id);

	/** Grabs a pointer to a vector with all listeners in the component. */
	std::vector<PathEvent::Listener>* GetListeners();

	void RemoveListener(int id);
	void RemoveListener(PathEvent::Listener* listener);

	void OptimizeListeners();

	/** Re-draws all of the content of this component. Should flush before and after calling this. */
	void Repaint();

	/** Re-assigns the sizes of all the content in this component based on the top-level window. Should be called by LayoutManager after window event.*/
	void Refresh();

	/** Reassigns a PfInstance to this component. Note that by default, there is none. This should be called by the PfInstance, so don't worry about this. */
	virtual void AssignInstance(PfInstance* instance);

	Frame* GetRootFrame();

	void SetGraphics(PfGraphics* gfx);

	void AddShape(PaintableShape* shape);

	void SetWidth(uint16_t width);
	void SetHeight(uint16_t height);
	uint16_t GetHeight();
	uint16_t GetWidth();

	uint16_t GetMinHeight();
	uint16_t GetMinWidth();

	uint16_t GetMaxHeight();
	uint16_t GetMaxWidth();



	PfInstance* GetInstance();

protected:
	virtual void OnGraphicsUpdate(PfGraphics* graphics);

	// TODO: We want to prefer using the heap over the stack as much as we can, so turn these all into pointers...
	// We're awful and manage memory ourselves for some reason, just because pointers are fun.
	/* This component's parent. When parent is killed, all of it's children are killed too. */
	Component* parent;

	uint16_t xpos;
	uint16_t ypos;

	uint16_t width;
	uint16_t height;

	uint16_t minimumwidth;
	uint16_t minimumheight;

	uint16_t maximumwidth;
	uint16_t maximumheight;

	bool visible;
	bool enabled;
	bool valid = false;

	Theme* theme;

	/* Counter for the most recent item. */
	unsigned long long int childrecentid = 0;
	std::vector<Component>* children;
	std::vector<PathEvent::Listener*>* listeners;

	ShapeContainer* container;
	LayoutManager* manager;

	PfInstance* instance;
	PfGraphics* graphics;
};

} /* namespace Pathfinder */

#endif /* COMPONENT_H_ */
