/*
 * VulkanContext.h
 *
 *  Created on: Mar 22, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_EXTRA_GBACK_VULKANCONTEXT_H_
#define PATHTOOLKIT_EXTRA_GBACK_VULKANCONTEXT_H_

#include <vulkan/vulkan.h>

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
	virtual ~VulkanContext();

	//TODO
	void DrawLine();

private:
	void* vulkanlib;
	PathDraw::Color* color;
	VkInstance* instance;
	VkDevice* device;
	VkPhysicalDevice* pdevices;

};

} /* namespace PathWidget */

#endif /* PATHTOOLKIT_EXTRA_GBACK_VULKANCONTEXT_H_ */
