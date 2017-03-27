/*
 * BorderLayout.h
 *
 *  Created on: Feb 20, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef BORDERLAYOUT_H_
#define BORDERLAYOUT_H_

#include <cstdint>

#include "../LayoutManager.h"

namespace PathDraw
{
class Component;
} /* namespace Pathfinder */

namespace PathDraw
{

class BorderLayout: public LayoutManager
{
public:
	BorderLayout();
	BorderLayout(uint16_t hgap, uint16_t vgap);

	void Add(Component* component, int position);
	Component* Unbind(int position);
	Component Get(int position);

	void UpdateSize(int width, int height);

	virtual ~BorderLayout();

	/* Pathfinder specifications:
	 * These are the values for what this LayoutManager should ask for.
	 * Components in these indices should display in their respective parts of the Component.
	 */
	const static int CENTER = 0;
	const static int NORTH = 1;
	const static int EAST = 2;
	const static int SOUTH = 3;
	const static int WEST = 4;

private:
	uint16_t xgap;
	uint16_t ygap;

	Component* components[5];

	void Update(Component* root);	//We'll need to decide how exactly this class gets to position this stuff later... hm.
};

} /* namespace Pathfinder */

#endif /* BORDERLAYOUT_H_ */
