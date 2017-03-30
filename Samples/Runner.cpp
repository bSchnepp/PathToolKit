/*
 * Runner.cpp
 *
 *  Created on: Mar 18, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

// I build this in Eclipse, so this file is created so that I can test the demos and stuff.
#include "Simple/Simple.h"
#include "Shapes/Shapes.h"
#include "Managed/Managed.h"
#include <iostream>

int main()
{
	int in;
	std::cin >> in;
	std::cout << "Hello!" << std::endl;
	return RunManagedExample();
}

