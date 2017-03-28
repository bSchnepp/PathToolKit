/*
 * FlowLayout.h
 *
 *  Created on: Mar 26, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_GUTIL_MANAGERS_FLOWLAYOUT_H_
#define PATHTOOLKIT_GUTIL_MANAGERS_FLOWLAYOUT_H_

#include <PathToolKit/component.h>
#include <PathToolKit/gutil/LayoutManager.h>
#include <cstdint>
#include <vector>

namespace PathDraw
{

class FlowLayout: public LayoutManager
{
public:
	//TODO: the default manager for all Components.
	//Lines them all up in a row -- if the component is too large, makes a new row.
	//Each row's height is always equal.
	FlowLayout();
	FlowLayout(const int alignment);
	FlowLayout(const int alignment, uint16_t xgap, uint16_t ygap);

	void UpdateSize(int width, int height);

	virtual ~FlowLayout();

	/* Pathfinder specifications:
	 * These are the values for what this LayoutManager should ask for.
	 * Components in these indices should order in their respective parts of the Component.
	 * Almost certain there's a better way to do this I haven't thought up yet at 2 in the morning.
	 *
	 * This is basically a clone of how Swing does it, so just reference that I guess.
	 */
	const static int LEFT = 0;
	const static int RIGHT = 1;
	const static int CENTER = 2;

private:
	uint16_t xgap;
	uint16_t ygap;

	std::vector<Component>* components;
};

} /* namespace PathDraw */

#endif /* PATHTOOLKIT_GUTIL_MANAGERS_FLOWLAYOUT_H_ */
