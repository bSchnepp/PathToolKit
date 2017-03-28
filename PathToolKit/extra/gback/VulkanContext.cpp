/*
 * VulkanContext.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#include <dlfcn.h>
#include <PathToolKit/extra/gback/VulkanContext.h>
#include <stdlib.h>
#include <iostream>

#include <vulkan/vulkan.h>	//Really really really safely dynamically load this later -- too much work right now.

#ifdef _WIN32	//for WINE/ReactOS/Windows support if I ever bother.
#define LoadSharedObject LoadLibrary
#define VulkanLibrary "vulkan-1.dll"
#else
#define LoadSharedObject dlopen
#define VulkanLibrary "libvulkan.so", RTLD_NOW
#endif

namespace PathRender
{

VulkanContext::VulkanContext()
{
	this->vulkanlib = LoadSharedObject(VulkanLibrary);

	if (this->vulkanlib == nullptr)
	{
		std::cout
				<< "Vulkan failed to load: PathToolKit is unable to render without Vulkan.\n"
				<< "Please install a compatible driver which supports Vulkan in order to use PathToolKit."
				<< std::endl;
		exit(-2);
	}


	//TODO
	this->instance = nullptr;
	this->device = nullptr;
	this->pdevices = nullptr;
	this->color = nullptr;
}

VulkanContext::~VulkanContext()
{
	dlclose(this->vulkanlib);
}

} /* namespace PathWidget */
