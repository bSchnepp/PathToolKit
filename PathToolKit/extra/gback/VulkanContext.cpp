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


#include <vulkan/vulkan.h>	//Really really really safely dynamically load this later -- too much work right now.

#ifdef _WIN32	//for WINE/ReactOS/Windows support if I ever bother.
#define LoadSharedObject LoadLibrary
#else
#define LoadSharedObject dlopen
#endif

#include <iostream>

namespace PathRender
{

VulkanContext::VulkanContext()
{
	//** SOMETHING'S WRONG WITH THIS AND I CAN'T FIND IT. This is actually utterly baffling. Not calling the constructor, not doing _anything_ with this. Huh?**//

	std::cout << "Hey! This works!" << std::endl;	//It's not even calling this? Huh?
	this->vulkanlib = dlopen("libvulkan.so", RTLD_NOW);

	if (this->vulkanlib == nullptr)
	{
		std::cout
				<< "Vulkan failed to load: PathToolKit is unable to render without Vulkan.\n"
				<< "Please install a compatible driver which supports Vulkan in order to use PathToolKit."
				<< std::endl;
		exit(-2);
	}
	else
	{
		std::cout << "Vulkan loaded sucessfully!" << std::endl;
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
	if (makeInstance == VK_SUCCESS)
	{
		std::cout << "Instance creation success!" << std::endl;
	}
	else
	{
		std::cout << "Something went wrong with setting up Vulkan."
				<< std::endl;
	}
}

VulkanContext::~VulkanContext()
{
	dlclose(this->vulkanlib);
}

} /* namespace PathWidget */
