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

#include <vulkan/vulkan.h>

#ifdef _WIN32	//for WINE/ReactOS/Windows support if I ever bother.
#define LoadSharedObject LoadLibrary
#else
#define LoadSharedObject dlopen
#endif

namespace PathRender
{

VulkanContext::VulkanContext()
{
	//Instead of trying to solve the problem of "success" but not doing anything (or even calling the class!), we'll conveniently ignore it until we need to care!
	this->vulkanlib = dlopen("libvulkan.so", RTLD_NOW);

	if (this->vulkanlib == nullptr)
	{
		std::cout
				<< "Vulkan failed to load: PathToolKit is unable to render without Vulkan.\n"
				<< "Please install a compatible driver which supports Vulkan in order to use PathToolKit."
				<< std::endl;
		exit(-2);
	}

	this->info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	this->info.pApplicationName = "PathToolKit Vulkan Context";
	this->info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	this->info.pEngineName = "PathToolKit Compositor";
	this->info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	this->info.apiVersion = VK_API_VERSION_1_0;

	this->cinfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	this->cinfo.pApplicationInfo = &(this->info);

	//TODO
	this->instance = nullptr;
	this->device = nullptr;
	this->pdevices = nullptr;
	this->color = nullptr;

	VkResult makeInstance = vkCreateInstance(&(this->cinfo), nullptr,
			this->instance);
	if (makeInstance != VK_SUCCESS)
	{
		exit(-2);
	}
}

VulkanContext::~VulkanContext()
{
	dlclose(this->vulkanlib);
}

} /* namespace PathWidget */
