/*
 * Shapes.cpp
 *
 *  Created on: Mar 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <PathToolKit/pathfinder.h>

int RunShapesExample()
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

	Pathfinder::PTK_Point p1 = {0.1f, 0.2f};
	Pathfinder::PTK_Point p2 = {0.4f, 0.2f};
	Pathfinder::PTK_Point p3 = {0.25f, 0.9f};
	Pathfinder::PTK_Point array[] =
	{
			p1, p2, p3
	};

	Pathfinder::Shape* shape = new Pathfinder::Shape(array, 3);
	frame->AddShape(shape);

	// This is the main loop.Once this fires, everything must pass as an event to the main loop to do any GUI changes.
	frame->Repaint();
	instance->PfInit(frame);

	// Clean up our mess.
	delete frame;
	delete graphics;
	delete instance;

	delete shape;
	delete color;

	return 0;
}

