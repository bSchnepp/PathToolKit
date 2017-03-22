/*
 * PathLabel.h
 *
 *  Created on: Mar 22, 2017
 *      Author: Brian Schnepp
 *      License: See 'LICENSE' in root of this repository.
 */

#ifndef PATHTOOLKIT_WIDGETS_PATHLABEL_H_
#define PATHTOOLKIT_WIDGETS_PATHLABEL_H_

#include <string>

namespace PathWidget
{

class PathLabel
{
public:
	PathLabel();
	PathLabel(std::string label);
	virtual ~PathLabel();

private:
	std::string label;	//PathLabels _only_ support Strings. For image components, there's a todo PathImageLabel class.
};

} /* namespace PathWidget */

#endif /* PATHTOOLKIT_WIDGETS_PATHLABEL_H_ */
