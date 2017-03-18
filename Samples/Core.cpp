/*
 * Core.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: Brian Schnepp
 */

#include <PathToolKit/pathfinder.h>
#include <iostream>
#include <string>

int main()
{
	Pathfinder::PfInstance* instance = new Pathfinder::PfInstance();
	Pathfinder::Frame* frame = new Pathfinder::Frame("Hello, Pathfinder!");
	Pathfinder::PfGraphics* graphics = new Pathfinder::PfGraphics();
	graphics->AssignInstance(instance);

	instance->MakeFrame(frame);
	frame->SetBorderWidth(100);
	frame->SetPos(500, 500);
	frame->CreateWindow();

	Pathfinder::Color* color = new Pathfinder::Color(0, 0, 0);
	graphics->AssignColor(color);
	graphics->AssignFrame(frame);

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
	instance->PfInit(frame);


	delete frame;
	delete graphics;
	delete instance;

	return 0;
}
