/*
 * Color.h
 *
 *  Created on: Feb 18, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef COLOR_H_
#define COLOR_H_

#include <cstdint>

namespace PathDraw
{

class Color
{
public:

	/** Creates a black color. */
	Color();

	/** Creates a greyscale color based on 1 number. */
	Color(uint16_t c);

	/** Creates a greyscale color based on 2 number, one for alpha and one for the brightness. */
	Color(uint16_t c, uint16_t a);

	/** Create a new Color object with values from 0 - 255. */
	Color(uint16_t r, uint16_t g, uint16_t b);

	/** Create a relative-based color based on another color. */
	Color(uint16_t r, uint16_t g, uint16_t b, Color* o);

	/** Color with alpha value. */
	Color(uint16_t r, uint16_t g, uint16_t b, uint16_t a);

	/** Create a relative-based color based on another color and alpha value. */
	Color(uint16_t r, uint16_t g, uint16_t b, uint16_t a, Color* o);

	/* Handle in terms of ints, just for being lazy. */

	/** Creates a greyscale color based on 1 number. */
	Color(int c);

	/** Creates a greyscale color based on 2 number, one for alpha and one for the brightness. */
	Color(int c, int a);

	/** Create a new Color object with values from 0 - 255. */
	Color(int r, int g, int b);

	/** Create a relative-based color based on another color. */
	Color(int r, int g, int b, Color* o);

	/** Copy constructor */
	Color(Color* o);

	/** Color with alpha value. */
	Color(int r, int g, int b, int a);

	/** Create a relative-based color based on another color and alpha value. */
	Color(int r, int g, int b, int a, Color* o);

	/** Creates a new color based on 4 floats for the values. */
	Color(float r, float g, float b, float a);

	/** Creates a new color based on 3 floats for the values. */
	Color(float r, float g, float b);

	/** Returns a copied color with the values darkened. */
	Color* Darker();

	/** Returns a copied color with the values brightened. */
	Color* Brighter();

	/** Inverts the RBG value. This will, for example, turn white to black, and turn light colors to dark colors. */
	Color* InvertRBG();

	/** Inverts the hue of the color, such that the color will be it's inverse, but retain it's saturation and brightness. */
	Color* InvertHue();

	/** Gets the red value of this Color. */
	uint16_t GetRed();

	/** Gets the blue value of this Color. */
	uint16_t GetBlue();

	/** Gets the green value of this Color. */
	uint16_t GetGreen();

	/** Gets the alpha (transparency) value of this Color */
	uint16_t GetAlpha();

	/** Converts the R, G, and B components into a single color. The alpha is ignored if we're not using Vulkan for rendering. */
	uint32_t GenerateColor();

	virtual ~Color();

private:
	uint16_t r;
	uint16_t b;
	uint16_t g;
	uint16_t a = 255;
};

///* Some template colors and whatnot. These color values are identical to Swing's. */
//static const Color BLACK = Color(0, 0, 0);
//static const Color WHITE = Color(255, 255, 255);
//
//
//static const Color RED = Color(255, 0, 0);
//static const Color GREEN = Color(0, 255, 0);
//static const Color BLUE = Color(0, 0, 255);
//
//static const Color LIGHT_GREY = Color(192, 192, 192);
//static const Color GREY = Color(128, 128, 128);
//static const Color DARK_GREY = Color(64, 64, 64);
//
//static const Color PINK = Color(255, 175, 175);
//static const Color YELLOW = Color(255, 255, 0);
//static const Color ORANGE = Color(255, 200, 0);
//static const Color CYAN = Color(0, 255, 255);
//static const Color MAGENTA = Color(255, 0, 255);

} /* namespace Pathfinder */

#endif /* COLOR_H_ */
