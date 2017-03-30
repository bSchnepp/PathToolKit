/*
 * frame.cpp
 *
 *  Created on: Feb 18, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <PathToolKit/frame.h>
#include <xcb/xproto.h>
#include <cstdint>
#include <cstring>
#include <iostream>

namespace PathDraw
{

Frame::Frame() :
		Frame::Frame("Untitled frame")
{
}

Frame::Frame(std::string title) :
		Component::Component()
{
	this->title = title;
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

PfInstance* Frame::GetInstance()
{
	return this->instance;
}

void Frame::SetTitle(const char* newTitle)
{
	std::cout << "Changing title..." << std::endl;
	this->title = newTitle;
	xcb_change_property(this->instance->GetConnection(), XCB_PROP_MODE_REPLACE,
			window, XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8,
			static_cast<uint32_t>(strlen(newTitle)), this->title.c_str());
}

void Frame::CreateFrame()
{
	this->Create();
	this->SetTitle(this->title.c_str());

	//?????
	// Why isn't this moving the window..?
	const static uint32_t posxy[] =
	{ static_cast<uint32_t>(this->xpos), static_cast<uint32_t>(this->ypos) };
	xcb_configure_window(this->GetInstance()->GetConnection(), this->window,
			XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y, posxy);
}

void Frame::AssignInstance(PfInstance* const instance)
{
	this->instance = instance;
}
}
