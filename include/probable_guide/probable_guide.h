#pragma once

#include <memory>
#include <vector>

namespace probable_guide
{

class Window;
class VulkanContext;

class ProbableGuide : public std::enable_shared_from_this<ProbableGuide>
{
    struct Private{};
public:
    ProbableGuide(Private);

    static std::shared_ptr<ProbableGuide> Create() {
        return std::make_shared<ProbableGuide>(Private());
    }

    std::shared_ptr<ProbableGuide> GetPtr() {
        return shared_from_this();
    }

    ProbableGuide(const ProbableGuide&)=delete;
    ProbableGuide(const ProbableGuide&&)=delete;

    ProbableGuide& operator=(const ProbableGuide&)=delete;
    ProbableGuide&& operator=(const ProbableGuide&&)=delete;

    bool Init(int argc, char** argv);

    int Run();

    virtual ~ProbableGuide();

    std::shared_ptr<Window> CreateWindow();

    void CloseWindow(std::shared_ptr<Window> window);
private:
    std::vector<std::shared_ptr<Window>> mWindows;
    std::shared_ptr<VulkanContext> mVulkanContext;
};
}
