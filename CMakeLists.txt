cmake_minimum_required(VERSION 3.22)

project(probable_guide)

add_executable(probable_guide 
    src/main.cpp
    src/probable_guide.cpp
    src/window.cpp
)

set_property(TARGET probable_guide PROPERTY CXX_STANDARD 23)

target_include_directories(probable_guide PRIVATE include)

