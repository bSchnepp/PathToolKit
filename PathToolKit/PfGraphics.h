/*
 * PfGraphics.h
 *
 *  Created on: Feb 18, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PFGRAPHICS_H_
#define PFGRAPHICS_H_

//#include "frame.h"
#include "PfInstance.h"
#include "gutil/Color.h"
#include "graphic/gstructs.h"

namespace PathDraw
{
/* Because as always, it's actually an int and not a struct. */
typedef uint32_t xcb_colormap_t;

class PfInstance;
class Frame;
/**
 * Graphics context for Pathfinder, roughly equivalent to 'java.awt.Graphics' in AWT/Swing.
 * To utilize this, you must first create a PfInstance, create this class, then call AssignInstance to bind that PfInstance to this class.
 * From there, you can assign colors, do other stuff, draw on the window, etc.
 */
class PfGraphics
{
public:
	/** Default constructor. Required. */
	PfGraphics(PfInstance* instance);

	virtual ~PfGraphics();

	/** Returns the Graphics Context used by this class. [PROBABLY X11 ONLY] */
	uint32_t GetGraphics();

	/** Assigns an instance to this Graphics class, call this before doing anything with this. */
	void AssignInstance(PfInstance* instance);

	/** Assigns the color value to this Graphics instance. */
	void AssignColor(Color* color);	//TODO: Colors are currently ignored.

	/** Assigns the component that's to be used for this PfGraphics instance. */
	void AssignComponent(Component* component);

	/** Draws an arc (partial circle) with the specified parameters.*/
	void DrawArc(int x, int y, int width, int height, int startAngle,
			int arcAngle);
	/** Draws a line from (x1, y1) to (x2, y2)*/
	void DrawLine(int x1, int y1, int x2, int y2);

	/** Draws an oval starting at (x,y) and with width width and height height.*/
	void DrawOval(int x, int y, int width, int height);

	/** Draws a rectangle with it's upper-left corner at (x,y) and the width and height specified.*/
	void DrawRect(int x, int y, int width, int height);

	/** Same as DrawPolygon, except without connecting the last point to the first automatically.*/
	void DrawPolyline(int* xpoints, int* ypoints, int npoints);

	/** Draws a polygon with (xpoints[i], ypoints[i]) as a point, for npoints points.*/
	void DrawPolygon(int* xpoints, int* ypoints, int npoints);

	/** Draws a filled-in arc (partial circle) with the specified parameters.*/
	void FillArc(int x, int y, int width, int height, int startAngle,
			int arcAngle);

	/** Draws a filled-in oval starting at (x,y) and with width width and height height.*/
	void FillOval(int x, int y, int width, int height);

	/** Draws a filled-in rectangle with it's upper-left corner at (x,y) and the width and height specified.*/
	void FillRect(int x, int y, int width, int height);

	/** Draws a filled-in polygon with (xpoints[i], ypoints[i]) as a point, for npoints points.*/
	void FillPolygon(int* xpoints, int* ypoints, int npoints);

	/** Plots a single pixel at the point (x, y) */
	void FillPixel(int x, int y);

	void Repaint();

	/* I expect this to be subclassed for things like GraphicsBrushes and whatnot, so these are protected. */
protected:
	uint32_t gcontext;

	PfInstance* instance = nullptr;
	Component* component;

	uint32_t mask;
	uint32_t* value;

	xcb_colormap_t* colormap;
};

} /* namespace Pathfinder */

#endif /* PFGRAPHICS_H_ */
