/*
 * pathfinder.h
 *
 *  Created on: Feb 18, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHFINDER_H_
#define PATHFINDER_H_

/**
 *  Just includes for everything you'd want to use...
 *  You should use this, as other files may or may not exist, be renamed, etc.
 *  Just include this for the sake of portability between variations of Pathfinder
 *  Promise I'll try to not bloat the RAM consumption too much.
 *
 *  Important TODOs:
 *  	- Vector-based widgets, get hardware acceleration via ~~OpenGL~~ Vulkan and some other black magic.
 *  	- Theming, based in a folder in $(HOME)/pathfinder/themes/
 *  	- Compile libPathfinder as a separate, shared object.
 *  	- GTK+ theme compatibility?
 **/

/* Frames + other high-level stuff */
#include <PathToolKit/graphic/Circle.h>
#include <PathToolKit/graphic/gstructs.h>
#include <PathToolKit/graphic/Shape.h>
#include <PathToolKit/graphic/Rectangle.h>
#include <PathToolKit/graphic/ShapeContainer.h>

#include <PathToolKit/component.h>
#include <PathToolKit/frame.h>

#include <PathToolKit/PfGraphics.h>
#include <PathToolKit/PfInstance.h>

/* Drawing toolkity stuff */
#include <PathToolKit/graphic/Shape.h>
#include <PathToolKit/PfInstance.h>
#include <PathToolKit/PfGraphics.h>

/* Events */
#include <PathToolKit/event/event.h>
#include <PathToolKit/event/ActionEvent.h>
#include <PathToolKit/event/ActionListener.h>
#include <PathToolKit/event/FrameEvent.h>
#include <PathToolKit/event/FrameListener.h>

/* Layouts and whatnot. */
#include <PathToolKit/gutil/LayoutManager.h>
#include <PathToolKit/gutil/managers/BorderLayout.h>

/* Text and stuff */
#include <PathToolKit/themes/Font.h>

/* Images and icons */
#include <PathToolKit/image/Image.h>

/* Shapes */
//TODO: Irregular circles and arcs!!
//TODO: Dynamically painted objects
//TODO: Dynamic objects
#include <PathToolKit/graphic/Circle.h>
#include <PathToolKit/graphic/Arc.h>
#include <PathToolKit/gutil/Color.h>

//Extensions

#ifdef PATHTOOLKIT_INCLUDE_EXTRAS
#include <PathToolKit/extra/BasicFrame.h>
#endif

/* Shapes and other graphical utilities */

#endif /* PATHFINDER_H_ */
