#include<iostream>

#include <probable_guide/probable_guide.h>

int main(int argc, char** argv)
{
    auto program = probable_guide::ProbableGuide::Create();

    if(!program->Init(argc, argv)) {
        std::cout << "probable_guide terminated after init()" << std::endl;
        return -1;
    }

    return program->Run();
}
