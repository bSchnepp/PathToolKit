/*
 * PfGraphics.cpp
 *
 *  Created on: Feb 18, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include "../PfGraphics.h"
#include "../gutil/Color.h"

#include <xcb/xcb.h>
#include <vector>

#include <cstdlib>
#include <iostream>

namespace Pathfinder
{

PfGraphics::PfGraphics()
{

	this->gcontext = 0;
	this->instance = nullptr;
	this->frame = nullptr;
	this->mask = XCB_GC_FOREGROUND;
	this->value = new uint32_t[2];
	this->colormap = NULL;
}

void PfGraphics::AssignInstance(PfInstance* const instance)
{
	this->instance = instance;
	xcb_connection_t* id = this->instance->GetConnection();
	this->gcontext = xcb_generate_id(id);
}

void PfGraphics::AssignColor(Color* color)
{
	xcb_connection_t* connection = this->instance->GetConnection();
	xcb_screen_t* screen = this->instance->GetScreen();
	xcb_drawable_t window = screen->root;
	this->colormap = &(this->instance->GetScreen()->default_colormap);


	*(this->colormap) = this->instance->GetScreen()->default_colormap;
	xcb_create_colormap(connection, XCB_COLORMAP_ALLOC_NONE, *(this->colormap),
			window, screen->root_visual);

	/* Had to fight with this, we're using auto because G++ can't figure out what we mean here or something. Thus, needs C++11 or later.*/
	auto reply = xcb_alloc_color_reply(connection,
			xcb_alloc_color(connection, *(this->colormap),
					static_cast<uint16_t>(color->GetRed() << 0),
					static_cast<uint16_t>(color->GetGreen() << 0),
					static_cast<uint16_t>((color->GetBlue() << 0))),
			NULL);

	this->gcontext = xcb_generate_id(connection);
	uint32_t mask = XCB_GC_FOREGROUND;
	uint32_t value[] =
	{ screen->black_pixel };
	reply++;

	Color* c2 = color->Darker();
	delete c2;

	xcb_create_gc(connection, this->gcontext, window, mask, value);
}

void PfGraphics::AssignFrame(Frame* frame)
{
	this->frame = frame;
}

void PfGraphics::DrawArc(int x, int y, int width, int height, int startAngle,
		int arcAngle)
{
	xcb_arc_t arc =
	{ static_cast<int16_t>(x), static_cast<int16_t>(y),
			static_cast<uint16_t>(width), static_cast<uint16_t>(height),
			static_cast<int16_t>(startAngle << 6), static_cast<int16_t>(arcAngle
					<< 6) };
	xcb_poly_arc(this->instance->GetConnection(), this->frame->GetWindow(),
			this->gcontext, 2, &arc);
}

void PfGraphics::FillArc(int x, int y, int width, int height, int startAngle,
		int arcAngle)
{
	xcb_arc_t arc =
	{ static_cast<int16_t>(x), static_cast<int16_t>(y),
			static_cast<uint16_t>(width), static_cast<uint16_t>(height),
			static_cast<int16_t>(startAngle << 6), static_cast<int16_t>(arcAngle
					<< 6) };
	xcb_poly_fill_arc(this->instance->GetConnection(), this->frame->GetWindow(),
			this->gcontext, 2, &arc);
}

void PfGraphics::DrawRect(int x, int y, int width, int height)
{
	xcb_rectangle_t rectangle =
	{ static_cast<int16_t>(x), static_cast<int16_t>(y),
			static_cast<uint16_t>(width), static_cast<uint16_t>(height) };
	xcb_poly_rectangle(this->instance->GetConnection(),
			this->frame->GetWindow(), this->gcontext, 2, &rectangle);
}

void PfGraphics::FillRect(int x, int y, int width, int height)
{
	xcb_rectangle_t rectangle =
	{ static_cast<int16_t>(x), static_cast<int16_t>(y),
			static_cast<uint16_t>(width), static_cast<uint16_t>(height) };
	xcb_poly_fill_rectangle(this->instance->GetConnection(),
			this->frame->GetWindow(), this->gcontext, 2, &rectangle);
}

void PfGraphics::DrawOval(int x, int y, int width, int height)
{
	xcb_arc_t arc =
	{ static_cast<int16_t>(x), static_cast<int16_t>(y),
			static_cast<uint16_t>(width), static_cast<uint16_t>(height),
			static_cast<int16_t>(0 << 6), static_cast<int16_t>(360 << 6) };
	xcb_poly_arc(this->instance->GetConnection(), this->frame->GetWindow(),
			this->gcontext, 2, &arc);
}

void PfGraphics::FillOval(int x, int y, int width, int height)
{
	xcb_arc_t arc =
	{ static_cast<int16_t>(x), static_cast<int16_t>(y),
			static_cast<uint16_t>(width), static_cast<uint16_t>(height),
			static_cast<int16_t>(0 << 6), static_cast<int16_t>(360 << 6) };
	xcb_poly_fill_arc(this->instance->GetConnection(), this->frame->GetWindow(),
			this->gcontext, 2, &arc);
}

void PfGraphics::FillPolygon(int* xpoints, int* ypoints, int npoints)
{
	std::vector<xcb_point_t>* points = new std::vector<xcb_point_t>();
	for (int i = 0; i < npoints; i++)
	{
		xcb_point_t p =
		{ static_cast<int16_t>(xpoints[i]), static_cast<int16_t>(ypoints[i]) }; /* Using dirty hacks to ensure we fit the C++14 standard correctly. We're making a waste here, this can be fixed later.*/
		points->push_back(p);
	}
	xcb_point_t* pa = &points->at(0);
	xcb_fill_poly(this->instance->GetConnection(), this->frame->GetWindow(),
			this->gcontext, XCB_POLY_SHAPE_COMPLEX, XCB_COORD_MODE_ORIGIN,
			npoints, pa);
	delete points;
}

void PfGraphics::Repaint()
{
	xcb_flush(this->instance->GetConnection());
}

PfGraphics::~PfGraphics()
{
	free(this->colormap);
	delete[] this->value;
}

} /* namespace Pathfinder */
