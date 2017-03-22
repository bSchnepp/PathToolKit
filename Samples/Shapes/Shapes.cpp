/*
 * Shapes.cpp
 *
 *  Created on: Mar 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#define PATHTOOLKIT_INCLUDE_EXTRAS
#define PATHTOOLKIT_USE_VULKAN
#include <PathToolKit/pathfinder.h>

#include <iostream>

int RunShapesExample()
{
	// We'll create a PfInstance and a frame, along with it's graphics context.
	PathExtension::BasicFrame* frame = new PathExtension::BasicFrame("Hello, Pathfinder!");

	frame->SetBorderWidth(100);
	frame->SetPos(500, 500);
	frame->CreateFrame();

	// Make a color, assign it to the graphics context.
	PathDraw::Color* color = new PathDraw::Color(0, 0, 0);
	frame->GetGraphics()->AssignColor(color);

	PathDraw::PTK_Point p1 = {0.1f, 0.2f};
	PathDraw::PTK_Point p2 = {0.4f, 0.2f};
	PathDraw::PTK_Point p3 = {0.25f, 0.9f};
	PathDraw::PTK_Point array[] =
	{
			p1, p2, p3
	};

	PathDraw::Shape* shape = new PathDraw::Shape(array, 3); //TODO: add optimizations for rectangles, and other shapes.
	shape->SetFill(true);


	PathDraw::PTK_Point cp1 = {0.9f, 0.6f};
	PathDraw::Circle* circle = new PathDraw::Circle(cp1, 80);
	circle->SetFill(true);
	frame->AddShape(shape);
	frame->AddShape(circle);

	// This is the main loop.Once this fires, everything must pass as an event to the main loop to do any GUI changes.
	frame->GetInstance()->PfInit(frame);

	// Clean up our mess
	delete frame;
	delete shape;
	delete color;

	return 0;
}

