#include <probable_guide/vulkan_context.h>

#include <iostream>
#include <vector>

#include <vulkan/vulkan.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

using namespace probable_guide;

namespace probable_guide
{

class VulkanContextPrivate
{
private:

public:
    VulkanContextPrivate()=default;
    virtual ~VulkanContextPrivate();

    VulkanContextPrivate(const VulkanContextPrivate&)=delete;
    VulkanContextPrivate(const VulkanContextPrivate&&)=delete;

    VulkanContextPrivate& operator=(const VulkanContextPrivate&)=delete;
    VulkanContextPrivate& operator=(const VulkanContextPrivate&&)=delete;

    bool Init();

private:
    VkInstance mInstance;
};

}

bool VulkanContext::Init()
{
    mPrivate = std::make_shared<VulkanContextPrivate>();

    return mPrivate->Init();
}


bool VulkanContextPrivate::Init()
{
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledLayerCount = 0;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    std::vector<const char*> requiredExtensions;
    
    for(uint32_t i = 0; i < glfwExtensionCount; i++) {
        requiredExtensions.emplace_back(glfwExtensions[i]);
    }
    
    requiredExtensions.emplace_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);

    createInfo.enabledExtensionCount = (uint32_t) requiredExtensions.size();
    createInfo.ppEnabledExtensionNames = requiredExtensions.data();

    createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;

    VkResult res = vkCreateInstance(&createInfo, nullptr, &mInstance);

    if (res == VK_ERROR_INCOMPATIBLE_DRIVER) {
        std::cout << "failed to create vulkan instance: incompatible driver" << std::endl;
        return false;
    }

    if (res != VK_SUCCESS) {
        std::cout << "failed to create vulkan instance" << std::endl;
        return false;
    }
    return true;
}

VulkanContextPrivate::~VulkanContextPrivate()
{
    vkDestroyInstance(mInstance, nullptr);
}
