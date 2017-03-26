/*
 * Component.cpp
 *
 *  Created on: Feb 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <PathToolKit/component.h>
#include <PathToolKit/graphic/Arc.h>
#include <PathToolKit/graphic/Circle.h>
#include <PathToolKit/graphic/gstructs.h>
#include <PathToolKit/graphic/Rectangle.h>
#include <PathToolKit/graphic/ShapeContainer.h>
#include <PathToolKit/gutil/managers/BorderLayout.h>
#include <PathToolKit/PfGraphics.h>
#include <PathToolKit/PfInstance.h>
#include <stdlib.h>
#include <iostream>

#ifdef PATHTOOLKIT_CREATE_WINDOW_MANAGER
//Include some stuff to help manage window management, Vulkan instances, all sorts of fun stuff. Requires a recent AMD graphics card, Intel iGPU, or proprietary NVIDIA drivers.
//Maybe try to pull off software rendering if HW acceleration through Vulkan isn't possible? Maybe an OpenGL stopgap? Not sure what to do, just 'get HW acceleration soon'.
//We'll abstract away the actual API itself **anyway** so might as well try.
#endif

#ifdef PATHTOOLKIT_USE_VULKAN
//Do things with managing the actual context as items in a Vulkan instance.
#else
//Otherwise, we reply on the X server to do all the hard work.
#endif

namespace PathDraw
{

Component::Component() :
		Component(nullptr)
{
}

Component::Component(Component* parent)
{

	this->children = new std::vector<PF_COMPONENT_SERIAL>();
	this->listeners = new std::vector<PathEvent::Listener*>();

	this->xpos = 0;
	this->ypos = 0;
	this->width = 10;
	this->height = 10;

	this->enabled = true;
	this->visible = true;
	this->valid = false;

	this->parent = parent;
	this->manager = new BorderLayout();
	this->instance = nullptr;
	this->container = new ShapeContainer();
	this->graphics = nullptr;

	this->preferredwidth = 10;
	this->preferredheight = 10;

	this->minimumwidth = 0;
	this->minimumheight = 0;

	this->maximumwidth = 65535;
	this->maximumheight = 65535;

	this->theme = nullptr; 		//temp, TODO
}

const std::vector<PF_COMPONENT_SERIAL> Component::GetChildren()
{
	return *(this->children);
}

Component::~Component()
{
	delete this->manager;
	delete this->children;
	delete this->listeners;
}

void Component::SetGraphics(PfGraphics* gfx)
{
	this->graphics = gfx;
}

void Component::Repaint()
{
	for (PaintableShape* n : this->container->GetItems())
	{
		PTK_Stroke stroke = n->GetStroke();
		this->graphics->AssignColor(stroke.colors);	//FIXME, gradients  + all
		uint16_t pointCount = n->GetNumPoints();
		int* xpoints = (int*) malloc(sizeof(int) * pointCount);
		int* ypoints = (int*) malloc(sizeof(int) * pointCount);
		PTK_Point* points = n->GetPoints();
		if (!n->IsArc() && !n->IsCircle())
		{
			for (int i = 0; i < pointCount; i++)
			{
				xpoints[i] = static_cast<int>(this->width * points[i].posx);
				ypoints[i] = static_cast<int>(this->height * points[i].posy);
			}
			if (n->GetFill())
				this->graphics->FillPolygon(xpoints, ypoints, pointCount);
			else
				this->graphics->DrawPolygon(xpoints, ypoints, pointCount);
		}
		else if (n->IsArc())
		{
			Arc* arc = static_cast<Arc*>(n);//We're certain this is, in fact, an Arc.
			uint16_t arcStart = arc->GetStartAngle();
			uint16_t arcAngle = arc->GetArcAngle();
			uint16_t radius = arc->GetRadius();
			if (n->GetFill())
				this->graphics->FillArc(
						static_cast<int>(this->width * points->posx),
						static_cast<int>(this->width * points->posy), radius,
						radius, static_cast<int>(arcStart),
						static_cast<int>(arcAngle));
			else
				this->graphics->DrawArc(
						static_cast<int>(this->width * points->posx),
						static_cast<int>(this->width * points->posy), radius,
						radius, static_cast<int>(arcStart),
						static_cast<int>(arcAngle));
		}
		else if (n->IsCircle())
		{
			//TODO, FIXME LATER
			Circle* circle = static_cast<Circle*>(n);
			uint16_t radius = circle->GetRadius();
			int rad = static_cast<int>(radius);	//Get the width and height of the circle. Radius here is absolute, include setting for relative and for relative only when could be cut off later. TODO

			int x = static_cast<int>(points->posx * this->width);
			int y = static_cast<int>(points->posy * this->height);
			if (n->GetFill())
				this->graphics->FillOval(x, y, rad, rad);
			else
				this->graphics->DrawOval(x, y, rad, rad);
		}
		else if (n->isRectangle())
		{
			Rectangle* rect = static_cast<Rectangle*>(n);
			int x = static_cast<int>(points->posx * this->width);
			int y = static_cast<int>(points->posy * this->height);

			int width = static_cast<int>(rect->getWidth() * this->width);
			int height = static_cast<int>(rect->getHeight() * this->height);

			if (n->GetFill())
				this->graphics->FillRect(x, y, width, height);
			else
				this->graphics->DrawRect(x, y, width, height);
		}
		else
		{
			std::cerr << "Invalid shape attempted to be drawn." << std::endl;
		}
	}
}

Frame* Component::GetRootFrame()
{
	return this->instance->GetRoot();
}

void Component::OnGraphicsUpdate(PfGraphics* graphics)
{
	//TODO
	if (graphics)
	{
		return;
	}
}

PfInstance* Component::GetInstance()
{
	return this->instance;
}

void Component::AssignInstance(PfInstance* instance)
{
	this->instance = instance;
}

void Component::AddShape(PaintableShape* shape)
{
	this->container->AddItem(shape);
}

void Component::SetWidth(uint16_t width)
{
	this->width = width;
}

void Component::SetHeight(uint16_t height)
{
	this->height = height;
}

uint16_t Component::GetHeight()
{
	return this->height;
}

uint16_t Component::GetWidth()
{
	return this->width;
}

void Refresh()
{
	//TODO
}
} /* namespace Pathfinder */
