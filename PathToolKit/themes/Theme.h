/*
 * ThemeFactory.h
 *
 *  Created on: Mar 24, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_THEMES_THEME_H_
#define PATHTOOLKIT_THEMES_THEME_H_

namespace PathDraw
{
class Color;
class Theme
{
public:
	Theme();
	virtual ~Theme();

private:
	Color* control;
	Color* info;
	Color* motif;
	//expect a mess of objects, ahhh!
	//We'll have to do alll sorts of things ahhh

	/*
	 * TODO:
	 * Read a theme from ~/ptk/Themes/system.ptk
	 * or
	 * Read a theme with the file specified
	 *
	 * Generate a tree of colors, theming, position, etc, and apply this to __all__ objects which don't opt-out of the theme.
	 * Components should bind this to it, blah blah blah.
	 */
};

} /* namespace PathDraw */

#endif /* PATHTOOLKIT_THEMES_THEME_H_ */
