/*
 * Component.cpp
 *
 *  Created on: Feb 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include "../component.h"
#include "../structdefs.h"
#include "../PfGraphics.h"
#include "../gutil/LayoutManager.h"
#include "../gutil/managers/BorderLayout.h"
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
#ifdef _DEBUG_
			std::cout << "Deleted a Component!" << std::endl;
#endif
		}
	}
	delete this->manager;
	delete this->children;
	delete this->listeners;
}

void Component::repaint()
{
	//TODO
}

void Component::OnGraphicsUpdate(PfGraphics* graphics)
{
	graphics->Repaint();
}

} /* namespace Pathfinder */
