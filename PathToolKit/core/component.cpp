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
#include <iterator>
#include <limits>

namespace Pathfinder
{

Component::Component() :
		Component(nullptr)
{
}

Component::Component(Component* parent)
{

	this->children = new std::vector<PF_COMPONENT_SERIAL>();
	this->listeners = new std::vector<Listener*>();

	unsigned long long int mx =
			std::numeric_limits<unsigned long long int>::max() - 1;
	if (childrecentid >= mx)
	{
		unsigned long long int avID = 0;
		for (unsigned long long int i = 0; i < mx; i++)
		{
			//Worst-case scenario... we have to check through __all__ the things to desperately try to find an ID that's not taken.
			//Aka, *very* long load times for any new Components.
			//At this point, you should probably just restart the application, because you've now just used 2 ^ 64 components as children of this one, which is a really big number, totally ridiculous, and this isn't meant to be a serious or long standing thing.
			for (unsigned long long int i = 0; i < this->children->size(); i++)
			{
				//  This is TODO code.
				//  Sort our list of things by their ID, then look for any holes between numbers (ie, between 3 and 5 leaves 4.)

				//EDIT:
				//We're far from stable, expect this whole thing to be cleaned up eventually.
				avID++;
			}
		}
	}
	else
	{
		this->cid = ++childrecentid;
		children->push_back(
		{ this, this->cid });


	}
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
}

const std::vector<PF_COMPONENT_SERIAL> Component::GetChildren()
{
	return *(this->children);
}

Component::~Component()
{
	for (unsigned long long int i = 0; i < children->size(); i++)
	{

		if ((children->at(i)).cid == this->cid)
		{
			children->erase(children->begin() + i);
		}
	}
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
		int* xpoints = (int*)malloc(sizeof(int) * pointCount);
		int* ypoints = (int*)malloc(sizeof(int) * pointCount);
		PTK_Point* points = n->GetPoints();
		if (pointCount > 1)
		{
			if (n->GetFill())
			{

				for (int i = 0; i < pointCount; i++)
				{
					xpoints[i] = static_cast<int>(this->width * points[i].posx);
					ypoints[i] = static_cast<int>(this->height * points[i].posy);
				}
				this->graphics->FillPolygon(xpoints, ypoints, pointCount);
			}
			else
			{
				for (int i = 0; i < pointCount; i++)
				{
					xpoints[i] = static_cast<int>(this->width * points[i].posx);
					ypoints[i] = static_cast<int>(this->height * points[i].posy);
				}
				//this->graphics->DrawPolygon(xpoints, ypoints, pointCount);		TODO
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

} /* namespace Pathfinder */
