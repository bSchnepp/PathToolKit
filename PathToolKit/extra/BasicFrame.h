/*
 * BasicFrame.h
 *
 *  Created on: Mar 19, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_EXTRA_BASICFRAME_H_
#define PATHTOOLKIT_EXTRA_BASICFRAME_H_

#include <PathToolKit/frame.h>
#include <string>

namespace PathExtension
{

class BasicFrame: public PathDraw::Frame
{
public:
	BasicFrame();
	BasicFrame(std::string title);
	virtual ~BasicFrame();

	void SetGraphics(PathDraw::PfGraphics* graphics);
	PathDraw::PfGraphics* GetGraphics();
	PathDraw::PfInstance* GetInstance();

private:
	PathDraw::PfGraphics* graphics;
	PathDraw::PfInstance* instance;
};

} /* namespace PathExtension */

#endif /* PATHTOOLKIT_EXTRA_BASICFRAME_H_ */
