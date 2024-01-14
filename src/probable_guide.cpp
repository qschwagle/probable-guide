#include <probable_guide/probable_guide.h>

#include <GLFW/glfw3.h>

using namespace probable_guide;

bool ProbableGuide::Init(int argc, char** argv)
{
    if(!glfwInit()) {
        return false;
    }
    return true;
}

int ProbableGuide::Run()
{
    return 0;
}


ProbableGuide::ProbableGuide(ProbableGuide::Private)
{
}

ProbableGuide::~ProbableGuide()
{
    glfwTerminate();
}

