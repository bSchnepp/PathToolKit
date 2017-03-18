/*
 * ActionListener.h
 *
 *  Created on: Feb 19, 2017
 *      Author: Brian Schnepp
 */

#ifndef ACTIONLISTENER_H_
#define ACTIONLISTENER_H_

#include "ActionEvent.h"
#include "Listener.h"

namespace Pathfinder
{

class ActionListener : public Listener
{
public:
	ActionListener();
	virtual ~ActionListener();

	/** This method is called by the Pathfinder library. You'll need to assign a function to this Listener first. */
	void ActionPerformed(ActionEvent* e);
};

} /* namespace Pathfinder */

#endif /* ACTIONLISTENER_H_ */
