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
        window->mWidth = 1920;
        window->mHeight = 1080;
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

private:
    int mWidth{0};
    int mHeight{0};
    std::weak_ptr<ProbableGuide> mGuide;
    GLFWwindow* mGLFWWindow{nullptr};
};
}
