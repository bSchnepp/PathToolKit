# PathToolKit
A simple drawing/widget toolkit, utilizing XCB.
Currently dead, migrating to learning Wayland instead and to drop X11 support.
Will submit patches for Wayland later.
___

PathToolKit is meant to be a simple-to-understand but deep in features widget/drawing toolkit that I can just use.
It is a work in progress, with many features, ideas, anything being very fluid and subject to change rather rapdily.
___

Core features (TODO):

	- Vector-based graphics. (Currently sort-of supported in a terrible manner, Right now, we just render based on the component's x and y and points relative to those bounds.)

	- Preference to render surfaces in Vulkan/OpenGL whenever possible.
	
	- Themes based on CSS3, allowing for customization of almost everything.
	
	- Offscreen rendering of all components, which are then rendered to the window as an image, and events manually managed. Figure out a better way to do this later.
	
Completed features:

	- Colors. That's really about it. No gradient support yet.
	- Drawing of some shapes is supported, more being added.

Roadmap:

	- Within 4 months, start getting a Vulkan backend up (to do rendering of components before putting them on the X window).
	
	- Complete a real program with PathToolKit in 1 year. [A rewrite of FreedomWriter or basic file manager or something.]
___
PathToolKit also has a sample folder for some programs utilizing the library.
These are located in the 'Samples' folder.
If you're building PathToolKit to be used, you should build the PathToolKit directory by itself, and create a dynamic object from it.

Some of those examples are expected to be broken as the library is changed over time, and will be updated whenever I can spare the time to fix them.

(TODO: make this readme not awful later)

___

Suggestions are welcome, commits are welcome as long as all changes are under the same license and the commit message is descriptive of changes.
