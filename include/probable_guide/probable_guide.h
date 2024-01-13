#pragma once

#include <memory>

namespace probable_guide
{
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
private:
};
}
