#pragma once

#include <memory>

struct GLFWwindow;


namespace probable_guide
{

class ProbableGuide;

class Window : public std::enable_shared_from_this<Window>
{
private:
    struct Private{};
public:
    Window(Private);

    virtual ~Window();

private:
    static std::shared_ptr<Window> Create(std::shared_ptr<ProbableGuide> guide) {
        auto window = std::make_shared<Window>(Private());
        window->mScreenWidth = 1920;
        window->mScreenHeight = 1080;
        window->mFramebufferWidth = 1920;
        window->mFramebufferHeight = 1080;

        window->mGuide = guide;
        return window;
    }

public:
    Window(const Window&)=delete;
    Window(const Window&&)=delete;

    Window& operator=(const  Window&)=delete;
    Window&& operator=(const Window&&)=delete;

    friend ProbableGuide;

    bool Init();

    bool ShouldClose();

    void Close();

    void MakeContextCurrent();

    bool IsWindow(GLFWwindow *window) const { return mGLFWWindow == window; } 

    void OnWindowSizeChange(int width, int height);

    void OnFramebufferChange(int width, int height);

private:
    /// screen space width
    int mScreenWidth{0};
    /// screen space height
    int mScreenHeight{0};
    /// framebuffer width in pixels
    int mFramebufferWidth{0};
    int mFramebufferHeight{0};

    std::weak_ptr<ProbableGuide> mGuide;
    GLFWwindow* mGLFWWindow{nullptr};
};
}
