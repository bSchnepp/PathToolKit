/*
 * VulkanContext.h
 *
 *  Created on: Mar 22, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_EXTRA_GBACK_VULKANCONTEXT_H_
#define PATHTOOLKIT_EXTRA_GBACK_VULKANCONTEXT_H_

//TODO, use iff vulkan is enabled at compile-time.
//If not... try to do weird hacks with OpenGL I guess. Or have a fallback option to software rendering of components (as is normal right now).

namespace PathRender
{

class VulkanContext
{
public:
	VulkanContext();
	virtual ~VulkanContext();
};

} /* namespace PathWidget */

#endif /* PATHTOOLKIT_EXTRA_GBACK_VULKANCONTEXT_H_ */
