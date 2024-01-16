# Rendering 2D 

Its decided that probable\_guide will use skia.

Skia requires a gpu rendering for performance and easier to get the target
to the screen. For Mac OS and Windows support and future other targets, I only
have the choice between OpenGL and Vulcan. 

Mac OS opengl is capped at 4.1. I can write seperate targets for windows and
mac os, but I would rather keep it stuck to one for the time being.

So, I can risk the opengl support with 4.1 or I can use Vulcan and hope there
are no issues on other platforms.

I am going to choose Vulkan for the time being.



## Vulkan integration

Vulkan rendering is complex. There are many moving parts that need to be handled by
the developer. For my purposes, I am going to have either one context per window
or one context that is erased and replaced for each window. I will need to read up
on which is better. 

I am going to do a center dependency that then is given out to windows. The windows
then can use the context when they need to render.

Main Render Vulkan Context -> Window
                           -> Window
                           -> Window
                           ...
                           -> Window
struct VulkanContext (main)

struct VulkanSurface (reference)


## Skia

Skia will need information to render. Future research needs to be done to figure out
how skia needs to be split up between windows

