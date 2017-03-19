/*
 * PfInstance.cpp
 *
 *  Created on: Feb 18, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <xcb/xcb.h>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

#include "../PfInstance.h"
#include "../frame.h"

/* This had to be created because for whatever reason, to_string wasn't available in C++14 or something? Dirty hack. Blame G++. Probably fixed by now, not compiling GCC over again.*/
template<typename T> std::string to_string(const T& n)
{
	std::ostringstream stm;
	stm << n;
	return stm.str();
}

namespace Pathfinder
{
PfInstance::PfInstance()
{
	this->connection = xcb_connect(NULL, NULL);
	this->setup = xcb_get_setup(connection);
	this->iterator = xcb_setup_roots_iterator(setup);
	this->screen = iterator.data;
	this->root = nullptr;
}

/* Delete frames first... */
PfInstance::~PfInstance()
{
	xcb_disconnect(this->connection);
	delete this->screen;

}

Frame* PfInstance::GetRoot()
{
	return this->root;
}

void PfInstance::MakeFrame(Frame* frame)
{
	this->root = frame;
	frame->AssignInstance(this);
}

xcb_connection_t* PfInstance::GetConnection()
{
	return this->connection;
}

xcb_screen_t* PfInstance::GetScreen()
{
	return this->screen;
}

void PfInstance::PfInit(Component* root)
{
	xcb_generic_event_t *event;
	root->Repaint();
	while ((event = xcb_wait_for_event(connection)))
	{
		switch (event->response_type & ~0x80)
		{
		case XCB_EXPOSE:
		{
			this->root->Repaint();
     		break;
		}

		case XCB_BUTTON_PRESS:
		{
			xcb_button_press_event_t* bp = (xcb_button_press_event_t*) event;

			switch (bp->detail)
			{
			case 4:
				break;
			case 5:
				break;
			default:
				break;
			}
			break;
		}
//		case XCB_BUTTON_RELEASE:
//		{
//			xcb_button_release_event_t* br = (xcb_button_release_event_t*) event;
//			break;
//		}
//		case XCB_MOTION_NOTIFY:
//		{
//			xcb_motion_notify_event_t* motion = (xcb_motion_notify_event_t*) event;
//			break;
//		}
//		case XCB_ENTER_NOTIFY:
//		{
//			xcb_enter_notify_event_t* enter = (xcb_enter_notify_event_t*) event;
//			break;
//		}
//		case XCB_LEAVE_NOTIFY:
//		{
//			xcb_leave_notify_event_t* leave = (xcb_leave_notify_event_t*) event;
//			break;
//		}
//		case XCB_KEY_PRESS:
//		{
//			xcb_key_press_event_t* kp = (xcb_key_press_event_t*) event;
//			break;
//		}
//		case XCB_KEY_RELEASE:
//		{
//			xcb_key_release_event_t* kr = (xcb_key_release_event_t*) event;
//			break;
//		}
		default:
			/* Unknown event type, ignore it */
			break;
		}

		free(event);
	}

}
}