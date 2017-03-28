/*
 * BorderLayout.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <PathToolKit/component.h>
#include <PathToolKit/gutil/managers/BorderLayout.h>

namespace PathDraw
{

BorderLayout::BorderLayout()
{
	this->xgap = 0;
	this->ygap = 0;

}

BorderLayout::~BorderLayout()
{
	// TODO Auto-generated destructor stub
}

void BorderLayout::UpdateSize(int width, int height)
{
	LayoutManager::UpdateSize(width, height);
	//BorderLayout disregards maximum size entirely.

	//Center
	uint16_t cwidth, cheight;

	//Min check
	width > this->components[this->CENTER]->GetMinWidth() ?
			cwidth = static_cast<uint16_t>(width) : cwidth =
					this->components[this->CENTER]->GetMinWidth();

	height > this->components[this->CENTER]->GetMinHeight() ?
			cheight = static_cast<uint16_t>(height) : cheight =
					this->components[this->CENTER]->GetMinHeight();

	this->components[this->CENTER]->SetHeight(cheight);
	this->components[this->CENTER]->SetWidth(cwidth);

	// NORTH and SOUTH are always minimum height.
	// EAST and WEST are always minimum width.

	uint16_t wwidth;
	uint16_t ewidth;

	uint16_t nheight;
	uint16_t sheight;

	wwidth = this->components[this->WEST]->GetMinWidth();
	ewidth = this->components[this->EAST]->GetMinWidth();

	nheight = this->components[this->NORTH]->GetMinHeight();
	sheight = this->components[this->SOUTH]->GetMinHeight();

	this->components[this->WEST]->SetWidth(wwidth);
	this->components[this->EAST]->SetWidth(ewidth);

	this->components[this->NORTH]->SetHeight(nheight);
	this->components[this->SOUTH]->SetHeight(sheight);

	// And the rest is ignored to fit the component.

	//uint16_t nsheight = this->components[this->NORTH]->GetHeight() > this->components[this->SOUTH]->GetHeight() ? this->components[this->NORTH]->GetHeight() : this->components[this->SOUTH]->GetHeight();
	//uint16_t wewidth = ;	TODO

	this->components[this->WEST]->SetHeight(
			static_cast<uint16_t>((height - cheight) / 2));
	this->components[this->EAST]->SetHeight(
			static_cast<uint16_t>((height - cheight) / 2));

	this->components[this->NORTH]->SetWidth(
			static_cast<uint16_t>((width - cwidth) / 2));
	this->components[this->SOUTH]->SetWidth(
			static_cast<uint16_t>((width - cwidth) / 2));

	//TODO: placement of components, ahhh this'll be fun...
}

} /* namespace Pathfinder */
