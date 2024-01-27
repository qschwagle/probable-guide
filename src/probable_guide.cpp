#include <probable_guide/probable_guide.h>

#include <algorithm>
#include <tuple>
#include <iostream>

#include <probable_guide/window.h>
#include <probable_guide/vulkan_context.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

using namespace probable_guide;

bool ProbableGuide::Init(int argc, char** argv)
{
    if(!glfwInit()) {
        return false;
    }

    auto window = CreateWindow();

    if(!window->Init()) {
        std::cout << "failed to create window" << std::endl;
        return false;
    }

    mVulkanContext = VulkanContext::Create();

    if(!mVulkanContext->Init(window->GetHandle())) {
        std::cout << "vulkan failed to initialize" << std::endl;
        return false;
    }

    return true;
}

int ProbableGuide::Run()
{
    while(true) {
        for(auto i = mWindows.begin(); i != mWindows.end(); ++i) {
            auto window = *i;
            if(!window) {
                break;
            }

            window->MakeContextCurrent();

            if(window->ShouldClose()) {
                window->Close();
            }
        }

        glfwPollEvents();

        auto last_element = std::remove_if(mWindows.begin(), mWindows.end(), 
                    [](std::shared_ptr<Window> ptr) {
                        return ptr == nullptr;
                    }
        );

        mWindows.erase(last_element, mWindows.end());

        if(mWindows.size() == 0) {
            // terminate if there are no windows open
            return 0;
        }
    }
}


ProbableGuide::ProbableGuide(ProbableGuide::Private)
{
}

ProbableGuide::~ProbableGuide()
{
    glfwTerminate();
}

std::shared_ptr<Window> ProbableGuide::CreateWindow()
{
    auto window = Window::Create(shared_from_this());
    mWindows.push_back(window);
    return window;
}

void ProbableGuide::CloseWindow(std::shared_ptr<Window> window)
{
    for(auto i = mWindows.begin(); i != mWindows.end(); ++i) {
        if(window == *i) {
            *i = nullptr;
        }
    }
}


