/*
 * Runner.cpp
 *
 *  Created on: Mar 18, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

// I build this in Eclipse, so this file is created so that I can test the demos and stuff.
#define Simple

#include "Simple/Simple.h"

int main()
{
#ifdef Simple
	return RunSimple();
#endif
	return 0;
}



