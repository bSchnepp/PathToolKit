/*
 * ThemeFactory.cpp
 *
 *  Created on: Mar 24, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <PathToolKit/gutil/Color.h>
#include <PathToolKit/themes/Theme.h>

namespace PathDraw
{

Theme::Theme()
{
	this->control = new Color(0, 0, 0);
	this->info = new Color(.3f, .3f, .3f);
	this->motif = new Color(255, 0, 0);
	//TODO, placeholder. Lots more are to be added.
}

Theme::~Theme()
{
	// TODO Auto-generated destructor stub
}

} /* namespace PathDraw */
