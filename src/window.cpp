#include <probable_guide/window.h>
#include <probable_guide/probable_guide.h>

#include <iostream>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

using namespace probable_guide;

static void WindowSizeCallBack(GLFWwindow* window, int width, int height)
{
    void* user_pointer = glfwGetWindowUserPointer(window);
    Window* w = reinterpret_cast<Window*>(user_pointer);
    w->OnWindowSizeChange(width, height);
}

static void WindowFramebufferChangeCallback(GLFWwindow* window, int width, int height)
{
    void* user_pointer = glfwGetWindowUserPointer(window);
    Window* w = reinterpret_cast<Window*>(user_pointer);
    w->OnFramebufferChange(width, height);
}

static void WindowPositionChangeCallback(GLFWwindow* window, int x, int y)
{
    void* user_pointer = glfwGetWindowUserPointer(window);
    Window* w = reinterpret_cast<Window*>(user_pointer);
    w->OnWindowPositionChange(x, y);
}

void Window::OnFramebufferChange(int width, int height)
{
    mFramebufferWidth = width;
    mFramebufferHeight = height;
}


Window::Window(Window::Private)
{
}

Window::~Window()
{
    glfwDestroyWindow(mGLFWWindow);
}

void Window::Close()
{
    auto pg = mGuide.lock();

    if(pg) {
        pg->CloseWindow(shared_from_this());
    }
}

bool Window::Init()
{

    // preparing for vulkan
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    // will be removed in the future
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    if(!(mGLFWWindow = glfwCreateWindow(mScreenWidth, mScreenHeight, "Probable Guide", NULL, NULL))) {
        return false;
    }
    glfwSetWindowUserPointer(mGLFWWindow, this);
    glfwSetWindowSizeCallback(mGLFWWindow, WindowSizeCallBack);
    glfwSetFramebufferSizeCallback(mGLFWWindow, WindowFramebufferChangeCallback);
    return true;
}

bool Window::ShouldClose()
{
    if(glfwWindowShouldClose(mGLFWWindow)) {
        return true;
    }
    return false;
}


void Window::MakeContextCurrent()
{
    glfwMakeContextCurrent(mGLFWWindow);
}

void Window::OnWindowSizeChange(int width, int height)
{

}


void Window::OnWindowPositionChange(int x, int y)
{

}

