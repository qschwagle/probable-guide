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
the developer. There is one vulkan instance and potentially the physical device and device handled by the VulkanContext. Each window 
recieve a hanlder to the VulkanContext and maintain their own separate vulkan objects such as surfaces, queues, etc.

I am going to do a center dependency that then is given out to windows. The windows
then can use the context when they need to render.

Main Render Vulkan Context -> Window
                           -> Window
                           -> Window
                           ...
                           -> Window
struct VulkanContext (main)

Each window will hold a strong reference to the VulkanContext. The program will also hold a strong reference to the vulkanContext. The vulkanContext will not hold a strong reference to the windows.

## Skia

Skia will need information to render. Future research needs to be done to figure out
how skia needs to be split up between windows

All items will be rendered through skia.

