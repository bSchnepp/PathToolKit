/*
 * frame.cpp
 *
 *  Created on: Feb 18, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <frame.h>
#include <xcb/xproto.h>
#include <cstdint>
#include <cstring>


namespace Pathfinder
{

Frame::Frame() :
		Frame::Frame("Untitled frame")
{
}

Frame::Frame(std::string title) :
		Component::Component()
{
	this->title = title;
	this->window = 0;
	this->frame = 0;
	this->bwidth = 0;
	this->width = 800;
	this->height = 600;
	this->instance = nullptr;
}
Frame::~Frame()
{
}

int Frame::GetPosX()
{
	return this->xpos;
}

int Frame::GetPosY()
{
	return this->ypos;
}

int Frame::GetWidth()
{
	return this->width;
}

int Frame::GetHeight()
{
	return this->height;
}

int Frame::GetBorderWidth()
{
	return this->bwidth;
}

uint32_t Frame::GetWindow()
{
	return this->window;
}

void Frame::SetSize(unsigned int w, unsigned int h)
{
	this->width = static_cast<uint16_t>(w);
	this->height = static_cast<uint16_t>(h);
}

void Frame::SetPos(uint16_t x, uint16_t y)
{
	this->xpos = static_cast<uint16_t>(x << 6);
	this->ypos = static_cast<uint16_t>(y << 6);
}

void Frame::SetBorderWidth(int w)
{
	this->bwidth = w;
}

void Frame::SetTitle(const char* newTitle)
{
	this->title = newTitle;
	xcb_change_property(this->instance->GetConnection(), XCB_PROP_MODE_REPLACE, window,
			XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8,
			static_cast<uint32_t>(strlen(newTitle)),
			this->title.c_str());
}

void Frame::CreateWindow()
{
	xcb_screen_t* screen = this->instance->GetScreen();
	xcb_connection_t* connection = this->instance->GetConnection();

	xcb_window_t root = screen->root;
	xcb_visualid_t visual = screen->root_visual;

	uint32_t window = this->GetWindow();

	uint32_t mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;

	uint32_t values[2] =
	{ screen->white_pixel, XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_BUTTON_PRESS
			| XCB_EVENT_MASK_BUTTON_RELEASE | XCB_EVENT_MASK_POINTER_MOTION
			| XCB_EVENT_MASK_ENTER_WINDOW | XCB_EVENT_MASK_LEAVE_WINDOW
			| XCB_EVENT_MASK_KEY_PRESS | XCB_EVENT_MASK_KEY_RELEASE };

	xcb_create_window(connection, static_cast<uint8_t>(XCB_COPY_FROM_PARENT),
			window, root, static_cast<int16_t>(this->xpos),
			static_cast<int16_t>(this->ypos),
			static_cast<uint16_t>(this->GetWidth()),
			static_cast<uint16_t>(this->GetHeight()),
			static_cast<uint16_t>(this->GetBorderWidth()),
			static_cast<uint16_t>(XCB_WINDOW_CLASS_INPUT_OUTPUT), visual, mask,
			values);

	xcb_change_property(connection, XCB_PROP_MODE_REPLACE, window,
			XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8,
			static_cast<uint32_t>(strlen(this->title.c_str())),
			this->title.c_str());

	//?????
	// Why isn't this moving the window..?
	const static uint32_t posxy[] =
	{ static_cast<uint32_t>(this->xpos), static_cast<uint32_t>(this->ypos) };
	xcb_configure_window(connection, window,
			XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y, posxy);

	xcb_map_window(this->instance->GetConnection(), this->window);
	xcb_flush(this->instance->GetConnection());
}

void Frame::AssignInstance(PfInstance* const instance)
{
	this->instance = instance;
	xcb_connection_t* id = this->instance->GetConnection();
	this->window = xcb_generate_id(id);
}
}
