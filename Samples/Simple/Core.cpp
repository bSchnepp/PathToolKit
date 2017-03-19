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


int RunExample()
{
	// We'll create a PfInstance and a frame, along with it's graphics context.
	PathDraw::PfInstance* instance = new PathDraw::PfInstance();
	PathDraw::Frame* frame = new PathDraw::Frame("Hello, Pathfinder!");
	PathDraw::PfGraphics* graphics = new PathDraw::PfGraphics(instance);

	// We need to bind ("make") the frame, then set it's attributes for the later CreateFrame call.
	instance->MakeFrame(frame);
	frame->SetBorderWidth(100);
	frame->SetPos(500, 500);
	frame->CreateFrame();

	// Make a color, assign it to the graphics context.
	PathDraw::Color* color = new PathDraw::Color(0, 0, 0);
	graphics->AssignColor(color);
	graphics->AssignComponent(frame);

	// Draw some shapes! These are unsafe as they aren't dynamically re-rendered.
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

	// This is the main loop.Once this fires, everything must pass as an event to the main loop to do any GUI changes. This should always be the last call of our program before cleanup and all.
	instance->PfInit(frame);


	// Clean up our mess.
	delete frame;
	delete graphics;
	delete instance;
	delete color;

	return 0;
}
