/*
 * Core.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <frame.h>
#include <gutil/Color.h>
#include <PfGraphics.h>
#include <PfInstance.h>
#include <iostream>


int RunExample()
{
	// We'll create a PfInstance and a frame, along with it's graphics context.
	Pathfinder::PfInstance* instance = new Pathfinder::PfInstance();
	Pathfinder::Frame* frame = new Pathfinder::Frame("Hello, Pathfinder!");
	Pathfinder::PfGraphics* graphics = new Pathfinder::PfGraphics(instance);

	// We need to bind ("make") the frame, then set it's attributes for the later CreateFrame call.
	instance->MakeFrame(frame);
	frame->SetBorderWidth(100);
	frame->SetPos(500, 500);
	frame->CreateFrame();

	// Make a color, assign it to the graphics context.
	Pathfinder::Color* color = new Pathfinder::Color(0, 0, 0);
	graphics->AssignColor(color);
	graphics->AssignComponent(frame);

	// Draw some shapes! These are unsafe as they aren't dynamically re-rendered.
	std::cout << "DEBUG PRINT [ACTIVE] : Before Calling FillArc" << std::endl;
	graphics->FillArc(0, 400, 190, 190, 50, 330);
	graphics->FillRect(100, 100, 165, 152);
	graphics->FillOval(300, 300, 25, 50);

	int xpoints[] =
	{ 0, 0, 90, 109, 53, 532, 12 };
	int ypoints[] =
	{ 0, 3, 25, 100, 53, 1, 9 };
	int numpoints = 7;
	graphics->FillPolygon(xpoints, ypoints, numpoints);
	graphics->Repaint();

	// This is the main loop.Once this fires, everything must pass as an event to the main loop to do any GUI changes.
	instance->PfInit(frame);


	// Clean up our mess.
	delete frame;
	delete graphics;
	delete instance;

	return 0;
}
