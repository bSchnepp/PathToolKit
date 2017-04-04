/*
 * PfInstance.h
 *
 *  Created on: Feb 18, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PFINSTANCE_H_
#define PFINSTANCE_H_

#include <xcb/xcb.h>
#include <vector>

#include "component.h"
#include "frame.h"
#include <PathToolKit/extra/gback/VulkanContext.h>
/**
 * Simple instance of creating a connection to X.
 * You need a PfInstance to do anything with Pathfinder -- we're implementing this initially in XCB, but it should carry over to Waypoint when it's a usable OS. (ie, 10 - 25 years?? Ever??)
 * I'll probably also provide C bindings for Pathfinder on Waypoint. Call this "Pathfinder++" or something. This is just a dirty widget API to get *something* up and working.
 * Really a successor to bGuiSystem, except that got *nowhere*.
 *
 * Do note that the actual way everything here is implemented is subject to change. So include <pathfinder/pathfinder.h>. It'll make your life much easier.
 *
 * I don't have a readme file yet, so I'll just cram this in here as well:
 * Goals:
 * 		- Should be nice and lightweight
 * 		- Feel a lot like some other graphics libraries I've used before (ie, Swing, GTK, etc.), but be far more low-level and expose some lower-level things.
 * 		- Mostly wrapping, but adding some functionalities for things like widgets and bars and scroll panes and whatnot.
 * 		- Easy to reimplement for something like Wayland or for Waypoint. Initially we're XCB, then we'll move on to rewrite for Wayland, and so on.
 * 		- Create an alternative to Qt and GTK+. Why? Because I feel like it? :)
 *
 *
 *
 * 	NOTICE:
 * 		WE'RE NOT STABLE.
 * 		EXPECT THINGS TO BE VERY VERY SHAKY
 * 		VERY VERY FAST AT SHIFTING
 * 		AND DON'T TRY TO SERIOUSLY BUILD SOMETHING THAT WORKS WITH THIS YET.
 * 		JUST DON'T.
 */
namespace PathDraw
{
class Frame;
class PfInstance
{
public:
	/* Set up a basic and simple instance */
	PfInstance();

	virtual ~PfInstance();

	/** Connect a window to the PfInstance.*/
	void MakeFrame(Frame* frame);

	xcb_connection_t* GetConnection();
	xcb_screen_t* GetScreen();

	void PfInit(Component* root);

	Component* GetRoot();

private:
	xcb_connection_t* connection;
	xcb_screen_t* screen;

	xcb_screen_iterator_t iterator;
	const xcb_setup_t* setup;

	Component* root;

	//PathRender::VulkanContext* vulkan = nullptr;
};
}

#endif /* PFINSTANCE_H_ */
