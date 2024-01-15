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

private:
    std::weak_ptr<ProbableGuide> mGuide;
    GLFWwindow* mGLFWWindow{nullptr};
};
}
