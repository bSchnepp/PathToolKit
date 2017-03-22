/*
 * PfGraphics.cpp
 *
 *  Created on: Feb 18, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <PathToolKit/frame.h>
#include <PathToolKit/PfGraphics.h>
#include <sys/types.h>
#include <xcb/xcb.h>
#include <xcb/xproto.h>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <vector>

namespace PathDraw
{

PfGraphics::PfGraphics()
{
	this->gcontext = 0;
	this->instance = nullptr;
	this->component = nullptr;
	this->mask = XCB_GC_FOREGROUND;
	this->value = new uint32_t[2];
	this->colormap = nullptr;
}

PfGraphics::PfGraphics(PfInstance* const instance)
{
	this->gcontext = 0;
	this->instance = nullptr;
	this->component = nullptr;
	this->mask = XCB_GC_FOREGROUND;
	this->value = new uint32_t[2];
	this->colormap = nullptr;
	this->AssignInstance(instance);
}

void PfGraphics::AssignInstance(PfInstance* const instance)
{
	this->instance = instance;
	xcb_connection_t* id = this->instance->GetConnection();
	this->gcontext = xcb_generate_id(id);

	this->colormap = &(this->instance->GetScreen()->default_colormap);
	*(this->colormap) = this->instance->GetScreen()->default_colormap;
	xcb_create_colormap(this->instance->GetConnection(), XCB_COLORMAP_ALLOC_NONE, *(this->colormap),
			this->instance->GetScreen()->root, this->instance->GetScreen()->root_visual);

	this->gcontext = xcb_generate_id(this->instance->GetConnection());
}

void PfGraphics::AssignColor(Color* color)
{
	xcb_connection_t* connection = this->instance->GetConnection();
	xcb_alloc_color_reply_t* color_reply = xcb_alloc_color_reply(connection,
			xcb_alloc_color(connection, *(this->colormap),
					static_cast<uint16_t>(color->GetRed() << 0),
					static_cast<uint16_t>(color->GetGreen() << 0),
					static_cast<uint16_t>((color->GetBlue() << 0))),
			NULL);

	//TODO
	free(color_reply);
	//

	uint32_t mask = XCB_GC_FOREGROUND;
	uint32_t value[] =
	{ this->instance->GetScreen()->black_pixel };
	xcb_create_gc(connection, this->gcontext, this->instance->GetScreen()->root, mask, value);
}

void PfGraphics::AssignComponent(Component* component)
{
	this->component = component;
	component->SetGraphics(this);
}

void PfGraphics::DrawArc(int x, int y, int width, int height, int startAngle,
		int arcAngle)
{
	uint32_t rootWindow = this->instance->GetRoot()->GetWindow();
	xcb_arc_t arc =
	{ static_cast<int16_t>(x), static_cast<int16_t>(y),
			static_cast<uint16_t>(width), static_cast<uint16_t>(height),
			static_cast<int16_t>(startAngle << 6), static_cast<int16_t>(arcAngle
					<< 6) };
	xcb_poly_arc(this->instance->GetConnection(), rootWindow,
			this->gcontext, 2, &arc);
}

void PfGraphics::FillArc(int x, int y, int width, int height, int startAngle,
		int arcAngle)
{
	uint32_t rootWindow = this->instance->GetRoot()->GetWindow();

	xcb_arc_t arc =
	{ static_cast<int16_t>(x), static_cast<int16_t>(y),
			static_cast<uint16_t>(width), static_cast<uint16_t>(height),
			static_cast<int16_t>(startAngle << 6), static_cast<int16_t>(arcAngle
					<< 6) };

	printf("Hello, world!");


	xcb_poly_fill_arc(this->instance->GetConnection(), rootWindow,
			this->gcontext, 2, &arc);


}

void PfGraphics::DrawRect(int x, int y, int width, int height)
{

	uint32_t rootWindow = this->instance->GetRoot()->GetWindow();

	xcb_rectangle_t rectangle =
	{ static_cast<int16_t>(x), static_cast<int16_t>(y),
			static_cast<uint16_t>(width), static_cast<uint16_t>(height) };
	xcb_poly_rectangle(this->instance->GetConnection(),
			rootWindow, this->gcontext, 2, &rectangle);
}

void PfGraphics::FillRect(int x, int y, int width, int height)
{
	uint32_t rootWindow = this->instance->GetRoot()->GetWindow();

	xcb_rectangle_t rectangle =
	{ static_cast<int16_t>(x), static_cast<int16_t>(y),
			static_cast<uint16_t>(width), static_cast<uint16_t>(height) };
	xcb_poly_fill_rectangle(this->instance->GetConnection(),
			rootWindow, this->gcontext, 2, &rectangle);
}

void PfGraphics::DrawOval(int x, int y, int width, int height)
{

	uint32_t rootWindow = this->instance->GetRoot()->GetWindow();

	xcb_arc_t arc =
	{ static_cast<int16_t>(x), static_cast<int16_t>(y),
			static_cast<uint16_t>(width), static_cast<uint16_t>(height),
			static_cast<int16_t>(0 << 6), static_cast<int16_t>(360 << 6) };
	xcb_poly_arc(this->instance->GetConnection(), rootWindow,
			this->gcontext, 2, &arc);
}

void PfGraphics::FillOval(int x, int y, int width, int height)
{
	uint32_t rootWindow = this->instance->GetRoot()->GetWindow();

	xcb_arc_t arc =
	{ static_cast<int16_t>(x), static_cast<int16_t>(y),
			static_cast<uint16_t>(width), static_cast<uint16_t>(height),
			static_cast<int16_t>(0 << 6), static_cast<int16_t>(360 << 6) };
	xcb_poly_fill_arc(this->instance->GetConnection(), rootWindow,
			this->gcontext, 2, &arc);
}

void PfGraphics::DrawPolygon(int* xpoints, int* ypoints, int npoints)
{

	uint32_t rootWindow = this->instance->GetRoot()->GetWindow();

	std::vector<xcb_point_t>* points = new std::vector<xcb_point_t>();
	for (int i = 0; i < npoints; i++)
	{
		xcb_point_t p =
		{ static_cast<int16_t>(xpoints[i]), static_cast<int16_t>(ypoints[i]) };
		points->push_back(p);
	}
	xcb_point_t org =
	{
			static_cast<int16_t>(xpoints[0]),
			static_cast<int16_t>(ypoints[0])
	};
	points->push_back(org);
	xcb_point_t* pa = &points->at(0);
	xcb_poly_line(this->instance->GetConnection(), XCB_COORD_MODE_ORIGIN, rootWindow,
			this->gcontext, npoints + 1, pa);
	delete points;
}

void PfGraphics::FillPolygon(int* xpoints, int* ypoints, int npoints)
{

	uint32_t rootWindow = this->instance->GetRoot()->GetWindow();

	std::vector<xcb_point_t>* points = new std::vector<xcb_point_t>();
	for (int i = 0; i < npoints; i++)
	{
		xcb_point_t p =
		{ static_cast<int16_t>(xpoints[i]), static_cast<int16_t>(ypoints[i]) };
		points->push_back(p);
	}
	xcb_point_t* pa = &points->at(0);
	xcb_fill_poly(this->instance->GetConnection(), rootWindow,
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
