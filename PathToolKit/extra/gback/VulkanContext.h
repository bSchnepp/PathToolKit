/*
 * VulkanContext.h
 *
 *  Created on: Mar 22, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#pragma once

#include <vulkan/vulkan.h>
#include <string>

namespace PathDraw
{
class Color;
} /* namespace PathDraw */

//If not... try to do weird hacks with OpenGL I guess. Or have a fallback option to software rendering of components (as is normal right now).
//This will probably totally replace the old graphics context stuff because we need hardware acceleration and compositing.

namespace PathRender
{

class VulkanContext
{
public:
	VulkanContext();
	VulkanContext(VkApplicationInfo info);
	VulkanContext(std::string name);

	virtual ~VulkanContext();

	//TODO
	void DrawLine();

private:
	void* vulkanlib;
	PathDraw::Color* color;
	VkInstance* instance;
	VkDevice* device;
	VkPhysicalDevice* pdevices;

	VkApplicationInfo info;
	VkInstanceCreateInfo cinfo;

};

} /* namespace PathWidget */
