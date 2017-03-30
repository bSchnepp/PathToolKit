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
#include <PathToolKit/graphic/Shape.h>
#include <PathToolKit/graphic/ShapeContainer.h>
#include <PathToolKit/gutil/managers/BorderLayout.h>
#include <PathToolKit/PfGraphics.h>
#include <PathToolKit/PfInstance.h>
#include <stdlib.h>
#include <sys/types.h>
#include <xcb/xcb.h>
#include <xcb/xproto.h>
#include <iostream>

#ifdef PATHTOOLKIT_CREATE_WINDOW_MANAGER
//Include some stuff to help manage window management, Vulkan instances, all sorts of fun stuff. Requires a recent AMD graphics card, Intel iGPU, or proprietary NVIDIA drivers.
//Maybe try to pull off software rendering if HW acceleration through Vulkan isn't possible? Maybe an OpenGL stopgap? Not sure what to do, just 'get HW acceleration soon'.
//We'll abstract away the actual API itself **anyway** so might as well try.
#endif

namespace PathDraw
{

/**
 * Creates a new component with no parent.
 */
Component::Component() :
		Component(nullptr)
{
}

/*
 * Creates a component with a parent.
 * @param parent: the component that this is a child of.
 */
Component::Component(Component* parent)
{

	this->children = new std::vector<Component>();
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

	this->minimumwidth = 0;
	this->minimumheight = 0;

	this->maximumwidth = 65535;
	this->maximumheight = 65535;

	this->theme = nullptr; 		//temp, TODO
	this->window = 0;	//In X, a Window is the same thing as a component: all things drawn to screen are windows.
}

const std::vector<Component> Component::GetChildren()
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
		int* xpoints = static_cast<int*>(malloc(sizeof(int) * pointCount));
		int* ypoints = static_cast<int*>(malloc(sizeof(int) * pointCount));
		PTK_Point* points = n->GetPoints();

		//Uses more memory, but is faster. Overall better code anyway. Why not.
		Arc* arc = dynamic_cast<Arc*>(n);
		if (!(arc == nullptr))
		{
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
						continue;
		}

		Circle* circle = dynamic_cast<Circle*>(n);
		if (!(circle == nullptr))
		{
			//TODO, FIXME LATER
						Circle* circle = static_cast<Circle*>(n);
						uint16_t radius = circle->GetRadius();
						int rad = static_cast<int>(radius);
						//Get the width and height of the circle. Radius here is absolute, include setting for relative and for relative only when could be cut off later. TODO

						int x = static_cast<int>(points->posx * this->width);
						int y = static_cast<int>(points->posy * this->height);
						if (n->GetFill())
							this->graphics->FillOval(x, y, rad, rad);
						else
							this->graphics->DrawOval(x, y, rad, rad);
						continue;
		}

		Rectangle* rect = dynamic_cast<Rectangle*>(n);
		if (!(rect == nullptr))
		{
			int x = static_cast<int>(points->posx * this->width);
						int y = static_cast<int>(points->posy * this->height);

						int width = static_cast<int>(rect->getWidth() * this->width);
						int height = static_cast<int>(rect->getHeight() * this->height);

						if (n->GetFill())
							this->graphics->FillRect(x, y, width, height);
						else
							this->graphics->DrawRect(x, y, width, height);

						free(points);	//In this case it's a memory leak to _not_ free it.
						continue;
		}

		Shape* shape = dynamic_cast<Shape*>(n);
		if (!(shape == nullptr))
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
						continue;
		}
		free(xpoints);
		free(ypoints);
#if 0

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
			int rad = static_cast<int>(radius);
			//Get the width and height of the circle. Radius here is absolute, include setting for relative and for relative only when could be cut off later. TODO

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

			free(points);	//In this case it's a memory leak to _not_ free it.
		}
		else
		{
			std::cerr << "Invalid shape attempted to be drawn." << std::endl;
		}
#endif
	}
}

void Component::Create()
{
	xcb_screen_t* screen = this->instance->GetScreen();
	xcb_connection_t* connection = this->instance->GetConnection();

	xcb_visualid_t visual = screen->root_visual;

	this->window = xcb_generate_id(this->instance->GetConnection());

	uint32_t mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;

	uint32_t values[2] =
	{ screen->white_pixel, XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_BUTTON_PRESS
			| XCB_EVENT_MASK_BUTTON_RELEASE | XCB_EVENT_MASK_POINTER_MOTION
			| XCB_EVENT_MASK_ENTER_WINDOW | XCB_EVENT_MASK_LEAVE_WINDOW
			| XCB_EVENT_MASK_KEY_PRESS | XCB_EVENT_MASK_KEY_RELEASE };

	xcb_create_window(connection, static_cast<uint8_t>(XCB_COPY_FROM_PARENT),
			this->window, this->parent->GetWindow(), static_cast<int16_t>(this->xpos),
			static_cast<int16_t>(this->ypos),
			static_cast<uint16_t>(this->GetWidth()),
			static_cast<uint16_t>(this->GetHeight()),
			static_cast<uint16_t>(0),
			static_cast<uint16_t>(XCB_WINDOW_CLASS_INPUT_OUTPUT), visual, mask,
			values);

	xcb_map_window(this->instance->GetConnection(), this->window);
	xcb_flush(this->instance->GetConnection());
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

void Component::AssignLayout(LayoutManager* layout)
{
	delete this->manager;
	this->manager = layout;
}

void Component::Refresh()
{
	//TODO
	//Size cannot ever be more than it's maximum size,
	//Cannot be less than it's minimum size,
	//And we'll actually enforce this: undefined behavior if a component can't fit.
	this->manager->UpdateSize(this->width, this->height);
	//Use private variables to check the width and height on the previous refresh call: if they're different, go through the list of listeners and fire all ComponentResized events.
}

uint16_t Component::GetMinHeight()
{
	return this->minimumheight;
}

uint16_t Component::GetMinWidth()
{
	return this->minimumwidth;
}

uint16_t Component::GetMaxHeight()
{
	return this->maximumheight;
}

uint16_t Component::GetMaxWidth()
{
	return this->maximumwidth;
}

uint32_t Component::GetWindow()
{
	return this->window;
}

uint32_t Component::GetParentWindow()
{
	return this->parent->GetWindow();
}

void Component::SetParent(Component* component)
{
	xcb_reparent_window(this->GetInstance()->GetConnection(), this->window, component->GetWindow(), this->xpos, this->ypos);
}

Component* Component::GetParent()
{
	return this->parent;
}

} /* namespace Pathfinder */
