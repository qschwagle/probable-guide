#include <probable_guide/window.h>
#include <probable_guide/probable_guide.h>

#include <iostream>

#include <GLFW/glfw3.h>

using namespace probable_guide;

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
    if(!(mGLFWWindow = glfwCreateWindow(1920, 1080, "Probable Guide", NULL, NULL))) {
        return false;
    }
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
