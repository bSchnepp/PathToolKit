/*
 * Component.cpp
 *
 *  Created on: Feb 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <component.h>
#include <graphic/PaintableShape.h>
#include <graphic/ShapeContainer.h>
#include <gutil/managers/BorderLayout.h>
#include <PfGraphics.h>
#include <PfInstance.h>
#include <stdlib.h>
#include <iostream>
#include <iterator>
#include <limits>

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
		uint16_t pointCount = n->GetNumPoints();
		int* xpoints = (int*) malloc(sizeof(int) * pointCount);
		int* ypoints = (int*) malloc(sizeof(int) * pointCount);
		PTK_Point* points = n->GetPoints();
		if (pointCount > 1)
		{
			if (n->GetFill())
			{

				for (int i = 0; i < pointCount; i++)
				{
					xpoints[i] = static_cast<int>(this->width * points[i].posx);
					ypoints[i] =
							static_cast<int>(this->height * points[i].posy);
				}
				this->graphics->FillPolygon(xpoints, ypoints, pointCount);
			}
			else
			{
				for (int i = 0; i < pointCount; i++)
				{
					xpoints[i] = static_cast<int>(this->width * points[i].posx);
					ypoints[i] =
							static_cast<int>(this->height * points[i].posy);
				}
				this->graphics->DrawPolygon(xpoints, ypoints, pointCount);
			}

		}
		else
		{

		}
	}
}

Frame* Component::GetRootFrame()
{
	return this->instance->GetRoot();
}

void Component::OnGraphicsUpdate(PfGraphics* graphics)
{
	graphics->Repaint();
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
} /* namespace Pathfinder */
