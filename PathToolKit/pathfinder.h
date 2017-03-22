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

#include <PathToolKit/graphic/gstructs.h>
#include <PathToolKit/graphic/ShapeContainer.h>
#include "component.h"
#include "frame.h"

#include "graphic/gstructs.h"

/* Drawing toolkity stuff */
#include "gutil/Color.h"
#include "graphic/Shape.h"
#include "PfInstance.h"
#include "PfGraphics.h"

/* Events */
#include "event/event.h"
#include "event/ActionEvent.h"
#include "event/ActionListener.h"
#include "event/FrameEvent.h"
#include "event/FrameListener.h"

/* Layouts and whatnot. */
#include "gutil/LayoutManager.h"
#include "gutil/managers/BorderLayout.h"

/* Text and stuff */
#include "font/Font.h"

/* Images and icons */
#include "image/Image.h"

/* Shapes */
//TODO: Irregular circles and arcs!!
//TODO: Dynamically painted objects
//TODO: Dynamic objects
//TODO: COLORS!!!!
#include "graphic/Circle.h"
#include "graphic/Arc.h"

//Extensions

#ifdef PATHTOOLKIT_INCLUDE_EXTRAS
#include "extra/BasicFrame.h"
#endif

/* Shapes and other graphical utilities */

#endif /* PATHFINDER_H_ */
