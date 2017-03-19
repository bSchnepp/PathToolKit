/*
 * ActionListener.h
 *
 *  Created on: Feb 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef ACTIONLISTENER_H_
#define ACTIONLISTENER_H_

#include "ActionEvent.h"
#include "Listener.h"

namespace PathEvent
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
