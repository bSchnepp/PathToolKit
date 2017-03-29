/*
 * Shapes.cpp
 *
 *  Created on: Mar 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */
#define PATHTOOLKIT_INCLUDE_EXTRAS
#define PATHTOOLKIT_USE_VULKAN
#include <PathToolKit/ptk.h>

#include <iostream>
#include "Managed.h"

int RunManagedExample()
{
	// We'll create a PfInstance and a frame, along with it's graphics context.
	PathExtension::BasicFrame* frame = new PathExtension::BasicFrame(
			"Managed Example");
	frame->CreateFrame();

	// Make a color, assign it to the graphics context.
	PathDraw::Color* color = new PathDraw::Color(255, 0, 0);
	PathDraw::Color* black = new PathDraw::Color(0, 0, 0);
	PathDraw::Color* rectColor = new PathDraw::Color(73, 17, 92);

	PathDraw::PTK_Point p1 =
	{ 0.1f, 0.2f };
	PathDraw::PTK_Point p2 =
	{ 0.4f, 0.2f };
	PathDraw::PTK_Point p3 =
	{ 0.25f, 0.9f };
	PathDraw::PTK_Point array[] =
	{ p1, p2, p3 };

	PathDraw::Shape* shape = new PathDraw::Shape(array, 3); //TODO: add optimizations for rectangles, and other shapes.
	shape->SetFill(true);
	PathDraw::PTK_Stroke* stroke = new PathDraw::PTK_Stroke();
	stroke->colors = color;
	shape->SetStroke(stroke);

	PathDraw::PTK_Point cp1 =
	{ 0.9f, 0.6f };
	PathDraw::Circle* circle = new PathDraw::Circle(cp1, 80);
	circle->SetFill(true);	//Implicit usually.
	PathDraw::PTK_Stroke* stroke2 = new PathDraw::PTK_Stroke();
	stroke2->colors = black;
	circle->SetStroke(stroke2);

	PathDraw::PTK_Point rp1 =
	{ 0.5f, 0.2f };	//This is currently unintended behavior. Fixme
	PathDraw::Rectangle* rect = new PathDraw::Rectangle(rp1, .4f, .3f);
	PathDraw::PTK_Stroke* stroke3 = new PathDraw::PTK_Stroke();
	stroke3->colors = rectColor;
	rect->SetStroke(stroke3);

	frame->AddShape(shape);
	frame->AddShape(circle);
	frame->AddShape(rect);

	PathDraw::Component* component1 = new PathDraw::Component();

	// This is the main loop.Once this fires, everything must pass as an event to the main loop to do any GUI changes.
	frame->GetInstance()->PfInit(frame);

	// Clean up our mess
	delete frame;
	delete component1;
	delete shape;
	delete color;
	delete rect;

	return 0;
}

