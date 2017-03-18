/*
 * BorderLayout.h
 *
 *  Created on: Feb 20, 2017
 *      Author: Brian Schnepp
 */

#ifndef BORDERLAYOUT_H_
#define BORDERLAYOUT_H_

#include <cstdint>

#include "../../structdefs.h"
#include "../LayoutManager.h"

namespace Pathfinder
{
class Component;
} /* namespace Pathfinder */

namespace Pathfinder
{

class BorderLayout : public LayoutManager
{
public:
	BorderLayout();
	BorderLayout(uint16_t hgap, uint16_t vgap);

	//void Add(Component* component, int position);

	virtual ~BorderLayout();
	void Update(Component* root);

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
	uint16_t* xgap;
	uint16_t* ygap;

	PF_COMPONENT_SERIAL components[5];
};

} /* namespace Pathfinder */

#endif /* BORDERLAYOUT_H_ */
